#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2000 + 10;
int n, m;
int h[maxn * maxn];
bool mark[maxn * maxn];
string s[maxn];
vector<pair<int, int> > g[maxn * maxn];

int id(int x, int y){
	return x * m + y;
}

void add_edge(int v, int u, int w){
	g[v].push_back({u, w});
	g[u].push_back({v, w});
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	int r, c;
	cin >> r >> c;
	r --, c --;
	int p, q;
	cin >> p >> q;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m - 1; j++)
			if (s[i][j] == '.' and s[i][j + 1] == '.')
				add_edge(id(i, j), id(i, j + 1), 1);
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '.' and s[i + 1][j] == '.')
				add_edge(id(i, j), id(i + 1, j), 0);
	memset(h, -1, sizeof h);
	deque<int> deq;
	deq.push_back(id(r, c));
	h[id(r, c)] = 0;
	int cnt = 0;
	while (!deq.empty()){
		int now = deq.front();
		deq.pop_front();
		if (mark[now])
			continue;
		int x = now / m, y = now % m;
		int k = h[now] - abs(c - y);
		k /= 2;
		if (y <= c){
			if (p >= k + abs(c - y) and q >= k)
				cnt ++;
		}
		else{
			if (q >= k + abs(c - y) and p >= k)
				cnt ++;
		}
		mark[now] = 1;
		for (auto edge : g[now]){
			int u = edge.first, w = edge.second;
			if (h[u] == -1 or h[u] > h[now] + w){
				h[u] = h[now] + w;
				if (w == 0)
					deq.push_front(u);
				else
					deq.push_back(u);
			}
		}
	}
	cout << cnt << endl;
}