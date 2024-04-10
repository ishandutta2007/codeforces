#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");
 
	int val;
 
	constexpr static_mint() : val() {}
 
	constexpr static_mint(long long x) : val(x % M) { if (val < 0) val += M; }
 
	constexpr static_mint pow(long long n) const {
		static_mint ans = 1, x(*this);
		for (; n > 0; n /= 2) {
			if (n & 1) ans *= x;
			x *= x;
		}
		return ans;
	}
 
	constexpr static_mint inv() const {
		return pow(M - 2);
	}
 
	constexpr static_mint operator+() const {
		static_mint m;
		m.val = val;
		return m;
	}
 
	constexpr static_mint operator-() const {
		static_mint m;
		m.val = (val == 0 ? 0 : M - val);
		return m;
	}
 
	constexpr static_mint &operator+=(const static_mint &m) {
		if ((val += m.val) >= M) val -= M;
		return *this;
	}
 
	constexpr static_mint &operator-=(const static_mint &m) {
		if ((val -= m.val) < 0) val += M;
		return *this;
	}
 
	constexpr static_mint &operator*=(const static_mint &m) {
		val = (long long) val * m.val % M;
		return *this;
	}
 
	constexpr static_mint &operator/=(const static_mint &m) {
		val = (long long) val * m.inv().val % M;
		return *this;
	}
 
	constexpr friend static_mint operator+(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) += rhs;
	}
 
	constexpr friend static_mint operator-(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) -= rhs;
	}
 
	constexpr friend static_mint operator*(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) *= rhs;
	}
 
	constexpr friend static_mint operator/(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) /= rhs;
	}
 
	constexpr friend bool operator==(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val == rhs.val;
	}
 
	constexpr friend bool operator!=(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val != rhs.val;
	}
 
	constexpr static_mint &operator++() {
		return *this += 1;
	}
 
	constexpr static_mint &operator--() {
		return *this -= 1;
	}
 
	constexpr static_mint operator++(int) {
		static_mint result(*this);
		*this += 1;
		return result;
	}
 
	constexpr static_mint operator--(int) {
		static_mint result(*this);
		*this -= 1;
		return result;
	}
 
	template<typename T>
	constexpr explicit operator T() const {
		return T(val);
	}
 
	friend std::ostream &operator<<(std::ostream &os, const static_mint &m) {
		return os << m.val;
	}
 
	friend std::istream &operator>>(std::istream &is, static_mint &m) {
		long long x;
		return is >> x, m = x, is;
	}
};

using mint = static_mint<mod>;
mint f[N];

mint ncr(ll n, ll r) {
	return f[n] / (f[r] * f[n - r]);
}

ll n, k;

void solve() {
	cin >> n >> k;
	if (k >= n) {
		deb1(mint(2).pow(n))
		return;
	}
	f[0] = 1;
	for (int i = 1; i <= n; i++) f[i] = i * f[i - 1];
	mint ans = 1;
	for (int i = 1; i <= k; i++) {
		ans += ncr(n, i);
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}