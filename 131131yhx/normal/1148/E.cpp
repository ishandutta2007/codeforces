#include <bits/stdc++.h>
#define M 600010

using namespace std;

typedef long long ll;

struct node {
	int a, id;
	node() {}
	node(int _1, int _3) {a = _1, id = _3;}
	bool operator < (const node& X) const {return a < X.a;}
};

int n;

node X[600010];

ll B[600010], PrA[M], PrB[M], SuA[M], SuB[M];

void GG() {
	puts("NO");
	exit(0);
}

int Det[600010];

int Ans[3000010][3];

int anst = 0;

void add(int a, int b, int c) {
	anst++;
	Ans[anst][0] = a;
	Ans[anst][1] = b;
	Ans[anst][2] = c;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &X[i].a);
	for(int i = 1; i <= n; i++) scanf("%lld", &B[i]), X[i].id = i;
	sort(X + 1, X + n + 1);
	sort(B + 1, B + n + 1);
	ll tota = 0, totb = 0;
	for(int i = 1; i <= n; i++) {
		tota += X[i].a;
		totb += B[i];
		PrA[i] = tota;
		PrB[i] = totb;
		if(tota > totb) {
			GG();
		}
	}
	tota = 0, totb = 0;
	for(int i = n; i >= 1; i--) {
		tota += X[i].a;
		totb += B[i];
		SuA[i] = tota;
		SuB[i] = totb;
		if(tota < totb) GG();
	}  
	if(tota != totb) GG();
	int t1 = 1;
	for(int i = 1; i <= n; i++) Det[i] = B[i] - X[i].a;
	for(int i = 1; i <= n; i++) if(Det[i] < 0) {
		int res = -Det[i];
		Det[i] = 0;
		while(res) {
			while(Det[t1] == 0) t1++;
			if(Det[t1] < res) {
				add(X[t1].id, X[i].id, Det[t1]);
				res -= Det[t1];
				t1++;
			} else {
				add(X[t1].id, X[i].id, res);
				Det[t1] -= res;
				break;
			}
		}
	}
	puts("YES");
	printf("%d\n", anst);
	for(int i = 1; i <= anst; i++) printf("%d %d %d\n", Ans[i][0], Ans[i][1], Ans[i][2]);
	return 0;
}