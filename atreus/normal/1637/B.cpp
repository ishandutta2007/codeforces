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
	int answer = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			for (int k = i; k <= j; k++)
				answer += 1 + (a[k] == 0);
	cout << answer << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int tc;
	cin >> tc;
	while (tc --){
		solve();
	}
}