#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int a[N];
int ans[N];
int freqs[N]; // frequency of numbers
int freqcount[N]; // count of numbers with frequency at least k
int p[N]; // numbers in decreasing order of frequency
int q[N]; // inverse of p
vector<int> children[N];
vector<tuple<int, int, int>> queries[N];
int n;

void swap_pos(int a, int b) {
  // swap numbers in p at positions a and b
  swap(p[a], p[b]);
  q[p[a]] = a;
  q[p[b]] = b;
}

void insert(int m) {
  int pos = q[m];
  int newpos = freqcount[freqs[m]+1]+1;
  swap_pos(pos, newpos);
  freqs[m]++;
  freqcount[freqs[m]]++;
}

void remove(int m) {
  int pos = q[m];
  int newpos = freqcount[freqs[m]];
  freqcount[freqs[m]]--;
  swap_pos(pos, newpos);
  freqs[m]--;
}

int query(int l, int k) {
  int a = freqcount[l];
  if (a < k) return -1;
  return p[a-k+1];
}

void dfs(int v) {
  insert(a[v]);
  for (tuple<int, int, int> q: queries[v]) {
    int i, l, k;
    tie(i, l, k) = q;
    ans[i] = query(l, k);
  }
  for (int u: children[v]) {
    dfs(u);
  }
  remove(a[v]);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int Q;
    cin >> n >> Q;

    iota(p+1, p+n+1, 1);
    iota(q+1, q+n+1, 1);
    freqcount[0] = n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    for (int i = 1; i <= n-1; i++) {
      int par;
      cin >> par;
      children[par].push_back(i+1);
    }

    for (int i = 0; i < Q; i++) {
      int v, l, k;
      cin >> v >> l >> k;
      queries[v].push_back({i, l, k});
    }

    dfs(1);
    for (int i = 0; i < Q; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= n; i++) {
      children[i].clear();
      queries[i].clear();
    }
  }
}