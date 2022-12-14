#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 3000 + 10;
const int mod = 998244353;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int a, b, n;
		cin >> a >> b >> n;
		int cnt = 0;
		while (max(a, b) <= n){
			if (a > b)
				swap(a, b);
			a += b;
			cnt ++;
		}
		cout << cnt << '\n';
	}
}