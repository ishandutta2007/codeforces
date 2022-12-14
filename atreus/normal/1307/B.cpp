#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;

int a[maxn];

void solve(){
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int p = *max_element(a, a + n);
	int answer = (x + p - 1) / p;
	if (answer == 1){
		int flag = 1;
		for (int i = 0; i < n; i++)
			if (a[i] == x)
				flag = 0;
		answer += flag;
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