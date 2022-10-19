/*input
18 0
*/
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
int E[18], N, M;
long long F[1 << 18];
int B[1 << 18];
 
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		E[u] ^= (1 << v);
		E[v] ^= (1 << u);
	}
 
	for (int mask = 1; mask < (1 << N); ++mask) {
		int cur = 0;
		for (int u = 0; u < N; ++u) if ((mask >> u) & 1) {
			cur |= E[u];
		}
		B[mask] = (!(cur & mask)) * (2 * (__builtin_popcount(mask) & 1) - 1);
	}
 
	F[0] = 1;
	for (int mask = 1; mask < (1 << N); ++mask) {
		if (__builtin_popcount(mask) == 1) {
			F[mask] = 1;
			continue;
		}
 
		vector<int> vec = {0};
		for (int tmp = mask; tmp; tmp ^= tmp & (-tmp)) {
			int sz = vec.size();
			for (int i = 0; i < sz; ++i) vec.push_back(vec[i] ^ (tmp & (-tmp)));
		}
		for (int cur : vec) {
			F[mask] += B[cur] * F[cur ^ mask];
		}
	}
 
	cout << F[(1 << N) - 1] * M / 2 % 998244353 << endl;
}