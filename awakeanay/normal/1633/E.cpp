#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <iostream>
#include <bitset>
#include <algorithm>

#define int long long

const int MAXA = 100000004;
const int MAXM = 303;

std::bitset<MAXA> bit[2];
std::pair<std::pair<int, int>, std::pair<int, int> > edges[MAXM];
int par[MAXM];

int root(int x) {
  if(par[x] < 0)
    return x;
  return par[x] = root(par[x]);
}

void merge(int u, int v) {
  u = root(u);
  v = root(v);

  if(u == v)
    return;

  if(par[u] > par[v])
    u ^= v ^= u ^= v;

  par[u] += par[v];
  par[v] = u;
}

int z0, z1;
int n, m;

int abso(int x) {
  if(x < 0)
    return -x;
  return x;
}

void recalc(int x) {
  for(int i = 0; i < n; i++)
    par[i] = -1;

  for(int i = 0; i < m; i++) {
    int w = abso(edges[i].first.second);
    edges[i].first.first = abso(x-w);
    edges[i].first.second = -w;
  }

  std::sort(edges, edges+m);

  z0 = z1 = 0;
  for(int i = 0; i < m; i++) {
    int v = edges[i].second.first;
    int u = edges[i].second.second;

    if(root(u) == root(v))
      continue;

    merge(u, v);
    int w = abso(edges[i].first.second);

    if(x < w) {
      z1--;
      z0 += w;
    }
    else {
      z1++;
      z0 -= w;
    }
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n >> m;

  for(int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--; v--;
    edges[i] = {{w, -w}, {u, v}};
    bit[1].set(w, 1);
  }

  for(int i = 0; i < m; i++) {
    for(int j = i+1; j < m; j++) {
      int u = -edges[i].first.second;
      int v = -edges[j].first.second;
      bit[1].set((u+v+1)/2, 1);
    }
  }

  int last = -1;
  int p, k, a, b, c;
  std::cin >> p >> k >> a >> b >> c;

  for(int i = 0; i < p; i++) {
    std::cin >> last;
    bit[0].flip(last);
  }
  bit[1].set(0, 1);

  for(int i = p; i < k; i++) {
    last = (last*a + b)%c;
    bit[0].flip(last);
  }

  int ans = 0;
  for(int i = 0; i < MAXA; i++) {
    if(bit[1].test(i)) {
      recalc(i);
    }

    if(bit[0].test(i)) {
      //std::cout << i << " " << z1*i + z0 << std::endl;
      ans ^= z1*i + z0;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}