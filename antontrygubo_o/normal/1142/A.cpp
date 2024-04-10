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

const int p = 1e9 + 7;


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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, k;
    cin>>n>>k;
    n = n*k;
    ll a, b;
    cin>>a>>b;
    ll mingcd =  n;
    ll maxgcd = 1;
    for (ll c = 0; c<=(n/k); c++)
    {
        ll x1 = c*k + a + b;
        ll x2 = c*k + a - b;
        ll x3 = c*k - a - b;
        ll x4 = c*k - a + b;
        if (x1>0&&x1<=n) mingcd = min(mingcd, __gcd(x1, n));
        if (x2>0&&x2<=n) mingcd = min(mingcd, __gcd(x2, n));
        if (x3>0&&x3<=n) mingcd = min(mingcd, __gcd(x3, n));
        if (x4>0&&x4<=n) mingcd = min(mingcd, __gcd(x4, n));
        if (x1>0&&x1<=n) maxgcd = max(maxgcd, __gcd(x1, n));
        if (x2>0&&x2<=n) maxgcd = max(maxgcd, __gcd(x2, n));
        if (x3>0&&x3<=n) maxgcd = max(maxgcd, __gcd(x3, n));
        if (x4>0&&x4<=n) maxgcd = max(maxgcd, __gcd(x4, n));
    }

    
    cout<<n/maxgcd<<' '<<n/mingcd;


}