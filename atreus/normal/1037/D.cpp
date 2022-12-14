#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 100;
const int inf = 1e9;
const int block = 400;

int p[maxn], a[maxn];
vector <int> v[maxn];

bool visited[maxn];

bool cmp (int fi, int se) {
	return p[fi] < p[se];
}

int main () { 
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u, w;
		cin >> u >> w;
		v[u].PB (w);
		v[w].PB (u);
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) 
		sort (v[i].begin(), v[i].end(), cmp);
	
	queue <int> q;
	q.push (1);
	visited[1] = 1;
	int idx = 1;
	while (!q.empty()) {
		int u = q.front();
		if (u != a[idx])
			return cout << "No" << endl, 0;
		idx ++;
		q.pop();
		for (auto w : v[u]) {
			if (!visited[w]) {
				visited[w] = 1;
				q.push (w);
			}
		}
	}
	cout << "Yes" << endl;
}