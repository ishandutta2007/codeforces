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

const int p =  1e9 + 7;


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

bool ask(int x, int y)
{
    cout<<1<<' '<<x<<' '<<y<<endl;
    string s;
    cin>>s;
    if (s=="TAK") return 1;
    return 0;
}


int solve(int l, int r)
{
    while (r-l>=1)
    {
        int mid = (l+r)/2;
        if (ask(mid, mid+1)) r = mid;
        else l = mid+1;
    }
    return l;
}

int checksolve(int l, int r, int t)
{
    int s = solve(l, r);
    if (ask(s, t)) return s;
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k;
    cin>>n>>k;
    int r = solve(1, n);
    
    int r1 = r;
    if (r1<n&&ask(r1+1, r1))
    {
        int s = solve(r1+1, n);
        cout<<2<<' '<<r<<' '<<s<<endl;
        return 0;
    }
    r1 = r+1;
    while (r1<n)
    {
        if (ask(r1+1, r1))
        {
            int s = solve(r1+1, n);
            cout<<2<<' '<<r<<' '<<s<<endl;
            return 0;
        }
        r1 = 2*r1-r;
    }
    
    r1 = r;
    if (r1>1&&ask(r1-1, r1))
    {
        int s = solve(1, r1-1);
        cout<<2<<' '<<r<<' '<<s<<endl;
        return 0;
    }
    r1 = r-1;
    while (r1>1)
    {
        if (ask(r1-1, r1))
        {
            int s = solve(1, r1-1);
            cout<<2<<' '<<r<<' '<<s<<endl;
            return 0;
        }
        r1 = 2*r1-r;
    }
    
}