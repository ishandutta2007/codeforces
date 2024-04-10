#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MOD = 1009;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int MAX = 1 << 19;

typedef complex<double> comp;

int n;
comp omega[MAX];
comp a1[MAX], a2[MAX];
comp z1[MAX], z2[MAX];

void fft(comp *a, comp *z, int m = n) {
  if (m == 1) {
    z[0] = a[0];
  } else {
    int s = n/m;
    m /= 2;

    fft(a, z, m);
    fft(a+s, z+m, m);

    REP(i, m) {
      comp c = omega[s*i] * z[m+i];
      z[m+i] = z[i] - c;
      z[i] += c;
    }
  }
}

void mult(vector <int> a, vector <int> b, vector <int> &c) {
  int len = (int)a.size() + (int)b.size() - 1;
  n = len;
  while (n & (n-1)) ++n;
  assert(n <= MAX);
  
  REP(i, n) a1[i] = 0;
  REP(i, n) a2[i] = 0;
  REP(i, a.size()) a1[i] = a[i];
  REP(i, b.size()) a2[i] = b[i];

  REP(i, n) omega[i] = polar(1.0, 2*M_PI/n*i);
  fft(a1, z1, n);
  fft(a2, z2, n);

  REP(i, n) omega[i] = comp(1, 0) / omega[i];
  REP(i, n) a1[i] = z1[i] * z2[i] / comp(n, 0);
  fft(a1, z1, n);
	
  REP(i, len) c.push_back((long long)round(z1[i].real()) % MOD);
}

int N, M, K;
int cnt[MAXN], id[MAXN];

void load() {
	scanf("%d%d%d", &N, &M, &K);
	while (N--) {
		int x;
		scanf("%d", &x);
		cnt[--x]++;
	}
}

vector <int> solve(int lo, int hi) {
	if (lo >= hi)
		return {1};
	if (hi - lo == 1)
		return vector <int> (cnt[id[lo]] + 1, 1);
	int mid = (lo + hi) / 2;
	vector <int> ans;
	mult(solve(lo, mid), solve(mid, hi), ans);
	return ans;
}

int main() {
	load();
	for (int i = 0; i < M; i++)
		id[i] = i;
	random_shuffle(id, id + M);
	printf("%d\n", solve(0, M)[K]);
	return 0;
}