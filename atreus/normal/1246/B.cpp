#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10;
const int mod = 1e6 + 7;
const int base = 31;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		int me = 1;
		for (int j = 2; j * j <= x; j++){
			if (x % j == 0){
				int cnt = 0;
				while (x % j == 0){
					x /= j;
					cnt ++;
				}
				cnt %= k;
				while (cnt --){
					me *= j;
				}
			}
		}
		if (x > 1)
			me *= x;
		a[me] ++;
	}
	ll answer = 0;
	for (int i = 1; i <= 100000; i++){
		int x = i;
		int me = 1;
		for (int j = 2; me != -1 and j * j <= x; j++){
			if (x % j == 0){
				int cnt = 0;
				while (x % j == 0){
					x /= j;
					cnt ++;
				}
				cnt %= k;
				cnt = k - cnt;
				while (cnt --){
					me *= j;
					if (me > 100000){
						me = -1;
						break;
					}
				}
			}
		}
		if (x > 1){
			for (int j = 0; me != -1 and j < k - 1; j++){
				me *= x;
				if (me > 100000)
					me = -1;
			}
		}
		if (me == -1)
			continue;
		if (a[i] > 0 and i <= me){
			if (i == me)
				answer += 1ll * a[i] * (a[i] - 1) / 2;
			else
				answer += 1ll * a[i] * a[me];
		}
	}
	cout << answer << endl;
}