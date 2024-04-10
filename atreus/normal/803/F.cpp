#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int a[maxn], cnt[maxn], pw[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		for (int j = 1; j * j <= a[i]; j++){
			if (a[i] % j == 0){
				cnt[j] ++;
				if (j * j != a[i])
					cnt[a[i] / j] ++;
			}
		}
	}
	pw[0] = 1;
	for (int i = 1; i <= 100000; i++)
		pw[i] = 2 * pw[i - 1] % mod;
	int answer = 0;
	for (int i = 1; i <= 100000; i++){
		int x = i;
		int sign = 1;
		for (int j = 2; j * j <= x; j++){
			if (x % j == 0){
				int cnt = 0;
				while (x % j == 0){
					x /= j;
					cnt ++;
				}
				if (cnt > 1)
					sign = 0;
				sign *= -1;
			}
		}
		if (x > 1)
			sign *= -1;
		answer = (1ll * answer + sign * (pw[cnt[i]] - 1 + mod) + mod) % mod;
	}
	cout << answer << endl;
}