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
int main() {

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, m;

  cin >> n >> m;

  vector<pair<string, int> > s(n);

  for(int i = 0; i < n; i++) {
    cin >> s[i].fi;
    s[i].se = i;
  }

  sort(all(s), [&](pair<string, int> a, pair<string, int> b) {
    for(int i = 0; i < a.fi.size(); i++) {
      if(a.fi[i] != b.fi[i]) {
        if(i % 2 == 1) return (a.fi[i] > b.fi[i]);
        else return (a.fi[i] < b.fi[i]);
      }
    }
  });

  for(auto& x : s) cout << x.se + 1 << ' ';

  return 0;
}
/*

*/