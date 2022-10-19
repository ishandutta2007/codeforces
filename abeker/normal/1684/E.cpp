#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct Node {
  int sum, cnt;
  Node() : sum(0), cnt(0) {}
  Node(int sum, int cnt) : sum(sum), cnt(cnt) {}
};

class Tournament {
  int offset;
  vector <Node> tour;
public:
  Tournament(int n) {
    for (offset = 1; offset < n; offset *= 2);
    tour.resize(2 * offset);
  }
  Node merge(const Node &lhs, const Node &rhs) {
    return Node(lhs.sum + rhs.sum, lhs.cnt + rhs.cnt);
  }
  void update(int x, int val) {
    x += offset;
    tour[x].sum += val;
    tour[x].cnt++;
    for (x /= 2; x; x /= 2)
      tour[x] = merge(tour[2 * x], tour[2 * x + 1]);
  }
  void update(int x) {
    update(x, x);
  }
  int get(int x, int k) const {
    if (!k)
      return 0;
    if (x >= offset)
      return k / (x - offset);
    if (tour[2 * x].sum < k)
      return tour[2 * x].cnt + get(2 * x + 1, k - tour[2 * x].sum);
    return get(2 * x, k);
  }
};

int N, K;
int a[MAXN];

void load() {
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

int solve() {
  unordered_map <int, int> freq;
  for (int i = 0; i < N; i++)
    freq[a[i]]++;
  int curr = 0;
  Tournament solver(N + 1);
  for (auto it : freq)
    if (it.first > N) {
      solver.update(it.second);
      curr++;
    }
  vector <int> missing(N + 1);
  for (int i = 1; i <= N; i++)
    missing[i] = missing[i - 1] + !freq[i - 1];
  int sol = N;
  for (int mex = N; mex >= 0; mex--) {
    int tmp = freq[mex];
    if (tmp <= K && missing[mex] <= K)
       sol = min(sol, curr - solver.get(1, K - tmp));
    if (tmp) {
      solver.update(tmp);
      curr++;
    }
  }
  return sol;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%d\n", solve());
  }
  return 0;
}