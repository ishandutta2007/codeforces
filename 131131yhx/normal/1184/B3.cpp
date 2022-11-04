#include <bits/stdc++.h>
#define Inf 1e18
#define M 2000010
#define PLL pair <ll, ll>
#define x first
#define y second

using namespace std;

typedef long long ll;

int Head[M], Next[M], Go[M], Cnt = 0;

struct flow {
	int Head[250010], Next[M], Go[M], Cnt;
	ll Val[M], Fl[250010];
	int Am[250010], H[250010], Pr[250010], Nw[250010];
	flow() {Cnt = 1, memset(Head, 0, sizeof Head);}
	void addedge(int a, int b, ll c) {
		Go[++Cnt] = b;
		Next[Cnt] = Head[a];
		Head[a] = Cnt;
		Val[Cnt] = c;
	}
	ll getflow(int S, int TT, int tot) {
		int x = S;
		ll f = Inf;
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

int n, m, Dis[105][105], XA[250010], AA[250010], FA[250010], PA[250010], XB[250010], DB[250010], GB[250010];

ll Ans[100010];

vector <PLL> V[105];

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
	int s, b, k;
	scanf("%d%d%d", &s, &b, &k);
	for(int i = 1; i <= s; i++) scanf("%d%d%d%d", &XA[i], &AA[i], &FA[i], &PA[i]);
	for(int i = 1; i <= n; i++) V[i].push_back(PLL(-1e18, -1e18));
	for(int i = 1; i <= b; i++) {
		int x, d, g;
		scanf("%d%d%d", &x, &d, &g);
		V[x].push_back(PLL(d, g));
	}
	for(int i = 1; i <= n; i++) {
		sort(V[i].begin(), V[i].end());
		for(int j = 1; j < V[i].size(); j++) V[i][j].y = max(V[i][j].y, V[i][j - 1].y);
	}
	for(int i = 1; i <= s; i++) {
		ll ans = -1e18; // notice PA
		for(int j = 1; j <= n; j++) if(Dis[XA[i]][j] <= FA[i])
			ans = max(ans, V[j][lower_bound(V[j].begin(), V[j].end(), PLL(AA[i] + 1, -Inf)) - V[j].begin() - 1].y);
		Ans[i] = ans - PA[i];
	}
	while(k--) {
		int s1, s2;
		scanf("%d%d", &s1, &s2);
		qwq.addedge(s1, s2, Inf);
		qwq.addedge(s2, s1, 0);
	}
	ll ans = 0;
	for(int i = 1; i <= s; i++) if(Ans[i] > 0) ans += Ans[i], qwq.addedge(s + 1, i, Ans[i]), qwq.addedge(i, s + 1, 0); else qwq.addedge(i, s + 2, -Ans[i]), qwq.addedge(s + 2, i, 0);
	printf("%lld\n", ans - qwq.getflow(s + 1, s + 2, s + 2));
	return 0;
}