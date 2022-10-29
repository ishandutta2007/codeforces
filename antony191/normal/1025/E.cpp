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

int n, m;
int mx(int x, int y, int i) {
	return x + abs(y - i);
}

struct an {
	int x1, y1, x2, y2;
};

void sorti(vector<pair<int, int>> & cub, vector<pair<int, int>> & pos, vector<an> & ans, vector<int> & srt) {
	int l = 0;
	vector<int> a(n, -1);
	for (int i = 0; i < m; ++i)
		if (cub[i].first < 1)
			a[cub[i].second] = i;
	for (int i = 0; i < n; ++i) {
		if (a[i] == -1) continue;
		if (a[i] != srt[l]) {
			ans.push_back(an{ cub[srt[l]].first, cub[srt[l]].second, cub[srt[l]].first + 1, cub[srt[l]].second });
			a[cub[srt[l]].second] = -1;
			cub[srt[l]].first++;
			for (int j = cub[srt[l]].second - 1; j >= i; --j) {
				if (a[j] >= 0) {
					ans.push_back(an{ cub[a[j]].first, cub[a[j]].second, cub[a[j]].first, cub[a[j]].second + 1 });
					cub[a[j]].second++;
					a[j + 1] = a[j];
					a[j] = -1;
				}
			}
			while (cub[srt[l]].second > i) {
				ans.push_back(an{ cub[srt[l]].first, cub[srt[l]].second, cub[srt[l]].first, cub[srt[l]].second - 1 });
				cub[srt[l]].second--;
			}
			ans.push_back(an{ cub[srt[l]].first, cub[srt[l]].second, cub[srt[l]].first - 1, cub[srt[l]].second });
			cub[srt[l]].first--;
			a[i] = srt[l];
		}
		l++;
	}
}

void stav1(vector<pair<int, int>> & cub, vector<pair<int, int>> & pos, vector<an> & ans) {
	for (int j = 0; j < m; ++j)
		if (pos[j].first == 1) {
			ans.push_back(an{ cub[j].first, cub[j].second, cub[j].first + 1, cub[j].second });
			cub[j].first++;
		}
	vector<int> a(n, -1), b(n, -1);
	for (int j = 0; j < m; ++j)
		if (cub[j].first == 1)
			a[cub[j].second] = j;
	for (int j = 0; j < m; ++j)
		if (pos[j].first == 1)
			b[pos[j].second] = j;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == -1) continue;
		while (cub[a[i]].second < pos[a[i]].second) {
			ans.push_back(an{ cub[a[i]].first, cub[a[i]].second, cub[a[i]].first, cub[a[i]].second + 1 });
			cub[a[i]].second++;
		}
		if (cub[a[i]].second != i) {
			a[cub[a[i]].second] = a[i];
			a[i] = -1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] == -1) continue;
		while (cub[a[i]].second > pos[a[i]].second) {
			ans.push_back(an{ cub[a[i]].first, cub[a[i]].second, cub[a[i]].first, cub[a[i]].second - 1 });
			cub[a[i]].second--;
		}
		if (cub[a[i]].second != i) {
			a[cub[a[i]].second] = a[i];
			a[i] = -1;
		}
	}
}

