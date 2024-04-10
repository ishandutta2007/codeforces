#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

const int N = 1e5 + 5, sqrN = 350;

int n, m, C, q, sC, sN, _sC;
int a[N];

int num;
bitset<N> vis;
bitset<70> mskv[sqrN];
int pri[N], mu[N], rk[N], mp[N];
void Euler(int lim) {
  mu[1] = 1;
  for (int i = 2; i <= lim; i++) {
    if (!vis.test(i)) {
      pri[num++] = i;
      mu[i] = -1;
      mp[i] = i;
      rk[i] = num;
    }
    for (int *p = pri, *_p = pri + num, x; p != _p && (x = *p * i) <= lim; p++) {
      vis.set(x);
      mp[x] = *p;
      if (i % *p) {
        mu[x] = -mu[i];
      } else {
        mu[x] = 0;
        break;
      }
    }
  }
  for (int i = 3; i <= lim; i++) {
    if (!rk[i]) {
      rk[i] = rk[i - 1];
    }
  }
  for (int i = 2; i <= sC; i++) {
    mskv[i] = mskv[i / mp[i]];
    mskv[i].set(rk[mp[i]]);
  }
}

int lgid[N];
int large[N];
bitset<70> msks[N];

typedef class Query {
  public:
    int l, r, lid, id;
    
    Query() {}
    Query(int l, int r, int id) : l(l), r(r), lid((l - 1) / sN), id(id) {}

    bool operator < (Query b) const {
      return (lid ^ b.lid) ? (lid < b.lid) : (r < b.r);
    } 
} Query;

int ans[N];
Query qs[N];

bitset<70> curm, curm2;
int cnta[N >> 3];
int cntv[sqrN];
int cntv2[sqrN];

void upd(int pos) {
  int p;
  if ((p = large[pos]) != 0) {
    if (++cnta[rk[p]] == 1) {
      cntv[lgid[pos]]++;
    }
  }
  curm |= msks[pos];
}
void del(int pos) {
  int p;
  if ((p = large[pos]) != 0) {
    cnta[rk[p]]--;
    cntv[lgid[pos]] = 0;
  }
}
void backup() {
  curm2 = curm;
  for (int i = 1; i <= sC; i++) {
    cntv2[i] = cntv[i];
  }
}
void recover() {
  curm = curm2;
  for (int i = 1; i <= sC; i++) {
    cntv[i] = cntv2[i];
  }
}
void reset() {
  curm.reset();
  fill(cnta, cnta + num + 1, 0);
  fill(cntv, cntv + sC + 1, 0);
}

vector<int> P;
int f[sqrN], g[sqrN];
int S(int pd, int m) {
  int n = C / pd;
  if (m >= (signed) P.size()) {
    return (n > sC) ? (rk[n] - rk[sC] - f[pd]) : 0;
  }
  if (n < P[m]) {
    return 0;
  }
  int rt = ((n >= sC) ? (rk[n] - rk[sC] + (signed) P.size() - f[pd]) : g[n]) - m;
  for (int j = m; j < (signed) P.size() && P[j] * P[j] <= n; j++) {
    int p = P[j], p2 = p * p, npd = pd;
    for (int e = 1; p2 * npd <= C; e++) {
      rt += S(npd *= p, j + 1) + 1;
    }
  }
  return rt;
}

int solve() {
  P.clear();
  fill(g, g + sC + 1, 0);
  for (int *p = pri, *_p = pri + num; p != _p && *p <= sC; p++) {
    if (!curm.test(rk[*p])) {
      P.push_back(*p);
      g[*p] = 1;
    }
  }
  for (int i = 1; i <= sC; i++) {
    g[i] += g[i - 1];
  }
  for (int i = _sC; i; i--) {
    f[i] = cntv[i] + f[i + 1];
  }
/*   cerr << "P: ";
  for (auto x : P) {
    cerr << x << " ";
  }
  cerr << endl; */
  int rt = S(1, 0) + 1;
  return rt;
}

int main() {
  scanf("%d%d%d%d", &n, &m, &C, &q);
  sC = sqrt(max(C, m) + 0.5);
  sN = sqrt(n + 0.5);
  _sC = C / sC;
//  cerr << "sqrC & sqrN:" << sC << " " << sN << endl;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  Euler(max(C, m));
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    while (x > 1) {
      int p = mp[x];
      x /= p;
      if (p > C) {
        break;
      }
      if (p > sC) {
        large[i] = p;
        lgid[i] = C / p;
      } else {
        msks[i].set(rk[p]);
      }
    }
  }
  for (int i = 1, l, r; i <= q; i++) {
    scanf("%d%d", &l, &r);
    qs[i] = Query(l, r, i);
  }
  sort(qs + 1, qs + q + 1);
  Query *pq = qs + 1, *_pq = qs + q + 1;
  for (int lid = 0, _lid = (n - 1) / sN; lid <= _lid; lid++) {
    int D = (lid + 1) * sN, mdzzr = D;
    reset();
    while (pq != _pq && pq->lid == lid) {
      int l = pq->l, r = pq->r;
 //     cerr << "Q:" << l << " " << r << endl;
      if (r < D) {
        for (int i = l; i <= r; i++) {
          upd(i);
        }
        ans[pq->id] = solve();
        for (int i = l; i <= r; i++) {
          del(i);
        }
        curm.reset();
      } else {
        while (mdzzr <= r) {
          upd(mdzzr++);
        }
        backup();
        for (int i = l; i < D; i++) {
          upd(i);
        }
        ans[pq->id] = solve();
        for (int i = l; i < D; i++) {
          del(i);
        }
        recover();
      }
      pq++;
    }
  }
  for (int i = 1; i <= q; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}