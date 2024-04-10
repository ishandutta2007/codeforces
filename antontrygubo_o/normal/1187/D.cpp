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

vector<int> t;

void setter(int v, int tl, int tr, int idx, int val)
{
    if (tl==tr) {t[v] = val; return;}
    int mid = (tl+tr)/2;
    if (idx<=mid) setter(2*v, tl, mid, idx, val);
    else setter(2*v+1, mid+1, tr, idx, val);
    t[v] = min(t[2*v], t[2*v+1]);
}

int MAXX = 1000000000;

int findmin(int v, int tl, int tr, int l, int r)
{
    if (l>r) return MAXX;
    if (tl==l&&tr==r) return t[v];
    int mid = (tl+tr)/2;
    return min( findmin(2*v, tl, mid, l, min(r, mid)), findmin(2*v+1, mid+1, tr, max(l, mid+1), r) );
}




void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    get(a);
    get(b);
    int N = 4*n;



    map<int, set<int>> kek;
    for (int i = 0; i<n; i++) kek[a[i]].insert(i);
    set<int> guys;
    for (int i = 0; i<n; i++) guys.insert(a[i]);
    
    //for (auto it: guys) {cout<<it<<": "; print(kek[it]);}
    
    t = vector<int>(N, MAXX);
    
    for (int i = 0; i<n; i++) setter(1, 0, n-1, i, a[i]);
    for (int i = 0; i<n; i++)
    {
        if (guys.find(b[i])==guys.end()) {cout<<"NO"<<endl; return;}
        if (kek[b[i]].size()==0) {cout<<"NO"<<endl; return;}
        int to = *kek[b[i]].begin();
        
        if (findmin(1, 0, n-1, 0, to)!=b[i]) {cout<<"NO"<<endl; return;}
        setter(1, 0, n-1, to, MAXX);
        kek[b[i]].erase(to);
    }
    cout<<"YES"<<endl;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int q;
    cin>>q;
    for (int i = 0; i<q; i++) solve();
    
}