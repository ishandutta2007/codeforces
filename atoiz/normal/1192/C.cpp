/*input
3
MAN1LA
MAN6OS
AN4NAS

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 100003, MAXC = 62, MAXL = 8, MOD = 998244353;
int N, mp[300];
long long A[MAXL][MAXC][MAXC], F[MAXC][MAXC][MAXC];
int ans[25];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 26; ++i) mp['a' + i] = i;
	for (int i = 0; i < 26; ++i) mp['A' + i] = i + 26;
	for (int i = 0; i < 10; ++i) mp['0' + i] = i + 52;

	cin >> N;
	vector<string> vec(2 * N);
	for (int i = 0; i < N; ++i) {
		cin >> vec[i];
		vec[N + i] = vec[i];
		reverse(vec[i].begin(), vec[i].end());
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (string str : vec) {
		int l = str.size() - 3;
		++A[l][mp[str.front()]][mp[str.back()]];
	}

	for (int l = 0; l < MAXL; ++l) {
		for (int i = 0; i < MAXC; ++i) for (int j = i; j < MAXC; ++j) for (int k = j; k < MAXC; ++k) {
			F[i][j][k] = 0;
			for (int x = 0; x < MAXC; ++x) {
				int cur = (1ull * A[l][x][i] * A[l][x][j] * A[l][x][k]) % MOD;
				F[i][j][k] += cur;
				if (F[i][j][k] >= MOD) F[i][j][k] -= MOD;
			}
			// if (F[i][j][k]) cout << l + 3 << " - " << i << ' ' << j << ' ' << k << ": " << F[i][j][k] << endl;
		}

		for (int h = 0; h < MAXC; ++h) {
			for (int i = h; i < MAXC; ++i) {
				for (int j = i; j < MAXC; ++j) {
					int ways0 = 24, ways1 = 24;
					if (h == j) ways0 /= 6, ways1 /= 24;
					else if (h == i && i != j) ways0 /= 2, ways1 /= 4;
					else if (h != i && i == j) ways0 /= 2, ways1 /= 6;
					else ways0 /= 1, ways1 /= 2;

					for (int k = j; k < MAXC; ++k) {
						int cur = (1ll * F[h][i][j] * F[h][i][k] % MOD * F[h][j][k] % MOD * F[i][j][k] % MOD);
						int w = (j == k ? ways1 : ways0);
						ans[w] += cur;
						if (ans[w] >= MOD) ans[w] -= MOD;
					}
				}
			}
		}
	}

	long long finalAns = 0;
	for (int i = 0; i < 25; ++i) {
		finalAns += 1ll * ans[i] * i;
	}
	cout << finalAns % MOD << endl;
}