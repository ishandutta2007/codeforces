#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e3 + 5;

class Node {
  int cnt;
  map <int, Node*> children;
public:
  Node() {
    cnt = 0;
  }
  int getCnt() const {
    return cnt;
  }
  void addWord(int const* word, int c) {
    if (*word == -1) {
      cnt += c;
      return;
    }
    Node*& nxt = children[*word];
    if (nxt == NULL)
      nxt = new Node();
    nxt -> addWord(word + 1, c);
  }
  int precompute() {
    for (auto it : children) 
      cnt += it.second -> precompute();
    return cnt; 
  }
  ll dfs(int sum, ll sofar, const int &n) const {
    int sizes = 0;
    ll pref = 0, res = (ll)(n - 2 * cnt) * sum - 2 * sofar;
    for (auto it : children) {
      int curr = it.second -> getCnt();
      sizes += curr;
      res = min(res, it.second -> dfs(sum + it.first, sofar + pref + (ll)(cnt - sizes) * it.first + (ll)(cnt - curr) * sum, n));
      pref += (ll)curr * it.first;
    }
    return res;
  }
};

int N;
int occ[MAXN];
int least[MAXN];
int idx[MAXN];
int ex[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int k;
    scanf("%d", &k);
    occ[max(k, 1)]++;
  }
}

ll solve() {
  vector <int> primes;
  for (int i = 2; i < MAXN; i++)
    if (!least[i]) {
      idx[i] = primes.size();
      primes.push_back(i);
      for (int j = i; j < MAXN; j += i)
        if (!least[j])
          least[j] = i;
    }
  ll tot = 0;
  int sz = primes.size();
  Node* root = new Node();
  ex[sz] = -1;
  for (int i = 1; i < MAXN; i++) {
    for (int x = i; x > 1; x /= least[x]) 
      ex[sz - 1 - idx[least[x]]]++;
    tot += (ll)occ[i] * accumulate(ex, ex + sz, 0);
    root -> addWord(ex, occ[i]);
  }
  root -> precompute();
  return (root -> dfs(0, 0, N)) + tot;
}

int main() {
  load();
  printf("%lld\n", solve());
  return 0;
}