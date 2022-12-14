// So What ?!!?!?!?!?!?!?!?!?
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn = 1e5 + 10;
const int maxm = 5e5 + 10;
 
bool mark[3 * maxn], edge[maxm];
int v[maxm], u[maxm];
 
void solve(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= 3 * n; i++)
		mark[i] = 0;
	for (int i = 1; i <= m; i++)
		edge[i] = 0;
	for (int i = 1; i <= m; i++)
		cin >> v[i] >> u[i];
	int cnt = 0;
	for (int i = 1; i <= m and cnt < n; i++){
		if (!mark[v[i]] and !mark[u[i]]){
			mark[v[i]] = mark[u[i]] = 1;
			cnt ++;
			edge[i] = 1;
		}
	}
	if (cnt == n){
		cout << "Matching\n";
		for (int i = 1; i <= m; i++)
			if (edge[i])
				cout << i << " ";
		cout << '\n';
		return;
	}
	cnt = 0;
	cout << "IndSet\n";
	for (int i = 1; i <= 3 * n and cnt < n; i++){
		if (!mark[i]){
			cout << i << " ";
			cnt ++;
		}
	}
	cout << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T --){
		solve();
	}
}