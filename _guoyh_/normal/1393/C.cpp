# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int t, n;
int cnt;
int bx[NR];
int main(){
	scanf("%d", &t);
	while (t--){
		memset(bx, 0, sizeof(bx));
		cnt = 0;
		scanf("%d", &n);
		int mx = 0;
		for (int i = 1; i <= n; i++){
			int a;
			scanf("%d", &a);
			if (++bx[a] > mx){
				mx = bx[a];
				cnt = 1;
			} else if (bx[a] == mx) cnt++;
		}
		int ans = (n - mx - cnt + 1) / (mx - 1);
		printf("%d\n", ans);
	}
	return 0;
}