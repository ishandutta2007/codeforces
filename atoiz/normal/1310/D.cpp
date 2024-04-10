/*input
3 2
0 1 1
2 0 1
2 2 0
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 82, INF = 1e9;
int N, K;
int dist1[MAXN][MAXN];
vector<pair<int, int>> dist2[MAXN][MAXN];

int vertex[MAXN], ans = INF;
bool used[MAXN];

void backtrack(int id)
{
	if (id == K) {
		int total_cost = 0;
		for (int i = 2; i <= K; i += 2) {
			int cur_cost = -1;
			for (auto p : dist2[vertex[i - 2]][vertex[i]]) {
				if (not used[p.second]) {
					cur_cost = p.first;
					break;
				}
			}
			if (cur_cost == -1) return;
			total_cost += cur_cost;
		}
		ans = (ans < total_cost ? ans : total_cost);
		return;
	}

	for (int i = 1; i <= N; ++i) {
		bool already_used = used[i];
		used[i] = true;
		vertex[id] = i;

		backtrack(id + 2);
		used[i] = already_used;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> dist1[i][j];
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (int k = 1; k <= N; ++k) {
				if (k != i and k != j) {
					dist2[i][j].emplace_back(dist1[i][k] + dist1[k][j], k);
				}
			}
			sort(dist2[i][j].begin(), dist2[i][j].end());
		}
	}

	vertex[0] = vertex[K] = 1;
	used[1] = 1;
	backtrack(2);
	cout << ans << endl;
	return 0;
}