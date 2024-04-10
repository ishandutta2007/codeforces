#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>,
  rb_tree_tag, tree_order_statistics_node_update>;

// cur.order_of_key(2)
// the number of elements in the set less than 2
// *cur.find_by_order(1)
// the 1-st smallest number in the set(0-based)

typedef long long ll;

const int MAX_N = 1e5 + 5;

struct Frac {
  ll p, q;
};

bool operator< (Frac a, Frac b) {
  return a.p * b.q > a.q * b.p;
}

bool beats (int x, Frac a) {
  return x * a.q >= a.p;
}

vector<ll> stud [MAX_N];
ll sstud [MAX_N];

int cur [MAX_N]; // does the i-th teacher beat the current, next, previous; prefix sum
int prv [MAX_N];
int nxt [MAX_N];

bool works (int *arr, int l, int r) {
  if (l > r) {
    return true;
  }

  int sum = arr[r];
  if (l != 0) {
    sum -= arr[l - 1];
  }
  return sum == r - l + 1;
}

void solve () {
  int n, m;
  cin >> n >> m;

  vector<int> teach (n);
  for (int i = 0; i < n; i++) {
    cin >> teach[i];
  }
  sort(teach.begin(), teach.end(), greater<int>());

  ordered_set<pair<Frac, int>> grps;
  n = m;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    stud[i] = vector<ll> (k);
    sstud[i] = 0;
    for (int j = 0; j < k; j++) {
      cin >> stud[i][j];
      sstud[i] += stud[i][j];
    }

    Frac f;
    f.p = sstud[i];
    f.q = k;
    grps.insert(make_pair(f, i));
  }

  for (int i = 0; i < n; i++) {
    cur[i] = beats(teach[i], grps.find_by_order(i)->first);
    if (i != n - 1) {
      nxt[i] = beats(teach[i], grps.find_by_order(i + 1)->first);
    }
    if (i != 0) {
      prv[i] = beats(teach[i], grps.find_by_order(i - 1)->first);
    }

    if (i != 0) {
      cur[i] += cur[i - 1];
      nxt[i] += nxt[i - 1];
      prv[i] += prv[i - 1];
    }
  }

  for (int i = 0; i < n; i++) {
    Frac f;
    f.p = sstud[i];
    f.q = stud[i].size();

    int idx = grps.order_of_key(make_pair(f, i));
    for (int j = 0; j < (int) stud[i].size(); j++) {
      Frac g;
      g.p = sstud[i] - stud[i][j];
      g.q = f.q - 1;

      int new_idx = grps.order_of_key(make_pair(g, MAX_N));
      if (new_idx > idx) {
        new_idx--;
      }

      bool ans;
      if (new_idx < idx) {
        ans = works(cur, 0, new_idx - 1)
          && works(prv, new_idx + 1, idx)
          && works(cur, idx + 1, n - 1)
          && beats(teach[new_idx], g);
      } else {
        ans = works(cur, 0, idx - 1)
          && works(nxt, idx, new_idx - 1)
          && works(cur, new_idx + 1, n - 1)
          && beats(teach[new_idx], g);
      }
      cout << ans;
    }
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}