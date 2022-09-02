#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

typedef long double DOUBLE;
typedef complex<DOUBLE> COMPLEX;
typedef vector<DOUBLE> VD;
typedef vector<COMPLEX> VC;

void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

const int p = 998244353;


int mul(int a, int b) {
    return (1LL * a%p * b%p) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

int sub(int a, int b) {
    int s = (a-b);
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
    int n;
    cin>>n;
    vector<int> a(n);
    get(a);
    int cnt = 0;
    for (int i = 0; i<n-1; i++)
    {
        if (a[i]==a[i+1]) {cout<<"Infinite"; return 0;}
        if (a[i]*a[i+1]==6) {cout<<"Infinite"; return 0;}
        if (a[i]*a[i+1]==2) cnt+=3;
        else cnt+=4;
    }
    cout<<"Finite"<<endl;
    for (int i = 0; i<n-2; i++) if (a[i]==3&&a[i+1]==1&&a[i+2]==2) cnt--;
    cout<<cnt;
    
}