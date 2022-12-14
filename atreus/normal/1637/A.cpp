#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 10;
const ll mod = 998244353;

int a[maxn];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	bool sorted = true;
	for (int i = 1; i + 1 <= n; i++)
		if (a[i] > a[i + 1])
			sorted = false;
	if (sorted)
		cout << "NO\n";
	else
		cout << "YES\n";
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int tc;
	cin >> tc;
	while (tc --){
		solve();
	}
}