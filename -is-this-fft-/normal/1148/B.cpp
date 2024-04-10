#include <iostream>
#include <set>

using namespace std;

const int maxn = 200005;

int A [maxn];
int B [maxn];

int main () {
  int ac, bc, ta, tb, canc_c;
  cin >> ac >> bc >> ta >> tb >> canc_c;

  for (int i = 0; i < ac; i++) {
    cin >> A[i];
  }

  set<pair<int, int>> b_times;
  for (int i = 0; i < bc; i++) {
    cin >> B[i];
    b_times.insert(make_pair(B[i], i));
  }

  int ans = 0;
  for (int i = 0; i <= canc_c; i++) {
    if (i >= ac) {
      cout << -1 << endl;
      return 0;
    }

    int arrives_b = A[i] + ta;
    if (b_times.lower_bound(make_pair(arrives_b, 0)) == b_times.end()) {
      cout << -1 << endl;
      return 0;
    }
    int b_idx = b_times.lower_bound(make_pair(arrives_b, 0))->second;
    b_idx += canc_c - i;
    if (b_idx >= bc) {
      cout << -1 << endl;
      return 0;
    }

    ans = max(ans, B[b_idx] + tb);
  }

  cout << ans << endl;
}