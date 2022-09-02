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

vector<int> parent(10000);
vector<int> sz(10000);

void make_set (int v) {
	parent[v] = v;
	sz[v] = 1;
}
 
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (sz[a] < sz[b])
			swap (a, b);
		parent[b] = a;
		sz[a]+=sz[b];
	}
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    for (int i = 0; i<10000; i++) make_set(i);

    int n, m, k;
    cin>>n>>m>>k;
    int a, b;
    vector<int> cap(k);
    for (int i = 0; i<k; i++) cin>>cap[i];
    for (int i = 0; i<m; i++) 
    {
        cin>>a>>b;
        union_sets(a, b);
    }
    vector<int> ans(k);
    for (int i = 0; i<k; i++) ans[i] = sz[find_set(cap[i])];
    sort(ans.begin(), ans.end());
    int summ = n;
    for (int i = 0; i<k; i++) summ-=ans[i];
    ans[k-1]+=summ;
    int total = 0;
    for (int i = 0; i<k; i++) total+=ans[i]*(ans[i]-1)/2;
    cout<<total - m;
    
}