#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

ll p = 1LL<<42;


ll mul(ll a, ll b) {
    return (1LL * a%p * b%p) % p;
}

ll add(ll a, ll b) {
    ll s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

ll po(ll a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    ll t = po(a, deg/2);
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

int solve(int n)
{
    if (n<=9) return 9;
    if (n%10!=9) return solve(n+1)+1;
    n+=1;
    while (n%10==0) n/=10;
    return solve(n)+1;
}

int dig(char c)
{
    return c-'0';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> f(10);
    for (int i = 1; i<=9; i++) cin>>f[i];
    bool flag = false;
    bool used = false;
    for (int i = 0; i<n; i++)
    {
        if (used) cout<<s[i];
        else if (flag==false)
        {
            if (f[dig(s[i])]>dig(s[i]))
            {
                cout<<f[dig(s[i])]; flag = true;
            }
            else cout<<s[i];
        }
        else
        {
            if (f[dig(s[i])]>=dig(s[i])) cout<<f[dig(s[i])];
            else {cout<<s[i]; flag = false; used = true;}
        }
    }


    
}