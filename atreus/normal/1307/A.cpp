#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

void solve(){
	int n, d;
	cin >> n >> d;
	int answer = 0;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (i == 0){
			answer += x;
			continue;
		}
		int t = min(x, d / i);
		answer += t;
		d -= t * i;
	}
	cout << answer << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		solve();
	}
}