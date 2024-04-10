#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 2e5 + 5;
const ll inf = 1e18 + 10;

int a[maxn], b[maxn];
int mark[maxn];
vector<pair<int, int> > e;

void add_edge(int v, int u){
	e.push_back({v, u});
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, ka, kb;
	cin >> n >> m >> ka >> kb;
	for (int i = 0; i < ka; i++)
		cin >> a[i];
	for (int i = 0; i < kb; i++)
		cin >> b[i];
	if (ka > m - 1 or kb > n - 1)
		return cout << "No\n", 0;
	for (int i = ka; i < m - 1; i++)
		a[i] = a[i - 1];
	for (int i = kb; i < n - 1; i++)
		b[i] = b[i - 1];
	for (int i = 0; i < m - 1; i++)
		mark[a[i]] ++;
	for (int i = 0; i < n - 1; i++)
		mark[b[i]] ++;
	set<pair<int, int> > leaf;
	for (int i = 1; i <= n + m; i++)
		leaf.insert({mark[i], i});
	ka = 0, kb = 0;
	for (int i = 1; i <= n + m - 2; i++){
		int v = (*leaf.begin()).second;
		leaf.erase(leaf.begin());
		int u;
		if (v <= n)
			u = b[kb ++];
		else
			u = a[ka ++];
		add_edge(v, u);
		leaf.erase({mark[u], u});
		mark[u] --;
		leaf.insert({mark[u], u});
	}
	int v = (*leaf.begin()).second;
	leaf.erase(leaf.begin());
	int u = (*leaf.begin()).second;
	add_edge(v, u);
	cout << "YES\n";
	for (auto it : e)
		cout << it.first << " " << it.second << endl;
}