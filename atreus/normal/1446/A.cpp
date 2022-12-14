#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

ll w[maxn];

void solve(){
	ll n, W;
	cin >> n >> W;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	ll sum = 0;
	for (int i = 1; i <= n; i++){
		if (w[i] > W)
			continue;
		if ((W+1)/2 <= w[i]){
			cout << "1\n" << i << '\n';
			return;
		}
		sum += w[i];
	}
	if (sum < (W+1)/2){
		cout << -1 << '\n';
		return;
	}
	vector<int> Q;
	sum = 0;
	for (int i = 1; sum < (W+1)/2 and i <= n; i++){
		if (w[i] <= W){
			sum += w[i];
			Q.push_back(i);
		}
	}
	cout << Q.size() << '\n';
	for (auto it : Q)
		cout << it << " ";
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		solve();
	}
}