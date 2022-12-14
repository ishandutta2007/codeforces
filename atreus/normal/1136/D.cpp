#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
const int maxn = 3e5 + 10;

int a[maxn];
bool mark[maxn];
vector<int> g[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		g[v].push_back(u);
	}
	int answer = n, now = 1;
	mark[a[n]] = 1;
	for (int i = n - 1; i >= 1; i--){
		int cnt = 0;
		for (auto j : g[a[i]])
			cnt += mark[j];
		if (cnt == now)
			answer --;
		else{
			mark[a[i]] = 1;
			now ++;
		}
	}
	cout << n - answer << endl;
}