#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <bitset>
#include <cassert>

using namespace std;

const int MAXN = 1 << 10, SZ = MAXN << 1;
int N, K;
vector<bitset<SZ>> equations;
bool state[MAXN][2][2];
int mapping[1 << 8];
char reverseMapping[4];
bool result[SZ];

int main()
{
	// freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		state[i][0][0] = state[i][1][1] = 1;
	}

	mapping['R'] = 1, mapping['Y'] = 2, mapping['B'] = 3, mapping['W'] = 0;
	reverseMapping[0] = '.', reverseMapping[1] = 'R', reverseMapping[2] = 'Y', reverseMapping[3] = 'B';

	while (K--) {
		string type;
		cin >> type;
		vector<int> idxs;
		int len;
		cin >> len;
		idxs.resize(len);
		for (int &x : idxs) { cin >> x; --x; }

		if (type == "mix") {
			char ch;
			cin >> ch;
			int col = mapping[(int) ch];

			for (int k = 0; k < 2; ++k) {
				bitset<SZ> cur = 0;
				cur[SZ - 1] = (col >> k) & 1;

				for (int x : idxs) {
					cur[x * 2] = state[x][k][0];
					cur[x * 2 + 1] = state[x][k][1];
				}
				equations.push_back(cur);
			}
		} else {
			for (int x : idxs) {
				if (type == "RY") {
					swap(state[x][0][0], state[x][1][0]);
					swap(state[x][0][1], state[x][1][1]);
				} else if (type == "RB") {
					state[x][1][0] ^= state[x][0][0];
					state[x][1][1] ^= state[x][0][1];
				} else {
					state[x][0][0] ^= state[x][1][0];
					state[x][0][1] ^= state[x][1][1];
				}
			}
		}
	}

	int start = 0;
	vector<int> posList;
	for (int pos = 0; pos < 2 * N; ++pos) {
		int id = -1;
		for (int i = start; i < (int) equations.size(); ++i) {
			if (equations[i][pos]) {
				id = i;
				break;
			}
		}

		if (~id) {
			if (start != id) swap(equations[id], equations[start]);
			for (int i = 0; i < (int) equations.size(); ++i) {
				if (i != start && equations[i][pos]) {
					equations[i] ^= equations[start];
				}
			}
			posList.push_back(pos);
			++start;
		}
	}

	assert((int) posList.size() == start);
	for (int i = 0; i < start; ++i) {
		int pos = posList[i];
		result[pos] = equations[i][SZ - 1];
	}

	// for (auto &cur : equations) {
	// 	for (int i = 0; i < 2 * N; ++i) {
	// 		cout << cur[i];
	// 	}
	// 	cout << ' ' << cur[SZ - 1] << endl;
	// }
	// cout << endl;

	// check
	for (auto &cur : equations) {
		bool x = cur[SZ - 1];
		for (int i = 0; i < 2 * N; ++i) {
			if (cur[i]) {
				x ^= result[i];
			}
		}
		if (x) return cout << "NO" << endl, 0;
	}

	cout << "YES" << endl;
	for (int i = 0; i < N; ++i) {
		cout << reverseMapping[result[2 * i] + (result[2 * i + 1] << 1)];
	}
	cout << endl;
	return 0;
}