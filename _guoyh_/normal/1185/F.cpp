# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
const int MAXA = 9;
int n, m;
int a[MAXN], b[MAXN];
ll c[MAXN];
ll f[3][1 << MAXA];
pair <int, int> pre[3][1 << MAXA];
int pp[1 << MAXA];
ll ct[1 << MAXA];
int count(int s){
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if ((s & b[i]) == b[i]) cnt++;
	}
	return cnt;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		int x, y;
		scanf("%d", &x);
		for (int j = 1; j <= x; j++){
			scanf("%d", &y);
			b[i] |= (1 << (y - 1));
		}
	}
	for (int i = 1; i <= m; i++){
		int x, y;
		scanf("%lld%d", c + i, &x);
		for (int j = 1; j <= x; j++){
			scanf("%d", &y);
			a[i] |= (1 << (y - 1));
		}
	}
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for (int i = 0; i < m; i++){
		for (int s = 0; s < (1 << MAXA); s++){
			if (f[1][s] + c[i + 1] < f[2][s | a[i + 1]]){
				f[2][s | a[i + 1]] = f[1][s] + c[i + 1];
				pre[2][s | a[i + 1]] = make_pair(i + 1, s);
			}
			//printf("f %d %d %d %lld\n", i, 0, s, f[0][s]);
			//printf("f %d %d %d %lld\n", i, 1, s, f[1][s]);
			//printf("f %d %d %d %lld\n", i, 2, s, f[2][s]);
		}
		if (f[0][0] + c[i + 1] < f[1][a[i + 1]]){
			f[1][a[i + 1]] = f[0][0] + c[i + 1];
			pre[1][a[i + 1]] = make_pair(i + 1, 0);
		}
	}
	int id = -1;
	for (int i = 0; i < (1 << MAXA); i++){
		if (f[1][i] >= 1e18 && f[2][i] >= 1e18) continue;
		pp[i] = count(i);
		ct[i] = f[2][i];
		if (id == -1 || pp[i] > pp[id] || (pp[i] == pp[id] && f[2][i] < f[2][id])) id = i;
	}
	printf("%d %d\n", pre[1][pre[2][id].second].first, pre[2][id].first);
	return 0;
}