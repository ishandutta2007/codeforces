#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

int p = 1e9 + 7;


int mul(int a, int b) {
    return (1LL * a%p * b%p) % p;
}

int add(int a, int b) {
    ll s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}

vector<int> Z(string s)
{
int n = s.length();
vector<int> z(n);
int L = 0, R = 0;
for (int i = 1; i < n; i++) {
  if (i > R) {
    L = R = i;
    while (R < n && s[R-L] == s[R]) R++;
    z[i] = R-L; R--;
  } else {
    int k = i-L;
    if (z[k] < R-i+1) z[i] = z[k];
    else {
      L = i;
      while (R < n && s[R-L] == s[R]) R++;
      z[i] = R-L; R--;
    }
  }
}
return z;
}

vector<int> t(4000000);
vector<int> maxx(4000000);

void update(int v, int tl, int tr, int l, int r, int add)
{
    if (l>r) return;
    if (l==tl&&r==tr) {t[v]+=add; maxx[v]+=add;}
    else
    {
        int tm = (tl+tr)/2;
        update(2*v, tl, tm, l, min(tm, r), add);
        update(2*v+1, tm+1, tr, max(l, tm+1), r, add);
        maxx[v] = max(maxx[2*v], maxx[2*v+1]) + t[v];
    }
}

int  get(int v, int tl, int tr, int l, int r)
{
    if (l>r) return 0;
    if (l==tl&&r==tr) return maxx[v];
    else
    {
        int tm = (tl+tr)/2;
        return t[v] + max(get(2*v, tl, tm, l, min(tm, r)), get(2*v+1, tm+1, tr, max(l, tm+1), r));
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    get(a);
    vector<int> pos(n);
    stack<int> my;
    my.push(0);
    pos[0] = -1;
    for (int i = 1; i<n; i++)
    {
        while (!my.empty()&&a[my.top()]<a[i]) my.pop();
        if (my.empty()) pos[i] = -1;
        else pos[i] = my.top();
        my.push(i);
    }
    //print(a);
    //print(pos);
    //cout<<endl;
    for (int i = 0; i<k-1; i++) update(1, 0, n-1, pos[i]+1, i, 1);
    
    /*for (int i = 0; i<n; i++) cout<<get(1, 0, n-1, i, i)<<' ';
    cout<<endl<<endl;*/
    
    
    
    for (int i = k-1; i<n; i++)
    {
        update(1, 0, n-1, pos[i]+1, i, 1);
        cout<<get(1, 0, n-1, i-k+1, i)<<' ';
        /*cout<<pos[i]+1<<' '<<i<<endl;
        for (int i = 0; i<n; i++) cout<<get(1, 0, n-1, i, i)<<' ';
        cout<<endl;*/
    }


}