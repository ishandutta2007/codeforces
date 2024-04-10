#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
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
 
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll t;
 
  cin >> t;
 
  while(t--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> pos, neg;
    for(ll i = 0; i < n; i++) {
      ll x; cin >> x;
      if(x > 0) pos.pb(x);
      else if(x < 0) neg.pb(-x);
    }
    sort(rall(pos));
    sort(rall(neg));
    ll ans = 0, mx = 0;
    for(ll i = 0; i < pos.size(); i += k) ans += 2 * pos[i];
    for(ll i = 0; i < neg.size(); i += k) ans += 2 * neg[i];
    pos.pb(0); neg.pb(0);
    ans -= max(pos[0], neg[0]);
    cout << ans << '\n';
  }
 
  return 0;
}
/*
 
*/