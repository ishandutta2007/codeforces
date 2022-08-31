#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

class Fenwick {
  vector<ll> tree;
public:
  Fenwick (int _n) : tree(_n, 0LL) {

  }

  ll get (int pos) {
    ll ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }

  void add (int pos, ll val) {
    for (int i = pos; i < (int) tree.size(); i += i & -i) {
      tree[i] += val;
    }
  }
};

const int MAX_N = 2e5 + 5;

pair<int, int> arr [MAX_N]; // <speed, pos>

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  map<int, int> compr;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].second;
    compr[arr[i].second] = 0;
  }

  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
  }

  int cur = 0;
  for (auto it = compr.begin(); it != compr.end(); it++) {
    cur++;
    it->second = cur;
  }

  map<int, int> orig;
  for (int i = 0; i < n; i++) {
    orig[compr[arr[i].second]] = arr[i].second;
    arr[i].second = compr[arr[i].second];
  }

  sort(arr, arr + n);

  Fenwick cnt (n + 5);
  Fenwick fenwick (n + 5);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += cnt.get(arr[i].second) * orig[arr[i].second] - fenwick.get(arr[i].second);
    fenwick.add(arr[i].second, orig[arr[i].second]);
    cnt.add(arr[i].second, 1);
  }

  cout << ans << endl;
}