#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;

vector<int> h[M];
int n, m;

int norm(int x) {
  x %= n;
  if (x < 0)
    x += n;
  return x;
}

void read() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    h[a].push_back(norm(b - a));
    h[b].push_back(norm(a - b));
  }

  for (int i = 0; i < n; ++i) {
    sort(all(h[i]));
  }
}

bool cmp(const vector<int> &A, const vector<int> &B) {
  if (A.size() != B.size())
    return false;
  for (int i = 0; i < (int) A.size(); ++i)
    if (A[i] != B[i])
      return false;
  return true;
}

bool test(int k) {
  assert(n % k == 0);

  for (int i = 0; i < n; i += k)
    for (int j = 0; j < k; ++j)
      if (!cmp(h[j], h[i + j]))
        return false;

  return true;
}

void kill() {
  set<int> ps;
  int cur = n;
  for (int i = 2; i <= cur; ++i)
    while (cur % i == 0) {
      ps.insert(i);
      cur /= i;
    }

  for (int p : ps)
    if (test(n / p)) {
      cout << "Yes\n";
      return;
    }
  cout << "No\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}