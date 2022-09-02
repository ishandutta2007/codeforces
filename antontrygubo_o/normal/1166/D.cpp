#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
#define mp make_pair
 
typedef long double DOUBLE;
typedef complex<DOUBLE> COMPLEX;
typedef vector<DOUBLE> VD;
typedef vector<COMPLEX> VC;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

 
void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}
 
void get(vector<auto> &a)
{
    for (int i = 0; i<(int)a.size(); i++) cin>>a[i];
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
    ll a, b, m;
    cin>>a>>b>>m;
    if (a==b)
    {
        cout<<1<<' '<<a<<endl;
        return;
    }
    ll a1 = (a+1);
    ll a2 = (a+m);
    if (b<=a+m)
    {
        cout<<2<<' '<<a<<' '<<b<<endl;
        return;
    }
    int k = 1;
    while (a2<b)
    {
        k++;
        a1*=2;
        a2*=2;
    }
    if (a1>b) {cout<<-1<<endl; return;}
    //cout<<k<<endl;
    vector<ll> answer;
    vector<ll> r;
    b-=a*((ll)1<<(k-1));
    //cout<<b<<endl;
    for (int i = k-2; i>=0; i--)
    {
        ll kek = (ll)1<<i;
        ll b1 = b-kek;
        ll r1 = min(m, b1/kek);
        b-=r1*kek;
        r.push_back(r1);
    }
    r.push_back(b);
    answer.push_back(a);
    //print(r);
    answer.push_back(a+r[0]);
    for (int i = 1; i<k; i++)
    {
        answer.push_back(2*answer[i]+r[i]-r[i-1]);
    }
    cout<<k+1<<' ';
    print(answer);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int q;
    cin>>q;
    for (int i = 0; i<q; i++) solve();

}