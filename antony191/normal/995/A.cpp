#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>

#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi1;
typedef vector<vi1> vi2;
typedef vector<ll> vll1;
typedef vector<vll1> vll2;

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()

int n;

struct an {
	int i, r, c;
};

pair<int, int> nex(int x, int y) {
	if (x == 0)
		return (y < n - 1 ? pair<int, int>{x, y + 1} : pair<int, int>{x + 1, y});
	return (y > 0 ? pair<int, int>{x, y - 1} : pair<int, int>{ x - 1, y });
}

vector<int> tab[4], pos;
vector<an> ans;

void go1(int r, int l) {
	for (int i = r; i >= l; --i) {
		if (tab[1][i]) {
			auto tmp = nex(0, i);
			pos[tab[1][i] - 1] = tmp.first * n + tmp.second;
			ans.push_back(an{ tab[1][i], tmp.first + 2, tmp.second + 1 });
			tab[tmp.first + 1][tmp.second] = tab[1][i];
			tab[1][i] = 0;
		}
	}
}

void go2(int l, int r) {
	for (int i = l; i <= r; ++i) {
		if (tab[2][i]) {
			auto tmp = nex(1, i);
			pos[tab[2][i] - 1] = tmp.first * n + tmp.second;
			ans.push_back(an{ tab[2][i], tmp.first + 2, tmp.second + 1 });
			tab[tmp.first + 1][tmp.second] = tab[2][i];
			tab[2][i] = 0;
		}
	}
}
int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin >> n >> k;
	for (int i = 0; i < 4; ++i) tab[i].resize(n);
	vector<int> apos(k);
	pos.resize(k);
	int cur = k, lef = -1;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> tab[i][j];
			if (i >= 1 && i <= 2 && tab[i][j] > 0)
				pos[tab[i][j] - 1] = j + n * (i - 1);
			if (i >= 1 && i <= 2 && tab[i][j] == 0 && lef == -1)
				lef = j + n * (i - 1);
			if ((i == 0 || i == 3) && tab[i][j] > 0)
				apos[tab[i][j] - 1] = j + n * (i == 0 ? 0 : 1);
		}
	vector<int> used(k, 0);
	while (cur > 0) {
		for (int i = 0; i < k; ++i)
			if (!used[i] && apos[i] == pos[i]) {
				cur--;
				ans.push_back({ i + 1, (apos[i] / n) * 3 + 1, apos[i] % n + 1 });
				tab[pos[i] / n + 1][pos[i] % n] = 0;
				if (lef == -1) lef = pos[i];
				used[i] = 1;
			}
		if (lef == -1)
			return cout << -1, 0;
		if (lef < n) {
			go1(lef - 1, 0);
			go2(0, n - 1);
			go1(n - 1, lef);
		}
		else {
			go2(lef - n + 1, n - 1);
			go1(n - 1, 0);
			go2(0, lef - n);
		}
		auto tmp = nex(lef / n, lef % n);
		lef = tmp.first * n + tmp.second;
	}
	cout << (int)ans.size() << '\n';
	for (int i = 0; i < (int)ans.size(); ++i)
		cout << ans[i].i << ' ' << ans[i].r << ' ' << ans[i].c << '\n';
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}