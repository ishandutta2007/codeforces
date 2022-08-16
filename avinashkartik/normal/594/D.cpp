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

const ll   N     =  1e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

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

template<int N>
struct spf_sieve {
    std::vector<int> primes;
    std::array<int, N + 1> spf;

    spf_sieve() : spf() {
        for (int i = 2; i <= N; i++) {
            if (spf[i] == 0) {
                spf[i] = i;
                primes.push_back(i);
            }
            for (int j = 0; j < (int) primes.size() && i * primes[j] <= N; j++) {
                spf[i * primes[j]] = primes[j];
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
    }

    bool is_prime(int x) const {
        return spf[x] == x;
    }

    std::vector<std::pair<int, int>> prime_factors(int x) const {
        std::vector<std::pair<int, int>> factors;
        while (x != 1) {
            if (factors.empty() || factors.back().first != spf[x]) {
                factors.emplace_back(spf[x], 0);
            }
            factors.back().second++;
            x /= spf[x];
        }
        return factors;
    }

    std::vector<int> divisors(int x) const {
        std::vector<int> divisors = {1};
        while (x > 1) {
            int p = spf[x], c = 0;
            while (x % p == 0) {
                x /= p, c += 1;
            }
            int sz = (int) divisors.size();
            for (int i = 1, pw = p; i <= c; i++, pw *= p) {
                for (int j = 0; j < sz; j++) {
                    divisors.push_back(divisors[j] * pw);
                }
            }
        }
        return divisors;
    }

    template<typename T, typename F>
    T compute_multiplicative_function(int x, F &&f) const {
        T result = T(1);
        while (x > 1) {
            int p = spf[x], c = 0;
            while (spf[x] == p) {
                x /= p, c += 1;
            }
            result *= f(p, c);
        }
        return result;
    }
};

template<typename T, typename F = std::function<T(const T&, const T&)>>
struct segment_tree {
	int n;
	std::vector<T> tree;
	T e;
	F f;

	segment_tree() : n(), e(), f() {}

	template<typename U>
	segment_tree(const std::vector<U> &v, int n, T e, F &&f): n(n), tree(4 * n), e(e), f(f) {
		build(v, 1, 1, n);
	}

	template<typename U>
	void build(const std::vector<U> &v, int node, int start, int end) {
		if (start == end) {
			tree[node] = T(v[start]);
		} else {
			int mid = (start + end) / 2;
			build(v, 2 * node, start, mid);
			build(v, 2 * node + 1, mid + 1, end);
			tree[node] = f(tree[2 * node], tree[2 * node + 1]);
		}
	}

	template<typename U>
	void update(int idx, U val) {
		update_helper(1, 1, n, idx, val);
	}

	template<typename U>
	void update_helper(int node, int start, int end, int idx, U val) {
		if (start == end) {
			tree[node].ans *= val;
		} else {
			int mid = (start + end) / 2;
			if (start <= idx and idx <= mid)
				update_helper(2 * node, start, mid, idx, val);
			else
				update_helper(2 * node + 1, mid + 1, end, idx, val);
			tree[node] = f(tree[2 * node], tree[2 * node + 1]);
		}
	}

	T query(int l, int r) {
		return query_helper(1, 1, n, l, r);
	}

	T query_helper (int node, int start, int end, int l, int r) {
		if (start > end or start > r or end < l)
			return e;
		if (l <= start and end <= r)
			return tree[node];
		int mid = (start + end) / 2;
		T p1 = query_helper(2 * node, start, mid, l, r);
		T p2 = query_helper(2 * node + 1, mid + 1, end, l, r);
		return f(p1, p2);
	}
};

struct node {
	mint ans;
	node(): ans(1) {}
	node(mint x): ans(x) {}
};

int n, q, a[N], l[N], r[N], last[N];
mint ans[N];
spf_sieve <N> s;

void solve() {
	cin >> n;
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	segment_tree st(a, n, node(), [&](const node &a, const node &b){
		node c;
		c.ans = a.ans * b.ans;
		return c;
	});

	cin >> q;
	vector <vector <int>> ind(n + 1);
	for (int i = 1; i <= q; i++) {
		cin >> l[i] >> r[i];
		ind[r[i]].pb(i);
	}

	for (int i = 1; i <= n; i++) {
		for (auto [pf, no] : s.prime_factors(a[i])) {
			if (last[pf] == 0) {
				st.update(i, mint(pf - 1) * mint(pf).inv());
			} else {
				st.update(last[pf], mint(pf) * mint(pf - 1).inv());
				st.update(i, mint(pf - 1) * mint(pf).inv());
			}
			last[pf] = i;
		}
		for (auto it : ind[i]) {
			ans[it] = st.query(l[it], r[it]).ans;
		}
	}

	for (int i = 1; i <= q; i++) deb1(ans[i]);
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}