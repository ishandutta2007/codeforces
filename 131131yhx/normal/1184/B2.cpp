#include <bits/stdc++.h>
#define Inf 1e9
#define M 4000010

using namespace std;

typedef long long ll;

int Head[M], Next[M], Go[M], Cnt = 0;

struct flow {
	int Head[50010], Next[M], Go[M], Val[M], Cnt;
	int Am[50010], H[50010], Pr[50010], Fl[50010], Nw[50010];
	flow() {Cnt = 1, memset(Head, 0, sizeof Head);}
	void addedge(int a, int b, int c) {
		Go[++Cnt] = b;
		Next[Cnt] = Head[a];
		Head[a] = Cnt;
		Val[Cnt] = c;
	}
	int getflow(int S, int TT, int tot) {
		int x = S;
		int f = Inf;
		Am[0] = tot;
		ll ans = 0;
		while(H[x] <= tot) {
			if(!Nw[x]) Nw[x] = Head[x];
			int flag = 0;
			for(int &T = Nw[x]; T; T = Next[T])
				if(Val[T] && H[Go[T]] == H[x] - 1) {
					flag = 1, Pr[Go[T]] = T ^ 1;
					Fl[x] = f, f = min(f, Val[T]);
					x = Go[T];
					if(x == TT) {
						ans += f;
						while(x != S) Val[Pr[x]] += f, Val[Pr[x] ^ 1] -= f, x = Go[Pr[x]];
						f = Inf; //!!!
					}
					break; //!!!
				}
			if(!flag) {
				int mn = tot;
				for(int T = Head[x]; T; T = Next[T]) if(Val[T] && H[Go[T]] < mn) mn = H[Go[T]], Nw[x] = T;
				if(!--Am[H[x]]) break;
				Am[H[x] = mn + 1]++;
				if(x != S) {
					x = Go[Pr[x]];
					f = Fl[x];
				}
			}
		}
		return ans;
	}
} qwq;

int n, m, Dis[105][105], XA[50010], AA[50010], FA[50010], XB[50010], DB[50010];

int main() {
	scanf("%d%d", &n, &m);
	memset(Dis, 63, sizeof Dis);
	for(int i = 1; i <= n; i++) Dis[i][i] = 0;
	for(int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		Dis[a][b] = 1, Dis[b][a] = 1;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++) Dis[j][k] = min(Dis[j][k], Dis[j][i] + Dis[i][k]);
	int s, b, k, h;
	scanf("%d%d%d%d", &s, &b, &k, &h);
	for(int i = 1; i <= s; i++) scanf("%d%d%d", &XA[i], &AA[i], &FA[i]);
	for(int i = 1; i <= b; i++) scanf("%d%d", &XB[i], &DB[i]);
	for(int i = 1; i <= s; i++)
		for(int j = 1; j <= b; j++) if(AA[i] >= DB[j] && FA[i] >= Dis[XA[i]][XB[j]]) qwq.addedge(1 + i, 1 + s + j, Inf), qwq.addedge(1 + s + j, 1 + i, 0);
	for(int i = 1; i <= s; i++) qwq.addedge(1, 1 + i, 1), qwq.addedge(1 + i, 1, 0);
	for(int i = 1; i <= b; i++) qwq.addedge(1 + s + i, 2 + s + b, 1), qwq.addedge(2 + s + b, 1 + s + i, 0);
	int ovo = qwq.getflow(1, 2 + s + b, 2 + s + b);
	ll ans = 1e18;
	for(int i = 0; i <= s; i++) ans = min(ans, ll(i) * h + ll(min(ovo, s - i)) * k);
	printf("%lld\n", ans);
	return 0;
}