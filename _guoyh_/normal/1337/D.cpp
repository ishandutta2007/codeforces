# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int t;
int n[4], pos[4];
ll a[4][NR];
ll work(){
	ll mi = 6e18;
	for (int i = -1; i <= 0; i++){
		for (int j = -1; j <= 0; j++){
			for (int k = -1; k <= 0; k++){
				if (pos[0] + i < 0 || pos[1] + j < 0 || pos[2] + k < 0) continue;
				if (pos[0] + i >= n[0] || pos[1] + j >= n[1] || pos[2] + k >= n[2]) continue;
				mi = min(mi, (a[0][pos[0] + i] - a[1][pos[1] + j]) * (a[0][pos[0] + i] - a[1][pos[1] + j])
							+(a[1][pos[1] + j] - a[2][pos[2] + k]) * (a[1][pos[1] + j] - a[2][pos[2] + k])
							+(a[2][pos[2] + k] - a[0][pos[0] + i]) * (a[2][pos[2] + k] - a[0][pos[0] + i]));
			}
		}
	}
	return mi;
}
int main(){
	scanf("%d", &t);
	while (t--){
		ll ans = 6e18;
		for (int i = 0; i < 3; i++) scanf("%d", n + i);
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < n[i]; j++) scanf("%lld", a[i] + j);
			sort(a[i], a[i] + n[i]);
		}
		for (int i = 0; i < 3; i++){
			for (pos[i] = 0; pos[i] < n[i]; pos[i]++){
				int i2 = (i + 1) % 3, i3 = (i + 2) % 3;
				pos[i2] = lower_bound(a[i2], a[i2] + n[i2], a[i][pos[i]]) - a[i2];
				pos[i3] = lower_bound(a[i3], a[i3] + n[i3], a[i][pos[i]]) - a[i3];
				ans = min(ans, work());
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}