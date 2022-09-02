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

int n;
vector<vector<int>> G;

vector<ll> subtree;
vector<ll> answer;
vector<bool> visited;

vector<ll> calc;

void dfs(int s)
{
    visited[s] = true;
    subtree[s] = 1;
    answer[s] = 0;
    for (auto it: G[s]) if (!visited[it]) {dfs(it); subtree[s]+=subtree[it]; answer[s]+=(subtree[it]+answer[it]);}
}

void dfs1(int s)
{
    visited[s] = true;
    for (auto it: G[s]) if (!visited[it]) {calc[it] = calc[s] + (n-2*subtree[it]); dfs1(it);} 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n;
    calc.resize(n);
    visited.resize(n);
    subtree.resize(n);
    G.resize(n);
    answer.resize(n);
    int a, b;
    for (int i = 0; i<n-1; i++)
    {
        cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0);
    calc[0] = answer[0];
    for (int i = 0; i<n; i++) visited[i] = false;
    dfs1(0);
    ll maxx = 0;
    for (int i = 0; i<n; i++) maxx = max(maxx, calc[i]);
    cout<<maxx+n;
    
    
   
   
    
}