#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;

void solve(){
	int n;
	cin >> n;
	int odd = 0, eve = 0;
	while (n --){
		int x;
		cin >> x;
		if (x & 1)
			odd ++;
		else
			eve ++;
	}
	if (odd & 1 or (odd > 0 and eve > 0))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		solve();
	}
}