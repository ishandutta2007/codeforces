#include <bits/stdc++.h>
#define M 600010

using namespace std;

typedef long long ll;

int n, q;

int A[M];

int F[19][19];

struct node {
	int l, r, id, ans;
	bool operator < (const node& X) const {return l > X.l;}
};

int Ans[300010];

node X[300010];

void cmin(int &x, int y) {if(x > y) x = y;}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= q; i++) scanf("%d%d", &X[i].l, &X[i].r), X[i].id = i, X[i].ans = 0;
	sort(X + 1, X + q + 1);
	int t = 1;
	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++) F[i][j] = n + 1;
	for(int i = 0; i < 19; i++) F[i][i] = 0;
	for(int i = n; i >= 1; i--) {
		for(int j = 0; j < 19; j++) if((A[i] >> j & 1)) 
			for(int k = j + 1; k < 19; k++) if((A[i] >> k & 1)) {
				F[j][k] = i;
				F[k][j] = i;
			}
		for(int k = 0; k < 19; k++) {
			int mn = n + 1;
			for(int j = 0; j < 19; j++) if(j != k && (A[i] >> j & 1)) mn = min(mn, F[j][k]);
			for(int j = 0; j < 19; j++) if(j != k && (A[i] >> j & 1)) F[j][k] = mn;
		}
		while(t != q + 1 && X[t].l == i) {
			int a = X[t].l, b = X[t].r;
			for(int j = 0; j < 19; j++) if((A[a] >> j & 1)) {
				for(int k = 0; k < 19; k++) if(A[b] >> k & 1) {
					if(F[j][k] <= b) {X[t].ans = 1; break;}
				}
				if(X[t].ans == 1) break;
			}
			t++;
		}
	}
	for(int i = 1; i <= q; i++) Ans[X[i].id] = X[i].ans;
	for(int i = 1; i <= q; i++) puts(Ans[i] ? "Shi" : "Fou");
	return 0;
}