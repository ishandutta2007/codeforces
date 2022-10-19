#include <bits/stdc++.h>
using namespace std;

// ecnerwala library
template <typename T> T mod_inv_in_range(T a, T m) {
	// assert(0 <= a && a < m);
	T x = a, y = m;
	T vx = 1, vy = 0;
	while (x) {
		T k = y / x;
		y %= x;
		vy -= k * vx;
		std::swap(x, y);
		std::swap(vx, vy);
	}
	assert(y == 1);
	return vy < 0 ? m + vy : vy;
}

template <typename T> T mod_inv(T a, T m) {
	a %= m;
	a = a < 0 ? a + m : a;
	return mod_inv_in_range(a, m);
}

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	int v;

public:

	modnum() : v(0) {}
	modnum(int64_t v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { int64_t v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = mod_inv_in_range(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v -= MOD-o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(int64_t(v) * int64_t(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

const int M = 1000000;
const int N = 31;

using mint = modnum<998244353>;
using poly = vector<mint>;

poly antideriv(poly p) {
  int k = (int)p.size();
  poly ans(k+1);
  for (int i = 0; i < k; i++) {
    ans[i+1] = p[i]/(i+1);
  }
  return ans;
}

poly shift(poly p) {
  // return p(x-M)
  // a_0 + a_1((x-M)+a_2((x-M)+...))
  int k = (int)p.size();
  poly ans;
  for (int i = k-1; i >= 0; i--) {
    ans.push_back(0);
    for (int j = (int)ans.size()-1; j >= 0; j--) {
      ans[j] = (j ? ans[j-1] : 0)-M*ans[j];
    }
    ans[0] += p[i];
  }
  return ans;
}

mint eval(poly p, mint x) {
  int k = (int)p.size();
  mint ans = 0;
  mint xp = 1;
  for (int i = 0; i < k; i++) {
    ans += xp*p[i];
    xp *= x;
  }
  return ans;
}

poly operator - (poly a, poly b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < (int)b.size(); i++) {
    a[i] -= b[i];
  }
  return a;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> residues(1);
  for (int i = 0; i < n; i++) {
    double s;
    cin >> s;
    x[i] = round(M*s);
    residues.push_back(x[i]%M);
  }
  sort(residues.begin(), residues.end());
  residues.resize(unique(residues.begin(), residues.end())-residues.begin());
  int k = residues.size();
  vector<int> left_point(n*k);
  vector<int> right_point(n*k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      left_point[k*i+j] = M*i+residues[j];
    }
  }
  for (int i = 0; i < n*k-1; i++) {
    right_point[i] = left_point[i+1];
  }
  right_point[n*k-1] = M*n;

  vector<poly> dp(n*k);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      for (int j = 0; j < k; j++) {
        dp[j].resize(1, 1);
      }
    }
    else {
      for (int j = 0; j < n*k; j++) {
        dp[j] = antideriv(dp[j]);
        if (j) dp[j][0] += eval(dp[j-1], left_point[j]) - eval(dp[j], left_point[j]);
      }
      for (int j = n*k-1; j >= k; j--) {
        dp[j] = dp[j] - shift(dp[j-k]);
      }
    }
    int z = k*(x[i]/M) + lower_bound(residues.begin(), residues.end(), x[i]%M)-residues.begin();
    for (int j = z; j < n*k; j++) {
      dp[j].clear();
    }
  }

  mint ans = 0;
  for (int j = 0; j < n*k; j++) {
    poly q = antideriv(dp[j]);
    ans += eval(q, right_point[j])-eval(q, left_point[j]);
  }
  ans *= pow(mint(1)/M, n);
  cout << ans << '\n';
}