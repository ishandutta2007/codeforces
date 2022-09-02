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



const int INF = 1000000000; // weight INF means there is no edge

struct Edge {
    int w = INF, to = -1;
};

vector<pair<int, int>> lol;

void prim(vector<vector<int>> adj, int n) {
    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        if (min_e[v].w == INF) {
            cout << "No MST!" << endl;
            exit(0);
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1)
            lol.push_back(mp(v, min_e[v].to)); 

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }
    cout<<total_weight<<endl;

}


int d(vector<string> &a, vector<string> &b){
    int n = a.size();
    int m = a[0].size();
    int cnt = 0;
    for (int i = 0; i<n; i++)
    for (int j = 0; j<m; j++) if (a[i][j]!=b[i][j]) cnt++;
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m, k, w;
    cin>>n>>m>>k>>w;
    vector<vector<string>> a(k, vector<string>(n));
    for (int i = 0; i<k; i++)
    for (int j = 0; j<n; j++) cin>>a[i][j];
    vector<vector<int>> dis(k+1, vector<int>(k+1));
    for (int i = 0; i<k; i++)
    for (int j = i+1; j<k; j++)
    {
        int ans = d(a[i], a[j]);
        dis[i+1][j+1] = w*ans;
        dis[j+1][i+1] = w*ans;
    }
    for (int i = 0; i<k; i++) {dis[0][i+1] = n*m; dis[i+1][0] = n*m;}
    prim(dis, k+1);
    for (auto it: lol) cout<<it.first<<' '<<it.second<<endl;
    
    

}