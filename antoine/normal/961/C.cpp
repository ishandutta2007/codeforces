#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <stack>

using namespace std;
typedef long long ll;

int n;
struct Board {
	int id;
	vector<string> * data;
	Board() {
		static int idGen = 0;
		id = idGen++;
		data = new vector<string>(n);
		for (int i = 0; i < n; ++i)
			cin >> (*data)[i];
	}
	int f(int p) {
		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				res += (i & 1) ^ (j & 1) ^ ((*data)[i][j] - '0') ^ p;
		return res;
	}
	bool operator<(const Board &other) const {
		return id < other.id;
	}
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<Board> v(4);
	sort(v.begin(), v.end());
	int ans = 1e9;
	do {
		ans = min(ans, v[0].f(0) + v[1].f(0) + v[2].f(1) + v[3].f(1));
	} while (next_permutation(v.begin(), v.end()));
	cout << ans;
	return 0;
}