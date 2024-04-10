#include <bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick {
  public:
    vector<T> arr;
    fenwick (int n) {
      arr.resize(n+3);
    }
    void add (int index, T val) {
      for (; index < arr.size(); index += (index & (-index))) {
        arr[index] += val;
      }
    }
    T query(int index) {
      T sum = 0;
      for (; index > 0; index -= (index & (-index))) {
        sum += arr[index];
      }
      return sum;
    }
};

const int N = 3e5+5;
const int K = 30;
const int D = (1LL<<K)-1;
int a[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  map<int, long long> hashes;
  auto get_hash = [&] (int x) {
    if (!hashes.count(x)) hashes[x] = rng()&D;
    return hashes[x];
  };

  int n, q;
  cin >> n >> q;
  vector<fenwick<int>> fen(60, fenwick<int>(n));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    long long z = get_hash(a[i]);
    for (int j = 0; j < K; j++) {
      if ((z>>j)&1) fen[j].add(i, 1);
    }
  }

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, x;
      cin >> i >> x;
      long long z = get_hash(a[i]);
      for (int j = 0; j < K; j++) {
        if ((z>>j)&1) fen[j].add(i, -1);
      }
      a[i] = x;
      z = get_hash(a[i]);
      for (int j = 0; j < K; j++) {
        if ((z>>j)&1) fen[j].add(i, 1);
      }
    }
    else {
      int l, r, k;
      cin >> l >> r >> k;
      bool ok = 1;
      for (int j = 0; j < K; j++) {
        if ((fen[j].query(r)-fen[j].query(l-1))%k != 0) {
          ok = 0;
          break;
        }
      }
      cout << (ok ? "YES" : "NO") << '\n';
    }
  }

}