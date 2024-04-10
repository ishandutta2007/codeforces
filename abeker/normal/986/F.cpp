#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

const int MAXT = 1e4 + 5;
const ll INF = LLONG_MAX;
const int MAXP = 32000000;

int T;
ll n[MAXT], k[MAXT];
bool ans[MAXT];
vector <int> v;
bool comp[MAXP];
set <ll> S;

void sieve() {
	for (int i = 2; i < MAXP; i++)
		if (!comp[i]) {
			v.push_back(i);
			if ((ll)i * i < MAXP)
				for (int j = i * i; j < MAXP; j += i)
					comp[j] = true;
		}
}

void load() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
		scanf("%lld%lld", n + i, k + i);
}

vector <ll> factorize(ll x) {
	vector <ll> res;
	if (x > 1e12) {
		for (auto it : v)
			if (!(x % it)) {
				while (!(x % it))
					x /= it;
				res.push_back(it);
			}
		if (x > 1)
			res.push_back(x);
		return res;
	}
	for (ll i = 2; i * i <= x; i++) 
		if (!(x % i)) {
			while (!(x % i))
				x /= i;
			res.push_back(i);
		}
	if (x > 1)
		res.push_back(x);
	return res;
}

void solve_one(ll K, ll p) {
	for (int i = 0; i < T; i++)
		if (k[i] == K)
			ans[i] = !(n[i] % p);
}

inline int mul(int a, int b, int mod) {
	return (ll)a * b % mod;
}

int pot(int a, int b, int mod) {
	int res = 1;
	for (; b; b /= 2) {
		if (b % 2)
			res = mul(res, a, mod);
		a = mul(a, a, mod);
	}
	return res;
}

void solve_two(ll K, ll p, ll q) {
	int inv = pot(q % p, p - 2, p);
	for (int i = 0; i < T; i++)
		if (k[i] == K) 
			ans[i] = mul(n[i] % p, inv, p) <= n[i] / q;
}

void solve_many(ll K, vector <ll> primes) {
	assert(primes.size() <= 13);
	int p = primes[0];
	assert(p <= 1e5);
	vector <pii> rest;
	for (int i = 1; i < primes.size(); i++)
		rest.push_back({primes[i], primes[i] % p});
		
	vector <ll> dist(p, INF);
	dist[0] = 0;
	priority_queue <pii> Q;
	Q.push({0, 0});
		
	while (!Q.empty()) {
		pii tmp = Q.top();
		Q.pop();
		for (auto it : rest) {
			int nxt = tmp.second + it.second;
			if (nxt >= p)
				nxt -= p;
			if (dist[nxt] > -tmp.first + it.first) {
				dist[nxt] = -tmp.first + it.first;
				Q.push({-dist[nxt], nxt});
			}
		}	
	}
	
	for (int i = 0; i < T; i++)
		if (k[i] == K)
			ans[i] = n[i] >= dist[n[i] % p];
}

void solve() {
	for (int i = 0; i < T; i++)
		S.insert(k[i]);
	
	assert(S.size() <= 50);
	
	for (auto it : S) {
		vector <ll> tmp = factorize(it);
		if (tmp.size() == 1)
			solve_one(it, tmp[0]);
		else if (tmp.size() == 2)
			solve_two(it, tmp[0], tmp[1]);
		else if (tmp.size() > 2)
			solve_many(it, tmp);
	}
	
	for (int i = 0; i < T; i++)
		puts(ans[i] ? "YES" : "NO");
}

int main() {
	sieve();
	load();
	solve();
	return 0;
}