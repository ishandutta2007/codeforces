#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define N_ 100010
#define Q_ 250010
#define M_ 150010
int n, m, Q, SZ, C[N_], cnt, st[N_], beg[N_], Next[(M_ + Q_) * 2];
bool v[N_];
struct Query{
	int a, b;
	char ck;
}w[Q_];
struct Edge{
	int a, b;
	bool ck;
	bool operator <(const Edge &p)const{
		return a != p.a ? a < p.a : b < p.b;
	}
}Ed[(M_ + Q_) * 2];
bool on[N_];
void UDT(int a, int b){
	int B = st[a], E = st[a+1] - 1, M;
	while (B <= E){
		M = (B + E) >> 1;
		if (Ed[M].b == b)break;
		if (Ed[M].b > b) E = M - 1;
		else B = M + 1;
	}
	Ed[M].ck = !Ed[M].ck;
	if (v[a] && on[b]){
		if (Ed[M].ck)C[a]++;
		else C[a]--;
	}
}
int main()
{
	int i, j, o, cnt = 0, a, b, pv, be, ed, x, t;
	char pp[2];
	scanf("%d%d%d%d", &n, &m, &Q, &o);
	while (o--){
		scanf("%d", &i);
		on[i] = true;
	}
	for (i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		Ed[cnt].a = a, Ed[cnt].b = b, Ed[cnt++].ck = true;
		Ed[cnt].a = b, Ed[cnt].b = a, Ed[cnt++].ck = true;
	}
	for (i = 1; i*i <= Q; i++);
	SZ = i * 2;
	for (i = 0; i < Q; i++){
		scanf("%s%d", &pp, &w[i].a);
		w[i].ck = pp[0];
		if (w[i].ck == 'A' || w[i].ck == 'D'){
			scanf("%d", &w[i].b);
			Ed[cnt].a = w[i].a, Ed[cnt++].b = w[i].b;
			Ed[cnt].a = w[i].b, Ed[cnt++].b = w[i].a;
		}
	}
	sort(Ed, Ed + cnt);
	o = 0, pv = 0;
	for (i = 0; i < cnt; i++){
		if (!i || Ed[i].a != Ed[i - 1].a || Ed[i].b != Ed[i - 1].b){
			if (!i || Ed[i].a != Ed[i - 1].a){
				while (pv != Ed[i].a){
					pv++;
					st[pv] = o;
				}
			}
			Ed[o++] = Ed[i];
		}
		else if (Ed[i].ck)Ed[o - 1].ck = true;
	}
	while (pv != n + 1){
		pv++; st[pv] = o;
	}
	be = 0;
	for (i = 1; i <= n; i++)beg[i] = -2;
	while (1){
		ed = be + SZ;
		if (ed > Q)ed = Q;
		cnt = 0;
		for (i = be; i < ed;i++){
			if (w[i].ck == 'C'){
				if (!v[w[i].a]){
					v[w[i].a] = true;
					C[w[i].a] = 0;
					for (j = st[w[i].a]; j < st[w[i].a + 1]; j++){
						if (Ed[j].ck && on[Ed[j].b])C[w[i].a]++;
					}
				}
			}
		}
		for (i = be; i < ed; i++){
			if (w[i].ck == 'O' || w[i].ck == 'F'){
				x = w[i].a;
				on[x] = !on[x];
				if (on[x]) a = 1;
				else a = -1;
				if (beg[x] == -2){
					for (j = st[x]; j != st[x + 1]; j++){
						if (v[Ed[j].b]){
							if(Ed[j].ck)C[Ed[j].b] += a;
							if (beg[x] == -2)beg[x] = j, t = j;
							else Next[t] = j, t = j;
						}
					}
					if (beg[x] == -2)beg[x] = -1;
					else Next[t] = -1;
				}
				else{
					t = beg[x];
					while (t != -1){
						if (Ed[t].ck)C[Ed[t].b] += a;
						t = Next[t];
					}
				}
			}
			else if(w[i].ck == 'D' || w[i].ck == 'A'){
				UDT(w[i].a, w[i].b);
				UDT(w[i].b, w[i].a);
			}
			else printf("%d\n", C[w[i].a]);
		}
		for (i = be; i < ed; i++){
			if (w[i].ck == 'C')v[w[i].a] = false;
			if (w[i].ck == 'O' || w[i].ck == 'F')beg[w[i].a] = -2;
		}
		if (ed == Q)break;
		be = ed;
	}
	return 0;
}