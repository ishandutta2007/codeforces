#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7, maxn = 1000 + 100;
bool visited[maxn];
int que = 1;
vector <pair <int, pair <int, char> > > v[maxn];
pair <int, char> p[maxn];
vector <pair <int, char> > ans;

void dfs (int u, int edg, char direc){
	for (auto w : v[u]){
		if (!visited[w.S.F]){
			visited[w.S.F] = 1;
			dfs (w.F, w.S.F, w.S.S);
		}
	}
	if (edg == -1)
		return;
	p[edg] = MP(que, direc);
	ans.PB(MP(edg, direc));
	que ++;
}

int main(){ 
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(MP(w, MP(i, '-')));
		v[w].PB(MP(u, MP(i, '+')));
	}
	int cnt = 0, ver = -1;
	for (int i = 0; i <= 6; i++)
		if (v[i].size() % 2 == 1)
			cnt ++;
	if (cnt > 2)
		return cout << "No solution" << endl, 0;
	for (int i = 0; i <= 6; i++){
		if (v[i].size() > 0){
			ver = i;
			if (v[i].size() % 2 == 1)
				break;
		}
	}
	dfs (ver, -1, -1);
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			return cout << "No solution" << endl, 0;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].F << " " << ans[i].S << endl;
//	for (int i = 1; i <= n; i++)
//		cout << p[i].F << " " << p[i].S << endl;
}