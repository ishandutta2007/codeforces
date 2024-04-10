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

int p;


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

char shift(char c)
{
    return --c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ll a00, a01, a10, a11;
    cin>>a00>>a01>>a10>>a11;
    
    ll zeros = 1;
    while (zeros*(zeros-1)/2 < a00) zeros++;
    if (zeros*(zeros-1)/2!=a00) {cout<<"Impossible"; return 0;}
    
    
    ll ones = 1;
    while (ones*(ones-1)/2 < a11) ones++;
    if (ones*(ones-1)/2!=a11) {cout<<"Impossible"; return 0;}
    
    ll total = a01+a10;
    
    if (total==0)
    {
        if (a00>0&&a11>0) {cout<<"Impossible"; return 0;}
        if (a00==0) {for (int i = 0; i<ones; i++) cout<<1; return 0;}
        if (a11==0) {for (int i = 0; i<zeros; i++) cout<<0; return 0;}
    }
    

    if (total!=zeros*ones) {cout<<"Impossible"; return 0;}

    vector<int> after(ones);
    for (int i = 0; i<ones; i++)
    {
        after[i] = min(zeros, a01);
        a01-=after[i];
    }

    vector<int> cnt(zeros+1);
    for (int i = 0; i<ones; i++) cnt[after[i]]++;
    for (int i = 0; i<cnt[0]; i++) cout<<1;
    for (int i = 0; i<zeros; i++)
    {
        cout<<0; for (int j = 0; j<cnt[i+1]; j++) cout<<1;
    }
    



    
}