# include <bits/stdc++.h>
# define ll long long
# define fst first
# define snd second
using namespace std;
const int MAXN = 400051;
const int MAXB = 505;
int n, m, b, cnt;
ll px[MAXN], py[MAXN];
int r[MAXB][MAXB];
int d[MAXN];
int st[MAXN];
void add(int nw, int id){
	st[id] = nw;
	if (px[id] + py[id] > b){
		for (int i = nw; i <= m; i += px[id] + py[id]){
			if (i + px[id] <= m) d[i + px[id]]++;
			if (i + px[id] + py[id] <= m) d[i + px[id] + py[id]]--;
		}
	} else {
		ll T = px[id] + py[id];
		r[T][(nw + px[id]) % T]++;
		r[T][nw % T]--;
		cnt++;
	}
}
void del(int nw, int id){
	if (px[id] + py[id] > b){
		for (int i = st[id]; i <= m; i += px[id] + py[id]){
			if (i + px[id] <= m) d[i + px[id]]--;
			if (i + px[id] + py[id] <= m) d[i + px[id] + py[id]]++;
		}
	} else {
		int T = px[id] + py[id];
		r[T][(st[id] + px[id]) % T]--;
		r[T][st[id] % T]++;
	}
	if ((nw - st[id]) % (px[id] + py[id]) > px[id] || (nw - st[id]) % (px[id] + py[id]) == 0) cnt--;
}
int main(){
	scanf("%d%d", &n, &m);
	b = int(sqrt(m));
	for (int i = 1; i <= n; i++) scanf("%lld%lld", px + i, py + i);
	for (int i = 1; i <= m; i++){
		int op, u;
		scanf("%d%d", &op, &u);
		if (op == 1){
			add(i, u);
			st[u] = i;
		}
		else del(i, u);
		cnt += d[i];
		for (int j = 1; j <= b; j++) cnt += r[j][i % j];
		printf("%d\n", cnt);
	}
	return 0;
}