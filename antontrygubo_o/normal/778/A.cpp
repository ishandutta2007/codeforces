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

bool check(string s, string p)
{
    int S = s.length();
    int P = p.length();
    
    int idx = 0;
    for (int i = 0; i<S&&idx<P; i++) if (s[i]==p[idx]) idx++;
    return (idx==P);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    
    string s, p;
    cin>>s>>p;
    int n = s.length();
    vector<int> a(n);
    get(a);
    for (int i = 0; i<n; i++) a[i]--;
    vector<int> b(n);
    for (int i = 0; i<n; i++) b[a[i]] = i;
    
    int l = 0; int r = n;
    while (r-l>1)
    {
        int mid = (l+r)/2;
        string s1;
        for (int i = 0; i<s.length(); i++) if (b[i]>=mid) s1+=s[i];
        if (check(s1, p)) l = mid;
        else r = mid;
    }
    cout<<l;

}