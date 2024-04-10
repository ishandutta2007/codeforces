# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
int n;
int p[MAXN];
int pre[MAXN], nxt[MAXN];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", p + i);
	int mx = -1, cnt = 0;
	for (int i = 1; i <= n; i++){
		if (i == 1 || p[i - 1] > p[i]) pre[i] = i;
		else pre[i] = pre[i - 1];
		if (i - pre[i] + 1 > mx){
			mx = i - pre[i] + 1;
			cnt = 1;
		} else if (i - pre[i] + 1 == mx) cnt++;
	}
	for (int i = n; i >= 1; i--){
		if (i == n || p[i + 1] > p[i]) nxt[i] = i;
		else nxt[i] = nxt[i + 1];
		if (nxt[i] - i + 1 > mx){
			mx = nxt[i] - i + 1;
			cnt = 1;
		} else if (nxt[i] - i + 1 == mx) cnt++;
	}
	if (mx % 2 == 0){
		printf("0\n");
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		if (i - pre[i] + 1 != mx || nxt[i] - i + 1 != mx) continue;
		int nw = cnt - 2;
		if (nw <= 0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}//