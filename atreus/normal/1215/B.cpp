#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

int a[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	a[0] = 0;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if (x > 0)
			a[i] = a[i - 1];
		else
			a[i] = a[i - 1] ^ 1;
	}
	ll answer = 1ll * n * (n + 1) / 2;
	ll num = 0;
	ll cnt0 = 1, cnt1 = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] == 1){
			num += cnt0;
			cnt1 ++;
		}
		else{
			num += cnt1;
			cnt0 ++;
		}
	}
	cout << num << " " << answer - num << endl;
}