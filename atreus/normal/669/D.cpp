#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	ll lazy1 = 0, lazy2 = 0, lazy = 0, now = 0;
	while (q --){
		int t;
		cin >> t;
		if (t == 1){
			int x;
			cin >> x;
			lazy += x;
			if (x & 1)
				now ^= 1;
		}
		else{
			if (now == 0)
				lazy1 ++, lazy2 --;
			else
				lazy1 --, lazy2 ++;
			now ^= 1;
		}
	}
	lazy1 %= n, lazy2 %= n, lazy %= n;
	lazy1 = (lazy1 + n) % n;
	lazy2 = (lazy2 + n) % n;
	lazy = (lazy + n) % n;
	for (int i = 1; i <= n; i++){
		int now;
		if (i & 1)
			now = (i + lazy + lazy1) % n;
		else
			now = (i + lazy + lazy2) % n;
		if (now == 0)
			now = n;
		a[now] = i;
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " \n"[i == n];
}