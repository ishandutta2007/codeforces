#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> w(n), h(n), h_sorted(n);
  int sum_w = 0;
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> h[i];
    h_sorted[i] = h[i];
    sum_w += w[i];
  }
  sort(h_sorted.rbegin(), h_sorted.rend());
  for (int i = 0; i < n; ++i) {
    ll W = sum_w - w[i];
    ll H = h[i] == h_sorted[0] ? h_sorted[1] : h_sorted[0];
    cout << W * H << ' ';
  }
  return 0;
}