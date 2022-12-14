#include <iostream>
#include <queue>
#include <bitset>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;

const int maxn = 3000 + 100;

bool mark[maxn][maxn];

int main (){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;
	for (int i = 0; i <= n; i++) {
		mark[x][i] = 1;
		mark[i][y] = 1;
		mark[x + i][y + i] = 1;
		if (x > i and y > i)
			mark[x - i][y - i] = 1;
		if (x > i)
			mark[x - i][y + i] = 1;
		if (y > i)
			mark[x + i][y - i] = 1;
	}
	cin >> x >> y;
	int x1, y1;
	cin >> x1 >> y1;
	queue <pii> q;
	q.push ({x, y});
	mark[x][y] = 1;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		x = p.F, y = p.S;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (x + i > 0 and x + i <= n and y + j > 0 and y + j <= n and !mark[x + i][y + j]) {
					mark[x + i][y + j] = 1;
					q.push ({x + i, y + j});
				}
			}
		}
	}
	if (mark[x1][y1])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}