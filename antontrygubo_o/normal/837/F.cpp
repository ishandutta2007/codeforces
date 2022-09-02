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

const int p = 1e9 + 7;
 
 
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
 
mt19937 rnd(time(0));

ll MAXX = 1e18;
//max number is equal to sum of a[i]*C(t-1, n-i-1+t-1);

ll prod(ll cur, ll up, ll down)
{
    if (cur==MAXX) return MAXX;
    ll t = __gcd(cur, down);
    cur/=t;
    down/=t;
    up/=down;
    if (cur>MAXX/up) return MAXX;
    else return min(cur*up, MAXX);
}

ll C(ll k, ll t)
{
    ll ans = 1;
    for (int i = k-1; i>=0; i--)
    {
        ans = prod(ans, t-i, k-i);
    }
    return ans;
}

vector<ll> a;

ll n, k;

bool check(ll t)
{
    ll answer = 0;
    for (int i = n-1; i>=0; i--) if (a[i]>0)
    {
        if (C(n-i-1, n-i-1 + t-1)>k/a[i]) return true;
        answer+=C(n-i-1, n-i-1 + t-1)*a[i];
        if (answer>=k) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);


    cin>>n>>k;
    a.resize(n);
    get(a);
    for (int i = 0; i<n; i++) if (a[i]>=k) {cout<<0; return 0;}
    vector<ll> a1(n);
    for (int i = 0; i<n; i++) a1[i] = a[i];
    for (int i = 1; i<=600; i++)
    {
        vector<ll> b(n);
        b[0] = a1[0];
        for (int j = 1; j<n; j++) {b[j] = b[j-1] + a1[j];  if (b[j]>=k) {cout<<i; return 0;}}
        a1 = b;
    }
    ll l = 1;
    ll r = 1e18;
    if (check(1)) {cout<<1; return 0;}
    while (r>l+1)
    {
        ll mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout<<r;
    
}