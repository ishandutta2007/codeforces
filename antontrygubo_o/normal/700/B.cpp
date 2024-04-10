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

ll total = 0;
int n, k;
vector<vector<int>> G;
vector<int> visited;
vector<bool> is;

int dfs(int s)
{
    visited[s] = true;
    ll cnt = 0;
    for (auto it: G[s]) if (!visited[it]) cnt+=dfs(it);
    if (is[s]) cnt++;
    if (s!=0) total+=min(cnt, 2*k-cnt);
    //cout<<s<<": "<<cnt<<endl;
    return cnt;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    cin>>n>>k;
    G.resize(n);
    visited.resize(n);
    is.resize(n);
    for (int i = 0; i<2*k; i++)
    {
        int c;
        cin>>c;
        c--;
        is[c] = 1;
    }
    int x, y;
    for (int i = 0; i<n-1; i++)
    {
        cin>>x>>y;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(0);
    cout<<total;
    
    

}