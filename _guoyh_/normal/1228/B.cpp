# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const ll PR = 1000000007;
int h, w, cnt;
int r[1050], c[1050];
int flag[1050][1050];
int pwr(ll x, ll y){
	ll ans = 1;
	while (y){
		if (y & 1) ans = ans * x % PR;
		x = x * x % PR;
		y >>= 1;
	}
	return (int)(ans % PR);
}
int main(){
	scanf("%d%d", &h, &w);
	for (int i = 1; i <= h; i++){
		scanf("%d", r + i);
		for (int j = 1; j <= r[i]; j++) flag[i][j] = 1;
		flag[i][r[i] + 1] = -1;
	}
	for (int i = 1; i <= w; i++){
		scanf("%d", c + i);
		for (int j = 1; j <= c[i]; j++){
			if (flag[j][i] == -1){
				printf("0\n");
				return 0;
			}
			flag[j][i] = 1;
		}
		if (flag[c[i] + 1][i] == 1){
			printf("0\n");
			return 0;
		}
		flag[c[i] + 1][i] = -1;
	}
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			if (flag[i][j] == 0) cnt++;
	printf("%d\n", pwr(2, cnt));
	return 0;
}