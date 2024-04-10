#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <deque>
#include <unordered_map>
#include <fstream>
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
typedef pair<int,int> pii;
const int maxn = 7e5 + 10;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

int n, a[10];

int to[maxn], cap[maxn], pre[maxn], last[maxn], pos[maxn];
int cnt = 0;

int dis[maxn];

int dfs (int source, int sink, int untilnow) {
	if (source == sink)
		return untilnow;
	int now = 0;
	for (int &ed = pos[source]; ed != -1; ed = pre[ed]) {
		if (cap[ed] and dis[to[ed]] == dis[source] + 1) {
			int cur = dfs (to[ed], sink, min (cap[ed], untilnow));
			cap[ed] -= cur, cap[ed ^ 1] += cur, untilnow -= cur, now += cur;
			if (untilnow == 0)
				return now;
		}
	}
	return now;
}

bool bfs (int source, int sink) {
	memset (dis, -1, sizeof dis);
	dis[source] = 0;
	queue <int> Q;
	Q.push (source);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int ed = last[cur]; ed != -1; ed = pre[ed]) {
			if (cap[ed] and dis[to[ed]] == -1) {
				dis[to[ed]] = dis[cur] + 1;
				Q.push (to[ed]);
			}
		}
	}
	return dis[sink] != -1;
}

void addEdge (int fi, int se, int c) {
	to[cnt] = se, cap[cnt] = c, pre[cnt] = last[fi], last[fi] = cnt ++;
	to[cnt] = fi, cap[cnt] = 0, pre[cnt] = last[se], last[se] = cnt ++;
}

string Dorost (int x) {
	if (x == 1)
		return "S";
	if (x == 2)
		return "M";
	if (x == 3)
		return "L";
	if (x == 4)
		return "XL";
	if (x == 5)
		return "XXL";
	return "XXXL";
}

int sz (string s) {
	if (s == "S")
		return 1;
	if (s == "M")
		return 2;
	if (s == "L")
		return 3;
	if (s == "XL")
		return 4;
	if (s == "XXL")
		return 5;
	return 6;
}

int main () {
	ios_base::sync_with_stdio (false);
	memset (last, -1, sizeof last);
	for (int i = 1; i <= 6; i++)
		cin >> a[i];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		addEdge (0, i + 6, 1);
		string s;
		cin >> s;
		bool cur = 1;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == ',') {
				int Size = sz (s.substr (0, j));
				addEdge (i + 6, Size, 1);
				Size = sz (s.substr (j + 1, s.size() - j - 1));
				addEdge (i + 6, Size, 1);
				cur = 0;
			}
		}
		if (cur) {
			int Size = sz (s);
			addEdge (i + 6, Size, 1);
		}
	}
	for (int i = 1; i <= 6; i++)
		addEdge (i, n + 6 + 1, a[i]);
	
	int flow = 0, source = 0, sink = n + 6 + 1;
	while (bfs (source, sink)) {
		for (int i = 0; i <= n + 6 + 1; i++)
			pos[i] = last[i];
		flow += dfs (source, sink, inf);
	}
	
	if (flow != n)
		return cout << "NO" << endl, 0;
	
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++) {
		for (int ed = last[i + 6]; ed != -1; ed = pre[ed]) {
			if (to[ed] >= 1 and to[ed] <= 6 and cap[ed] == 0)
				cout << Dorost (to[ed]) << '\n';
		}
	}
}