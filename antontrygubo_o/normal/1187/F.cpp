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

    /*
    
    E(  (n-cntequal)^2) = (n-1)^2 + cntequal^2 - 2n*cntequal  
    
    E(cntequal) = (n-1)/(r-l+1);
    
    E(cntequal^2 = ??)

    E(cntequal^2) = (n-1)/(r-l+1) + (n-1)*(n-2)/(r-l+1)^2
    
    */
   
    int n;
    cin>>n;
    
    vector<int> l(n);
    vector<int> r(n);
    get(l);
    get(r);
    vector<int> prob2(n-1);
    for (int i = 0; i<n-1; i++)
    {
        prob2[i] = mul(max(0, min(r[i+1], r[i]) - max(l[i+1], l[i]) + 1), inv(mul(r[i]-l[i]+1, r[i+1]-l[i+1]+1)));
    }
    vector<int> prob3(max(n-2, 0));
    for (int i = 0; i<n-2; i++)
    {
        prob3[i] = max(0, max(0, min(min(r[i], r[i+1]), r[i+2]) - max(max(l[i], l[i+1]), l[i+2]) + 1)  );
        prob3[i] = mul(prob3[i], inv(r[i]-l[i]+1));
        prob3[i] = mul(prob3[i], inv(r[i+1]-l[i+1]+1));
        prob3[i] = mul(prob3[i], inv(r[i+2]-l[i+2]+1));
    }
    
    
    int answer = mul(n, n);
    for (int i = 0; i<n-1; i++) answer = sub(answer, mul(2*n, prob2[i]));
    
    int sq = 0;
    int total = 0;
    for (int i = 0; i<n-1; i++) total = add(total, prob2[i]);
    answer = add(answer, total);
    sq = mul(total, total);
    for (int i = 0; i<n-1; i++) sq = sub(sq, mul(prob2[i], prob2[i]));
    for (int i = 0; i<n-2; i++) sq = sub(sq, mul(2, mul(prob2[i], prob2[i+1])));
    for (int i = 0; i<n-2; i++) sq = add(sq, mul(2, prob3[i]));
    answer = add(answer, sq);
    cout<<answer;
    
}