void stav0(vector<pair<int, int>> & cub, vector<pair<int, int>> & pos, vector<an> & ans) {
	vector<int> a(n, -1), b(n, -1);
	for (int j = 0; j < m; ++j)
		if (cub[j].first == 0)
			a[cub[j].second] = j;
	for (int j = 0; j < m; ++j)
		if (pos[j].first == 0)
			b[pos[j].second] = j;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == -1) continue;
		while (cub[a[i]].second < pos[a[i]].second) {
			ans.push_back(an{ cub[a[i]].first, cub[a[i]].second, cub[a[i]].first, cub[a[i]].second + 1 });
			cub[a[i]].second++;
		}
		if (cub[a[i]].second != i) {
			a[cub[a[i]].second] = a[i];
			a[i] = -1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] == -1) continue;
		while (cub[a[i]].second > pos[a[i]].second) {
			ans.push_back(an{ cub[a[i]].first, cub[a[i]].second, cub[a[i]].first, cub[a[i]].second - 1 });
			cub[a[i]].second--;
		}
		if (cub[a[i]].second != i) {
			a[cub[a[i]].second] = a[i];
			a[i] = -1;
		}
	}
}
int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vector<pair<int, int>> cub(m), pos(m);
	for (int i = 0; i < m; ++i) {
		cin >> cub[i].first >> cub[i].second;
		cub[i].first--; cub[i].second--;
	}
	for (int i = 0; i < m; ++i) {
		cin >> pos[i].first >> pos[i].second;
		pos[i].first--; pos[i].second--;
	}
	vector<bool> used(m, false);
	vector<an> ans;
	for (int i = 0; i < m; ++i) {
		int mn = -1;
		for (int j = 0; j < m; ++j) {
			if (!used[j]) {
				if (mn == -1 || mx(cub[j].first, cub[j].second, i) < 
					mx(cub[mn].first, cub[mn].second, i))
					mn = j;
			}
		}
		used[mn] = 1;
		while (cub[mn].second != i) {
			if (i < cub[mn].second) {
				ans.push_back(an{ cub[mn].first, cub[mn].second, cub[mn].first, cub[mn].second - 1 });
				cub[mn].second--;
			}
			else {
				ans.push_back(an{ cub[mn].first, cub[mn].second, cub[mn].first, cub[mn].second + 1 });
				cub[mn].second++;
			}
		}
		while (cub[mn].first > 0) {
			ans.push_back(an{ cub[mn].first, cub[mn].second, cub[mn].first - 1, cub[mn].second });
			cub[mn].first--;
		}
	}
	used.assign(n, false);
	int i = 0;
	for (; i < m; ++i) {
		int mx = -1;
		for (int j = 0; j < m; ++j)
			if (!used[j] && (mx == -1 || pos[mx].first < pos[j].first))
				mx = j;
		if (pos[mx].first < 2)
			break;
		ans.push_back(an{ cub[mx].first, cub[mx].second, cub[mx].first + 1, cub[mx].second });
		cub[mx].first++;
		while (cub[mx].second != pos[mx].second) {
			if (pos[mx].second < cub[mx].second) {
				ans.push_back(an{ cub[mx].first, cub[mx].second, cub[mx].first, cub[mx].second - 1 });
				cub[mx].second--;
			}
			else {
				ans.push_back(an{ cub[mx].first, cub[mx].second, cub[mx].first, cub[mx].second + 1 });
				cub[mx].second++;
			}
		}
		while (cub[mx].first < pos[mx].first) {
			ans.push_back(an{ cub[mx].first, cub[mx].second, cub[mx].first + 1, cub[mx].second });
			cub[mx].first++;
		}
		used[mx] = 1;
	}
	if (i < m) {
		i = m - i;
		vector<int> a(n, -1);
		vector<int> srt;
		int cnt = 0;
		for (int j = 0; j < m; ++j)
			if (pos[j].first == 0) {
				cnt++; a[pos[j].second] = j;
			}
		for (int j = 0; j < n; ++j)
			if (a[j] + 1) srt.push_back(a[j]);
		vector<int> b(n, -1);
		for (int j = 0; j < m; ++j)
			if (pos[j].first == 1)
				b[pos[j].second] = j;
		for (int j = 0; j < n; ++j)
			if (b[j] + 1) srt.push_back(b[j]);
		sorti(cub, pos, ans, srt);
		for (int j = 0; j < m; ++j)
			if (!used[j])
				a[cub[j].second] = j;
		stav1(cub, pos, ans);
		stav0(cub, pos, ans);
	}
	cout << (int)ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].x1 + 1 << ' ' << ans[i].y1 + 1 
			<< ' ' << ans[i].x2 + 1 << ' ' << ans[i].y2 + 1 << '\n';
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}