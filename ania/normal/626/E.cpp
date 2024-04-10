#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

const int maxn = 200200;

int n;
int x[maxn];
long long suff[maxn];

struct frac {
	long long a;
	int b;
	
	frac(long long x=0, int y=1) {a=x; b=y;}
	
	bool operator<(frac x) {
		return a*x.b < x.a*b;
	}
};

frac f(int mid, int len) {
	long long sum = suff[n-len] + suff[mid-len] - suff[mid+1];
	sum -= 1LL * x[mid] * (2*len+1);
	return frac(sum,2*len+1);
}

frac bestv;
int bestmid, bestlen;

int main() {
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &x[i]);
	sort(x,x+n);
	for (int i = n-1; i >= 0; i--) suff[i] = suff[i+1] + x[i];
	FOR(m,n) {
		int lo = 0, hi = min(n-1-m, m);
		while (lo+5 < hi) {
			int m1 = (lo*2+hi)/3, m2 = (lo+hi*2)/3;
			frac v1 = f(m,m1), v2 = f(m,m2);
			if (v1<v2) lo=m1;
			else hi=m2;
		}
		for (int i = lo; i <= hi; i++) {
			frac v = f(m,i);
			if (bestv<v) {
				bestv=v;
				bestmid=m;
				bestlen = i;
			}
		}
	}
	//printf("val = %lf, %d %d\n", bestv, bestmid, bestlen);
	printf("%d\n", bestlen*2+1);
	for (int i = bestmid-bestlen; i <= bestmid; i++) printf("%d ", x[i]);
	for (int i = n-bestlen; i < n; i++) printf("%d ", x[i]);
	printf("\n");
	return 0;
}