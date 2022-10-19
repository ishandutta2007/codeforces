#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vector<long long> conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vector<long long> res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = round(imag(out[i]) / (4 * n));
	return res;
}

template<typename T>
vector<T> operator + (vector<T> a, vector<T> b) {
  assert(a.size() == b.size());
  for (int i = 0; i < (int)a.size(); i++) {
    a[i] += b[i];
  }
  return a;
}

template<typename T>
vector<T> operator - (vector<T> a, vector<T> b) {
  assert(a.size() == b.size());
  for (int i = 0; i < (int)a.size(); i++) {
    a[i] -= b[i];
  }
  return a;
}

// type 1: cells >= x
// type 2: cells < x
// C1 = V1-E1+F1
// C2 = V2-E2+F2
// D1 = F2-Q2 (D1 = components not reaching the edge)
// D2 = F1-Q1
// C1+D1-C2-D2 = (V1-V2)-(E1-E2)+(Q1-Q2)

const int N = 1e5+1;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n), b(m);
  vector<double> a0(N), b0(N), a1(N), b1(N), a2(N), b2(N);
  for (int& x: a) {
    cin >> x;
    a0[x]++;
  }
  for (int& x: b) {
    cin >> x;
    b0[x]++;
  }
  for (int i = 0; i < n-1; i++) {
    a1[min(a[i], a[i+1])]++;
    a2[max(a[i], a[i+1])]++;
  }
  for (int i = 0; i < m-1; i++) {
    b1[min(b[i], b[i+1])]++;
    b2[max(b[i], b[i+1])]++;
  }

  vector<long long> ans = conv(a1-a0, b0-b1)+conv(a2-a0, b0-b2);
  for (int i = 1; i < (int)ans.size(); i++) ans[i] += ans[i-1];

  while (q--) {
    int x;
    cin >> x;
    cout << ans[x-1]+1 << '\n';
  }
}