// resubmission in 32-bit for comparison
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
const int A = 2e5+2;
const int N = 1e5+2;
const int M = 450;
const int K = 100;
int last = 0;
int n;
int a[N];
int is_prime[M];

int last_seen[A];
int prv[N];
vector<pair<int, int>> lpt[4*N];
vector<int> prods[4*N];

const int G = 256; // powers of small primes
vector<int> smallprimes;
bitset<G> vp[N];
bitset<G> spt[4*N];

void make_large_node(int v, int tl, int tr) {
  if (tl == tr) {
    if (a[tl] > 1) {
      lpt[v].push_back({prv[tl], a[tl]});
    }
  }
  else {
    int tm = (tl+tr)/2;
    make_large_node(2*v, tl, tm);
    make_large_node(2*v+1, tm+1, tr);
    int x = lpt[2*v].size();
    int y = lpt[2*v+1].size();
    int i = 0;
    int j = 0;
    while (i < x || j < y) {
      bool leftside = (j == y || (i != x && (lpt[2*v][i] < lpt[2*v+1][j])));
      if (leftside) {
        if (lpt[2*v][i].first >= tl) break;
        lpt[v].push_back(lpt[2*v][i]);
        i++;
      }
      else {
        if (lpt[2*v+1][j].first >= tl) break;
        lpt[v].push_back(lpt[2*v+1][j]);
        j++;
      }
    }
  }

  prods[v].resize(lpt[v].size()+1, 1);
  for (int i = 0; i < lpt[v].size(); i++) {
    prods[v][i+1] = 1LL * prods[v][i] * lpt[v][i].second % MOD;
  }
}

void make_small_node(int v, int tl, int tr) {
  if (tl == tr) {
    spt[v] = vp[tl];
  }
  else {
    int tm = (tl+tr)/2;
    make_small_node(2*v, tl, tm);
    make_small_node(2*v+1, tm+1, tr);
    spt[v] = spt[2*v] | spt[2*v+1];
  }
}

void preprocess() {
  for (int i = 1; i < A; i++) {
    last_seen[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    prv[i] = last_seen[a[i]];
    if (a[i] > 1) last_seen[a[i]] = i;
  }
  make_large_node(1, 0, n-1);
  make_small_node(1, 0, n-1);
}

int lp_query(int v, int tl, int tr, int l, int r) {
  if (tr < l || tl > r) return 1;
  if (r >= tr && l <= tl) {
    int k = lower_bound(lpt[v].begin(), lpt[v].end(), make_pair(l, -1))-lpt[v].begin();
    return prods[v][k];
  }
  int tm = (tl+tr)/2;
  return 1LL * lp_query(2*v, tl, tm, l, r) * lp_query(2*v+1, tm+1, tr, l, r) % MOD;
}

int lp_query(int l, int r) {
  return lp_query(1, 0, n-1, l, r);
}

bitset<G> sp_query(int v, int tl, int tr, int l, int r) {
  if (tr < l || tl > r) return 0;
  if (r >= tr && l <= tl) {
    return spt[v];
  }
  int tm = (tl+tr)/2;
  return sp_query(2*v, tl, tm, l, r) | sp_query(2*v+1, tm+1, tr, l, r);
}

bitset<G> sp_query(int l, int r) {
  return sp_query(1, 0, n-1, l, r);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  assert(M*M > A);
  for (int i = 2; i < M; i++) {
    is_prime[i] = 1;
  }
  for (int i = 2; i < M; i++) {
    if (is_prime[i]) {
      smallprimes.push_back(i);
      for (int j = 2*i; j < M; j += i) {
        is_prime[j] = 0;
      }
    }
  }
  vector<pair<int, int>> spp;
  int k = smallprimes.size();
  for (int p: smallprimes) {
    int u = p;
    while (u < A) {
      spp.push_back({u, p});
      u *= p;
    }
  }
  assert(G >= spp.size());

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = (int)spp.size()-1; j >= 0; j--) {
      if (a[i] % spp[j].first == 0) {
        vp[i][j] = 1;
        a[i] /= spp[j].second;
      }
    }
  }

  preprocess();

  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    int l = (x+last)%n;
    int r = (y+last)%n;
    if (l > r) swap(l, r);
    int ans = lp_query(l, r);
    bitset<G> spq = sp_query(l, r);
    for (int j = 0; j < spp.size(); j++) {
      if (spq[j]) ans = 1LL * ans * spp[j].second % MOD;
    }
    cout << (last = ans) << '\n';
  }
}