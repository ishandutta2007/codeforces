#include <bits/stdc++.h>

template<unsigned P>
class modint {
    static_assert(1 <= P);

    using mint = modint<P>;

protected:
    unsigned v;

public:
    modint() : v() {}

    template<typename T, typename std::enable_if<std::__and_<
      std::is_signed<T>, std::is_integral<T>>::value, bool>::type = true>
    modint(T _v) {
        long long tmp = _v % static_cast<long long>(P);
        if (tmp < 0) {
            tmp += P;
        }
        v = tmp;
    }

    template<typename T, typename std::enable_if<std::__and_<
      std::is_unsigned<T>, std::is_integral<T>>::value, bool>::type = true>
    modint(T _v) {
        v = _v % P;
    }

    unsigned val() const {
        return v;
    }

    static constexpr unsigned mod() {
        return P;
    }

    mint &operator+=(const mint &rhs) {
        v < P - rhs.v ? v += rhs.v : v -= P - rhs.v;
        return *this;
    }

    mint &operator++() {
        v + 1 < P ? ++v : v = 0;
        return *this;
    }

    mint operator++(int) {
        mint tmp = *this;
        v + 1 < P ? ++v : v = 0;
        return tmp;
    }

    mint &operator-=(const mint &rhs) {
        v < rhs.v ? v += P - rhs.v : v -= rhs.v;
        return *this;
    }

    mint &operator--() {
        v == 0 ? v = P - 1 : --v;
        return *this;
    }

    mint operator--(int) {
        mint tmp = *this;
        v == 0 ? v = P - 1 : --v;
        return tmp;
    }

    mint operator-() const {
        return mint(0) -= *this;
    }

    mint &operator*=(const mint &rhs) {
        v = static_cast<unsigned long long>(v) * rhs.v % P;
        return *this;
    }

    mint pow(unsigned long long b) const {
        mint a(*this), s(1);
        for (; b; b >>= 1) {
            if (b & 1) {
                s *= a;
            }
            a *= a;
        }
        return s;
    }

    mint inv() const {
        return pow(P - 2);
    }

    friend mint operator+(const mint &lhs, const mint &rhs) {
        return mint(lhs) += rhs;
    }

    friend mint operator-(const mint &lhs, const mint &rhs) {
        return mint(lhs) -= rhs;
    }

    friend mint operator*(const mint &lhs, const mint &rhs) {
        return mint(lhs) *= rhs;
    }

    friend bool operator==(const mint &lhs, const mint &rhs) {
        return lhs.v == rhs.v;
    }

    friend bool operator!=(const mint &lhs, const mint &rhs) {
        return lhs.v != rhs.v;
    }

    friend std::istream &operator>>(std::istream &in, mint &x) {
        return in >> x.v;
    }

    friend std::ostream &operator<<(std::ostream &out, const mint &x) {
        return out << x.v;
    }
};

using mint = modint<1000000007>;

template<typename _Val, typename _Tag = _Val, 
         typename _VV = std::plus<>, 
         typename _VT = std::plus<>, 
         typename _TT = std::plus<>>
class segment_tree {
public:
    typedef std::size_t size_type;

private:
    static size_type enlarge(size_type n) {
        size_type res = 1;
        while (res < n) {
            res <<= 1;
        }
        return res;
    }

protected:
    const size_type n, en;

    _VV fun_vv;
    _VT fun_vt;
    _TT fun_tt;

    std::vector<_Val> val;
    std::vector<_Tag> tag;

    void up(size_type u) {
        val[u] = fun_vv(val[u << 1], val[u << 1 | 1]);
    }

    void apply(size_type u, _Tag v) {
        val[u] = fun_vt(val[u], v);
        tag[u] = fun_tt(tag[u], v);
    }

    void down(size_type u) {
        apply(u << 1, tag[u]);
        apply(u << 1 | 1, tag[u]);
        tag[u] = _Tag();
    }

    template<typename T>
    void build(size_type u, size_type l, size_type r, 
               const std::vector<T> &a) {
        if (l + 1 == r) {
            val[u] = _Val(a[l]);
            return;
        }
        size_type mid = (l + r + 1) >> 1;
        build(u << 1, l, mid, a);
        build(u << 1 | 1, mid, r, a);
        up(u);
    }

    template<typename T>
    void modify(size_type u, size_type l, size_type r, 
                size_type x, const T &v) {
        if (l + 1 == r) {
            val[u] = _Val(v);
            return;
        }
        size_type mid = (l + r + 1) >> 1;
        down(u);
        if (x < mid) {
            modify(u << 1, l, mid, x, v);
        } else {
            modify(u << 1 | 1, mid, r, x, v);
        }
        up(u);
    }

    void modify(size_type u, size_type l, size_type r, 
                size_type L, size_type R, _Tag v) {
        if (L <= l && r <= R) {
            apply(u, v);
            return;
        }
        size_type mid = (l + r + 1) >> 1;
        down(u);
        if (L < mid) {
            modify(u << 1, l, mid, L, R, v);
        }
        if (mid < R) {
            modify(u << 1 | 1, mid, r, L, R, v);
        }
        up(u);
    }

