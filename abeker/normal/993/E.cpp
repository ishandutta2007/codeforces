#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

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

void mult(vector <ll> a, vector <ll> b, vector <ll> &c) {
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
	
  REP(i, len) c.push_back(round(z1[i].real()));
}

int N, X;
int pref[MAXN];

void load() {
	scanf("%d%d", &N, &X);
	for (int i = 1; i <= N; i++) {
		int tmp;
		scanf("%d", &tmp);
		pref[i] = pref[i - 1] + (tmp < X);
	}
}

void solve() {
	vector <ll> cnt, rev, ans;
	cnt.resize(N + 1);
	rev.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		cnt[pref[i]]++;
		rev[N - pref[i]]++;
	}
	
	mult(cnt, rev, ans);
	
	ans[N] -= N + 1;
	ans[N] /= 2;
	for (int i = 0; i <= N; i++)
		printf("%lld ", ans[i + N]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}