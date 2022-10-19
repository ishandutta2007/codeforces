#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

const int64_t CUTOFF = 2000000, INF = (int64_t) (1.001e18);
const int SQRT = (int) sqrt(1e15) + 10000;

bool composite[SQRT];
int primes[SQRT], numPrimes;

vector<int64_t> factorize(int64_t K)
{
	vector<int64_t> vec;
	for (int i = 0; (int64_t) primes[i] * primes[i] <= K; ++i) if (K % primes[i] == 0) {
		vec.push_back(primes[i]);
		while (K % primes[i] == 0) K /= primes[i];
	}
	if (K > 1) vec.push_back(K);
	return vec;
}

int main()
{
	numPrimes = 0;
	for (int i = 2; i * i < SQRT; ++i) if (!composite[i]) {
		for (int j = i * i; j < SQRT; j += i) composite[j] = true;
	}
	for (int i = 2; i < SQRT; ++i) if (!composite[i]) primes[numPrimes++] = i;
	int T;
	cin >> T;
	vector<int> ans(T);
	map<int64_t, vector<pair<int64_t, int>>> Q;
	for (int i = 0; i < T; ++i) {
		int64_t N, K;
		cin >> N >> K;
		Q[K].emplace_back(N, i);
	}

	for (auto &qK : Q) {
		int64_t K = qK.first;
		vector<int64_t> factors = factorize(K);

		if (K == 1) {
			for (auto &q : Q[K]) ans[q.second] = 0;
		} else if ((int) factors.size() == 1) {
			for (auto &q : Q[K]) ans[q.second] = (q.first % K == 0);
		} else if (factors[0] > CUTOFF) {
			assert((int) factors.size() == 2);
			int64_t a = factors[0], b = factors[1];
			assert(b <= (int) 1e9);
			assert(__gcd(a, b) == 1);
			int64_t x0 = 0, y0 = 1, z0 = b;
			int64_t x1 = 1, y1 = 0, z1 = a;
			while (z0 > 0) {
				int64_t q = z1 / z0;
				x1 -= x0 * q, y1 -= y0 * q, z1 -= z0 * q;
				swap(x0, x1), swap(y0, y1), swap(z0, z1);
			}
			assert(z1 == 1);

			if (x1 < 0) x1 += b, y1 -= b;
			assert(0 <= x1 && x1 < b);
			assert((x1 * a) % b == 1);
			for (auto &q : Q[K]) ans[q.second] = (1.0 * (x1 * (q.first % b) % b) * a < 2e18) && (((x1 * (q.first % b) % b) * a) <= q.first);
		} else {
			int S = (int) factors[0];
			factors.erase(factors.begin());
			vector<int64_t> dist(S, INF);
			priority_queue<pair<int64_t, int>> pq;
			pq.emplace(dist[0] = 0, 0);
			while (!pq.empty()) {
				int64_t d = -pq.top().first;
				int u = pq.top().second;
				pq.pop();
				if (d != dist[u]) continue;

				for (int64_t x : factors) {
					int v = (int) ((u + x) % S);
					if (dist[v] > d + x) pq.emplace(-(dist[v] = d + x), v);
				}
			}

			for (auto &q : Q[K]) ans[q.second] = dist[q.first % S] <= q.first;
		}
	}

	for (int i = 0; i < T; ++i) puts(ans[i] ? "YES" : "NO");
}