    _Val query(size_type u, size_type l, size_type r, 
               size_type L, size_type R) {
        if (L <= l && r <= R) {
            return val[u];
        }
        size_type mid = (l + r + 1) >> 1;
        down(u);
        if (R <= mid) {
            return query(u << 1, l, mid, L, R);
        } else if (L >= mid) {
            return query(u << 1 | 1, mid, r, L, R);
        } else {
            return fun_vv(query(u << 1, l, mid, L, R), 
                          query(u << 1 | 1, mid, r, L, R));
        }
    }

public:
    segment_tree() : segment_tree(0) {}

    segment_tree(size_type _n)
    : n(_n), en(enlarge(n)), val(en << 1), tag(en << 1) {}

    template<typename T>
    segment_tree(const std::vector<T> &a)
    : n(a.size()), en(enlarge(n)), val(en << 1), tag(en << 1) {
        build(1, 0, n, a);
    }

    size_type size() const {
        return n;
    }

    template<typename T>
    void modify(size_type x, const T &v) {
        modify(1, 0, n, x, v);
    }

    void modify(size_type l, size_type r, _Tag v) {
        if (l < r) {
            modify(1, 0, n, l, r, v);
        }
    }

    _Val query(size_type l, size_type r) {
        if (l < r) {
            return query(1, 0, n, l, r);
        } else {
            return _Val();
        }
    }
};

struct node {
	int l, r;
	mint sum;

	node() : l(0), r(0), sum(0) {}

	node(int x) : l(x), r(x + 1), sum(0) {}

	node operator+(const node &rhs) const {
		node res;
		res.l = l;
		res.r = rhs.r;
		res.sum = sum + rhs.sum;
		return res;
	}

	node operator+(const mint &rhs) const {
		node res;
		res.l = l, res.r = r;
		res.sum = sum + rhs * (r - l);
		return res;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	std::cin >> n;
	std::vector<int> l(n), r(n);
	std::vector<mint> p(n);
	int m = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> l[i] >> r[i];
		--l[i];
		m = std::max(m, r[i]);
		p[i] = mint(r[i] - l[i]).inv();
	}
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	std::vector<int> dep(n), sz(n);
	auto dfs = [&](auto self, int u, int fa) -> void {
		sz[u] = 1;
		for (int v : E[u]) {
			if (v != fa) {
				dep[v] = dep[u] + 1;
				self(self, v, u);
				sz[u] += sz[v];
			}
		}
	};
	dfs(dfs, 0, -1);

	std::vector<mint> a(m);
	for (int i = 0; i < n; ++i) {
		a[l[i]] += p[i];
		if (r[i] < m) {
			a[r[i]] -= p[i];
		}
	}
	for (int i = 1; i < m; ++i) {
		a[i] += a[i - 1];
	}
	std::vector<mint> sum(m + 1);
	for (int i = 0; i < m; ++i) {
		sum[i + 1] = sum[i] + a[i];
	}
	mint ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (sum[r[i]] - sum[l[i]] - 1) * p[i] * dep[i];
	}

	std::vector<node> tmp(m);
	for (int i = 0; i < m; ++i) {
		tmp[i] = node(i);
	}
	segment_tree<node, mint> T(tmp);
	std::vector<std::tuple<int, int, mint>> oper;

	auto get_ans = [&](auto self, int u, int fa) -> void {
		int son = -1;
		for (int v : E[u]) {
			if (v != fa) {
				if (son == -1 || sz[v] > sz[son]) {
					son = v;
				}
			}
		}
		while (!oper.empty()) {
			auto [l, r, v] = oper.back();
			oper.pop_back();
			T.modify(l, r, -v);
		}
		for (int v : E[u]) {
			if (v != fa && v != son) {
				self(self, v, u);
			}
		}
		if (son != -1) {
			self(self, son, u);
		}
		ans -= 2 * dep[u] * T.query(l[u], r[u]).sum * p[u];
		T.modify(l[u], r[u], p[u]);
		oper.emplace_back(l[u], r[u], p[u]);

        int U = u;

		auto query = [&](auto self, int u, int fa) -> void {
			ans -= 2 * dep[U] * T.query(l[u], r[u]).sum * p[u];
			for (int v : E[u]) {
				if (v != fa) {
					self(self, v, u);
				}
			}
		};
		auto add = [&](auto self, int u, int fa) -> void {
			T.modify(l[u], r[u], p[u]);
			oper.emplace_back(l[u], r[u], p[u]);
			for (int v : E[u]) {
				if (v != fa) {
					self(self, v, u);
				}
			}
		};
		for (int v : E[u]) {
			if (v != fa && v != son) {
				query(query, v, u);
				add(add, v, u);
			}
		}
	};

	get_ans(get_ans, 0, -1);

	for (int i = 0; i < n; ++i) {
		ans *= r[i] - l[i];
	}
	std::cout << ans << "\n";
}