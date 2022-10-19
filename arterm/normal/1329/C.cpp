#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 1100100;
const int inf = 1e9;

int n, m;
int a[M];
int c[M];
ll sum;

void read() {
  cin >> n >> m;
  sum = 0;
  for (int i = 1; i < (1 << n); ++i) {
    cin >> a[i];
    sum += a[i];
  }
}

int last(const vector<int> &v) {
  if (v.empty())
    return -inf;
  else
    return v.back();
}

vector<int> solve(int v) {
  if (v >= (1 << m))
    c[v]++;

  vector<int> ans = {a[v]};
  
  if (2 * v < (1 << n)) {

    int l = 2 * v , r = 2 * v + 1;
    auto L = solve(l);
    auto R = solve(r);

    bool stop = false;
    while (!L.empty() || !R.empty()) {
      if (last(L) > last(R)) {
        if (c[l] == 0) stop = true;
        if (!stop) {
          c[l]--;
          c[v]++;
          sum += L.back();
        }
        ans.push_back(L.back());
        L.pop_back();
      } else {
        if (c[r] == 0) stop = true;
        if (!stop) {
          c[r]--;
          c[v]++;
          sum += R.back();
        }
        ans.push_back(R.back());
        R.pop_back();
      }
    }

  }

  assert((int) ans.size() >= c[v]);
  for (int i = 0; i < c[v]; ++i)
    sum -= ans[i];
  reverse(all(ans));
  return ans;
}

void kill() {
  fill(c, c + (1 << n), 0);
  solve(1);

  cout << sum << "\n";
  for (int i = 1; i < (1 << n); ++i)
    for (int j = 0; j < c[i]; ++j)
      cout << i << " ";
  cout << "\n";
}


int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    read();
    kill();
  }

}