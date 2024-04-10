#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
 
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
 /*
const int p = 1e9;
 
 
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
 */
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
 
int minn[4000000];
int pl[4000000];

void add(int v, int tl, int tr, int l, int r, int val)
{
    if (l==tl&&r==tr) {pl[v]+=val; return;}
    if (r<l) return;
    int mid = (tl+tr)/2;
    add(2*v, tl, mid, l, min(r, mid), val);
    add(2*v+1, mid+1, tr, max(l, mid+1), r, val);
    minn[v] = min(minn[2*v]+pl[2*v], minn[2*v+1]+pl[2*v+1]);
}

int get(int v, int tl, int tr, int idx)
{
    if (tl==tr) return pl[v];
    int mid = (tl+tr)/2;
    if (idx<=mid) return pl[v]+get(2*v, tl, mid, idx);
    else return pl[v]+get(2*v+1, mid+1, tr, idx);
}

int find_first_less_than_x(int v, int tl, int tr, int l, int r, int x)
{
    
    if (r<l) return -1;
    if (minn[v]+pl[v]>=x) return -1;
    if (l==r) return r;
    int mid = (tl+tr)/2;
    int ans = find_first_less_than_x(2*v+1, mid+1, tr, max(l, mid+1), r, x-pl[v]);
    if (ans!=-1) return ans;
    else return find_first_less_than_x(2*v, tl, mid, l, min(r, mid), x-pl[v]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n, m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> b(m+1);
    
    for (int i = 1; i<=n; i++)
    {
        cin>>a[i];
        add(1, 1, 1000000, 1, a[i], -1);
    }

    
    for (int i = 1; i<=m; i++)
    {
        cin>>b[i];
        add(1, 1, 1000000, 1, b[i], 1);
    }
    //get returns difference of a (cnt of dishes) and b(cnt of guys)
    int q; cin>>q;
    for (int i = 0; i<q; i++)
    {
        int op, idx, x;
        cin>>op>>idx>>x;
        if (op==1)
        {
            add(1, 1, 1000000, 1, a[idx], 1);
            a[idx] = x;
            add(1, 1, 1000000, 1, a[idx], -1);
        }
        if (op==2)
        {
            add(1, 1, 1000000, 1, b[idx], -1);
            b[idx] = x;
            add(1, 1, 1000000, 1, b[idx], 1);
        }
        cout<<find_first_less_than_x(1, 1, 1000000, 1, 1000000, 0)<<endl;
    }

    /*for (int i = 1; i<=200; i++)
    {
        cout<<i<<": "<<get(1, 1, 1000000, i)<<endl;
    }
    cout<<endl;*/
}