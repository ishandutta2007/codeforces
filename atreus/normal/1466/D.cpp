#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 1e5 + 10;
const ll mod = 1e9 + 7;

pair<int,int> w[maxn];
int adj[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		ll sum = 0;
		for (int i = 1; i <= n; i++){
			cin >> w[i].first;
			w[i].second = i;
			sum += w[i].first;
		}
		for (int i = 1; i <= n-1; i++){
			int v, u;
			cin >> v >> u;
			adj[v]++;
			adj[u]++;
		}
		sort(w+1,w+n+1,greater<pair<int,int>>());
		cout << sum << " ";
		for (int i = 1; i <= n; i++){
			int v = w[i].second;
			adj[v] --;
			while (adj[v] > 0){
				adj[v]--;
				sum += w[i].first;
				cout << sum << " ";
			}
		}
		cout << '\n';
	}
}