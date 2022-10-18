#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include <queue>
#include <bitset>
#include <numeric>
#include <array>
#include <cstring>
#include <random>
#include <chrono>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename Str>
struct aho_corasic{
    typedef typename Str::value_type Char;
    struct node{
        int par, link = -1, elink = -1;
        Char cpar;
        map<Char, int> next, go;
        bool isleaf = false;
        node(int par = -1, Char pch = '$'): par(par), cpar(pch){ }
    };
    vector<node> state = vector<node>(1);
    void insert(const Str &s){
        int u = 0;
        for(auto &c: s){
            if(!state[u].next.count(c)){
                state[u].next[c] = int(state.size());
                state.emplace_back(u, c);
            }
            u = state[u].next[c];
        }
        state[u].isleaf = true;
    }
    int get_link(int u){
        if(state[u].link == -1){
            if(!u || !state[u].par) state[u].link = 0;
            else state[u].link = go(get_link(state[u].par), state[u].cpar);
        }
        return state[u].link;
    }
    int get_elink(int u){
        if(state[u].elink == -1){
            if(!u || !get_link(u)) state[u].elink = 0;
            else if(state[get_link(u)].isleaf) state[u].elink = get_link(u);
            else state[u].elink = get_elink(get_link(u));
        }
        return state[u].elink;
    }
    int go(int u, Char c){
        if(!state[u].go.count(c)){
            if(state[u].next.count(c)) state[u].go[c] = state[u].next[c];
            else state[u].go[c] = u ? go(get_link(u), c) : u;
        }
        return state[u].go[c];
    }
    int getsz() {
      return (int)state.size();
    }
};
int main() {

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, m, mx;

  cin >> n >> m;

  mx = n - m + 1;

  string a, b;

  cin >> a >> b;

  aho_corasic<string> aho;

  aho.insert(b);

  int csz = aho.getsz();

  vector<vector<int> > dp(csz, vector<int>(mx + 1, 1e9 + 42));

  vector<vector<int> > ndp(csz, vector<int>(mx + 1, 1e9 + 42));

  dp[0][0] = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < csz; j++) {
      for(int k = 0; k <= mx; k++) {
        if(dp[j][k] == 1e9 + 42) continue;
        int cv;
        cv = aho.go(j, '0');
        ndp[cv][k + (aho.state[cv].isleaf)] = min(ndp[cv][k + (aho.state[cv].isleaf)], dp[j][k] + (a[i] != '0'));
        cv = aho.go(j, '1');
        ndp[cv][k + (aho.state[cv].isleaf)] = min(ndp[cv][k + (aho.state[cv].isleaf)], dp[j][k] + (a[i] != '1'));
      }
    }
    for(int j = 0; j < csz; j++)
      for(int k = 0; k <= mx; k++) {
        dp[j][k] = ndp[j][k];
        ndp[j][k] = 1e9 + 42;
      }
  }

  vector<int> ans(mx + 1, 1e9 + 42);

  for(int j = 0; j <= m; j++)
    for(int i = 0; i <= mx; i++)
      ans[i] = min(ans[i], dp[j][i]);

  for(int i = 0; i <= mx; i++) cout << (ans[i] == 1e9 + 42 ? -1 : ans[i]) << ' ';

  return 0;
}
/*

*/