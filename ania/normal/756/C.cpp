#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

const int N = 100100;
const int B = 1<<17;
int sum[2*B+17], suf[2*B+13];
int n;
int t[N], p[N], x[N];

void add(int pos, int val) {
	pos += B;
	sum[pos] += val;
	suf[pos] += val;
	pos /= 2;
	while (pos) {
		sum[pos] += val;
		suf[pos] = max(suf[pos*2+1], sum[pos*2+1] + suf[pos*2]);
		pos /= 2;
	}
}

int get() {
	if (suf[1]<1) return -1;
	int pos = 1;
	int cur = 0;
	while (pos<B) {
		//printf("get %d %d\n", pos, cur);
		if (suf[pos*2+1]+cur>0) pos = 2*pos+1;
		else {
			cur += sum[pos*2+1];
			pos = 2*pos;
		}
	}
	return pos-B;
}

void test() {
	scanf("%d", &n);
	FOR(i,n) {
		scanf("%d%d", &p[i], &t[i]);
		if (t[i]==1) scanf("%d", &x[p[i]-1]);
		if (t[i]==0) {
			add(p[i], -1);
		} else {
			add(p[i], 1);
		}
		/*
		printf("p, t = %d %d\n", p[i], t[i]);
		FOR(q,4) {
			for (int w=1<<q; w<(1<<(q+1)); w++) printf("%d ", sum[w]);
			printf("\n");
		}
		FOR(q,4) {
			for (int w=1<<q; w<(1<<(q+1)); w++) printf("%d ", suf[w]);
			printf("\n");
		}*/
		int pos = get();
		if (pos != -1) printf("%d\n", x[pos-1]);
		else printf("-1\n");
	}
}

int main() {
	test();
	return 0;
}