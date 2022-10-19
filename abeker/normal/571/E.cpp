#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef unordered_map <int, int> umap;

const int MAXN = 1e2 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;

umap factor(int x) {
	umap res;
	for (int i = 2; i * i <= x; i++) 
		for (; !(x % i); x /= i)
			res[i]++;
	if (x > 1) 
		res[x]++;
	return res;
}

int expo(int x, ll y, int m) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = (ll)res * x % m;
		x = (ll)x * x % m;
	}
	return res;
}

namespace CRT {
	int inverse(ll a, int b, int p) {
		return expo(a % b, b / p * (p - 1) - 1, b);
	}
	
	pair <ll, ll> solve_system(vector <pii> cong) {
		map <pii, int> cond;
		for (auto &it : cong) {
			it.first %= it.second;
			if (it.first < 0)
				it.first += it.second;
			umap tmp = factor(it.second);
			for (auto p : tmp) {
				int pot = 1;
				for (int i = 0; i < p.second; i++)
					pot *= p.first;
				auto pos = cond.find({p.first, pot});
				if (pos != cond.end() && pos -> second != it.first % pot)
					return {-1, -1};
				cond[{p.first, pot}] = it.first % pot;
			}
		}
		
		map <int, vector <pii>> sorted;
		for (auto it : cond)
			sorted[it.first.first].push_back({it.second, it.first.second});	
		
		vector <pair <pii, int>> sys;
		for (auto it : sorted) {
			vector <pii> todo = it.second;
			if (todo.empty())
				continue;
			for (int i = 1; i < todo.size(); i++) 
				if (todo[i].first % todo[i - 1].second != todo[i - 1].first)
					return {-1, -1};
			sys.push_back({todo.back(), it.first});
		}
		
		ll prod = 1;
		for (auto it : sys)
			prod *= it.first.second;
		
		ll res = 0;
		for (auto it : sys) {
			ll other = prod / it.first.second;
			res += other * inverse(other, it.first.second, it.second) * it.first.first % prod;
			if (res >= prod)
				res -= prod;
		}
		
		return {res, prod};
	}
	
	ll arithm_prog(const vector <pii> &seq) {
		pair <ll, ll> res = solve_system(seq);
		if (res.second == -1)
			return -1;
		ll mx = 0;
		for (auto it : seq)
			if (it.first > res.first)
				mx = max(mx, (it.first - res.first - 1) / res.second + 1);
		return mx * res.second + res.first;
	}
};

class vec {
	public:
		vector <ll> v;
		vec(vector <ll> _v) {
			v = _v;
		}
		vec(int n) {
			v.resize(n);
		}
		vec() {}
		ll& operator [](int x) {
			return v[x];
		}
		int len() {
			return v.size();
		}
		bool is_zero() {
			for (auto it : v)
				if (it)
					return false;
			return true;
		}
		ll content() {
			ll g = 0;
			for (auto it : v)
				g = __gcd(g, it);
			return g;
		}
		void output() {
			for (auto it : v)
				printf("%lld ", it);
			puts("");
		}
};

vec operator +(vec p, vec q) {
	int sz = p.len();
	assert(q.len() == sz);
	vec r(sz);
	for (int i = 0; i < sz; i++)
		r[i] = p[i] + q[i];
	return r;
}

vec operator -(vec p, vec q) {
	int sz = p.len();
	assert(q.len() == sz);
	vec r(sz);
	for (int i = 0; i < sz; i++)
		r[i] = p[i] - q[i];
	return r;
}

vec operator *(ll scalar, vec p) {
	int sz = p.len();
	for (int i = 0; i < sz; i++)
		p[i] *= scalar;
	return p; 
}

void operator /=(vec &p, ll scalar) {
	assert(scalar);
	int sz = p.len();
	for (int i = 0; i < sz; i++)
		p[i] /= scalar;
}

pair <int, vec> divide(vec p, vec q) {
	int sz = p.len();
	assert(q.len() == sz);
	for (int i = 0; i < sz; i++)
		if (q[i])
			return {p[i] / q[i], p - (p[i] / q[i]) * q};
	assert(false);
}

bool operator !=(const vec &p, const vec &q) {
	return p.v != q.v;
}

int N, K;
int a[MAXN], b[MAXN];
umap fa[MAXN], fb[MAXN];
vec alpha[MAXN], beta[MAXN], gamma[MAXN];
int lambda[MAXN], mu[MAXN];
vector <int> primes[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", a + i, b + i);
}

bool in_all(int x) {
	for (int i = 0; i < N; i++) {
		if (x % a[i])
			return false;
		int y = x / a[i];
		if (b[i] == 1) {
			if (y != 1)
				return false;
			continue;
		}
		while (!(y % b[i]))
			y /= b[i];
		if (y > 1)
			return false;
	}
	return true;
}

int calc(vec e) {
	int res = 1;
	for (int i = 0; i < K; i++) 
		res = (ll)res * expo(primes[0][i], e[i], MOD) % MOD;
	return res;
}

int two_by_two(int A, int B, int C, int D, int Z, int W) {
	int det = A * D - B * C;
	if (!det)
		return INF;
	return (D * Z - B * W) / det;
}

int finish(int x, int y) {
	beta[x] = lambda[x] * beta[x];
	beta[y] = lambda[y] * beta[y];
	for (int i = 1; i < K; i++) {
		int tmp = two_by_two(beta[x][i], -beta[y][i], beta[x][i - 1], -beta[y][i - 1], alpha[y][i] - alpha[x][i], alpha[y][i - 1] - alpha[x][i - 1]);
		if (tmp == INF)
			continue;
		if (tmp < 0)
			return -1;
		vec cand = alpha[x] + tmp * beta[x];
		for (int j = 0; j < N; j++) {
			vec curr = cand - alpha[j];
			for (int k = 0; k < K; k++)
				if (curr[k] < 0)
					return -1;
			if (!divide(curr, beta[j]).second.is_zero())
				return -1;
		}
		return calc(cand);
	}
	assert(false);
}

int solve() {
	for (int i = 0; i < N; i++)
		if (in_all(a[i])) 
			return a[i];
	
	for (int i = 0; i < N; i++) {		
		if (b[i] == 1)
			return -1;
		fa[i] = factor(a[i]);
		fb[i] = factor(b[i]);
		for (auto it : fa[i])
			primes[i].push_back(it.first);
		for (auto it : fb[i])
			primes[i].push_back(it.first);
		sort(primes[i].begin(), primes[i].end());
		primes[i].resize(unique(primes[i].begin(), primes[i].end()) - primes[i].begin());
		if (primes[i] != primes[0])
			return -1;
	}
	
	K = primes[0].size();
	for (int i = 0; i < N; i++) {
		alpha[i] = beta[i] = vec(K);
		for (int j = 0; j < K; j++) {
			alpha[i][j] = fa[i][primes[0][j]];
			beta[i][j] = fb[i][primes[0][j]];
		}
	}
	
	for (int i = 0; i < N; i++) {
		lambda[i] = beta[i].content();
		beta[i] /= lambda[i];
		if (beta[i] != beta[0])
			return finish(i, 0);
		pair <int, vec> tmp = divide(alpha[i], beta[i]);
		mu[i] = tmp.first;
		gamma[i] = tmp.second;
	}
	
	vector <pii> arithm;
	for (int i = 0; i < N; i++) {
		if (gamma[i] != gamma[0])
			return -1;
		arithm.push_back({mu[i], lambda[i]});
	}
	
	ll coef = CRT::arithm_prog(arithm);
	if (coef == -1)
		return -1;
		
	return calc(gamma[0] + coef * beta[0]);
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}