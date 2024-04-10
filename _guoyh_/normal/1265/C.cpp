# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 400051;
int nm, t, n, nm2;
int p[NR];
int s[NR], b[NR];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		nm = -1;
		nm2 = -1;
		int ans = -1;
		memset(s, -1, sizeof(s));
		memset(b, -1, sizeof(b));
		for (int i = 1; i <= n; i++){
			scanf("%d", p + i);
			if (p[i] != p[1] && nm == -1) nm = i - 1;
		}
		if (nm * 3 + 2 > n / 2 || nm == -1){
			printf("0 0 0\n");
			continue;
		}
		for (int i = nm + 1; i <= n / 2; i++){
			int j = i;
			while (p[j + 1] == p[i]) j++;
			if (j > n / 2) break;
			if (j <= 2 * nm){
				i = j;
				continue;
			}
			nm2 = j;
			break;
		}
		if (nm2 + nm + 1 > n / 2 || nm2 == -1){
			printf("0 0 0\n");
			continue;
		}
		for (int i = nm2 + 1; i <= n / 2; i++){
			if (p[i + 1] != p[i] && i - nm2 > nm){
				ans = i;
			}
		}
		if (ans == -1) printf("0 0 0\n");
		else printf("%d %d %d\n", nm, nm2 - nm, ans - nm2);
	}
	return 0;
}