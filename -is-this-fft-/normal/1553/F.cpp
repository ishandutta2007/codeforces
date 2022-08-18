#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int BLOCK = 550;
const int MAX_N = BLOCK * BLOCK;

// O(1) query, O(sqrt(n)) update
class PrefixSum {
  vector<ll> arr;
  vector<ll> blocks;

public:
  PrefixSum () : arr(MAX_N, 0LL), blocks(BLOCK, 0LL) {
  }

  void add (int pos, ll val) {
    for (int i = pos; i < MAX_N;) {
      if (i % BLOCK == 0) {
        blocks[i / BLOCK] += val;
        i += BLOCK;
      } else {
        arr[i] += val;
        i++;
      }
    }
  }

  ll get (int pos) {
    if (pos < 0) {
      return 0;
    }
    
    return arr[pos] + blocks[pos / BLOCK];
  }

  ll range (int l, int r) {
    if (l > r) return 0;
    return get(r) - get(l - 1);
  }
};

int seen [MAX_N];
ll arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  PrefixSum sum, cnt;
  
  ll ans = 0;
  for (int k = 0; k < n; k++) {
    // sum a_k mod a_i

    // small values of a_i
    for (int i = 1; i < BLOCK; i++) {
      if (seen[i]) {
        ans += arr[k] % i;
      }
    }

    // large values of a_i
    for (int i = 0; i < BLOCK; i++) {
      int lb = max((ll) BLOCK, arr[k] / (i + 1) + 1);
      int ub = i == 0 ? MAX_N - 1 : arr[k] / i;

      ans += arr[k] * cnt.range(lb, ub);
      ans -= (ll) i * sum.range(lb, ub);
    }

    // sum a_i mod a_k
    for (int i = 0; i < MAX_N; i += arr[k]) {
      int lb = i;
      int ub = min((ll) MAX_N - 1, i + arr[k] - 1);

      auto add = sum.range(lb, ub) - cnt.range(lb, ub) * (ll) i;
      ans += add;
    }

    seen[arr[k]] = 1;
    sum.add(arr[k], arr[k]);
    cnt.add(arr[k], 1);

    cout << ans << " ";
  }
  cout << '\n';
}