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
 
vector<int> Z(vector<int> s)
{
int n = s.size();
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

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i = 0; i<=n-11; i++) if (s[i]=='8') {cout<<"YES"<<endl; return;}
    cout<<"NO"<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    vector<int> a = {4 , 8, 15, 16, 23, 42};
    vector<int> res(4);
    for (int i = 0; i<4; i++)
    {
        cout<<"? "<<1<<' '<<i+2<<endl;
        cin>>res[i];
    }
    
    for (auto x1: a)
    for (auto x2: a)
    for (auto x3: a)
    for (auto x4: a)
    for (auto x5: a)
    for (auto x6: a)
    {
        set<int> kek = {x1, x2, x3, x4, x5, x6};
        if (kek.size()<6) continue;
        if (x1*x2==res[0]&&x1*x3==res[1]&&x1*x4==res[2]&&x1*x5==res[3])
        {
            cout<<"! "<<x1<<' '<<x2<<' '<<x3<<' '<<x4<<' '<<x5<<' '<<x6<<endl;
        }
    }
    

}