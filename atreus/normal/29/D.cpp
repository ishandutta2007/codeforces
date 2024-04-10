#include <iostream>
#include <stack>
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
const int inf = 1e9 + 7, maxn = 500;
int n, k, mark[maxn], p[maxn], leaf[maxn];
vector <int> v[maxn], ans;
bool visited[maxn];
stack <int> s;

void dfs (){
	s.push(1);
	ans.PB(1);
	for (int i = 1; i <= k; i++){
		int u = leaf[i];
		while (u != -1){
			mark[u] = i;
			u = p[u];
		}
		u = s.top();
		while (mark[s.top()] != i){
			s.pop();
			ans.PB(s.top());
			u = s.top();
		}
		while (u != leaf[i]){
			for (auto w : v[u]){
				if (p[u] != w and mark[w] == i){
					u = w;
					s.push(w);
					ans.PB(w);
					break;
				}
			}
		}
	
	}
	while (!s.empty()){
		s.pop();
		if (!s.empty())
			ans.PB(s.top());
	}
}

void find_tree(int u, int dad){
	visited[u] = 1;
	p[u] = dad;
	for (auto w : v[u])
		if (!visited[w])
			find_tree (w, u);
}

int main(){ 
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(w);
		v[w].PB(u);
	}
	for (int i = 2; i <= n; i++)
		if (v[i].size() == 1)
			k ++;
	for (int i = 1; i <= k; i++)
		cin >> leaf[i];
	find_tree(1, -1);
	memset (visited, 0, sizeof visited);
	dfs ();
	if (ans.size() != 2 * n - 1)
		return cout << -1 << endl, 0;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}