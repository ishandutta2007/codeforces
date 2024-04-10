#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }

    for (int i = 0; i < n; ++i) {
      cin >> b[i];
      --b[i];
    }

    vector<int> drop(n + 1);

    int last = -1;
    bool ok = true;

    for (int i = n - 1, j = n - 1; i >= 0; ) {
      assert(j >= 0);

      if (b[i] == a[j]) {
        last = b[i];
        --j;
        --i;
        continue;
      }

      if (b[i] == last) {
        drop[b[i]]++;
        --i;
        continue;
      }

      if (drop[a[j]] > 0) {
        drop[a[j]]--;
        --j;
        continue;
      }

      ok = false;
      break;
    }

    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}