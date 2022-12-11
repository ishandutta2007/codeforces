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

ll q[maxn], res[maxn];
int qbeg, qend, r;
int n,b;
ll curtime;

int main() {
	scanf("%d%d", &n, &b);
	FOR(i,n) {
		int t,d;
		scanf("%d%d", &t, &d);
		while (qend > qbeg && curtime+q[qbeg] <= t) {
			while (res[r]==-1) r++;
			curtime += q[qbeg];
			qbeg++;
			res[r] = curtime;
			r++;
		}
		if (qend > qbeg+b) {
			res[i] = -1;
		} else {
			if (qbeg==qend) curtime = t;
			q[qend] = d;
			qend++;
		}
	}
	while (qbeg < qend) {
		curtime += q[qbeg];
		qbeg++;
		while (res[r]==-1) r++;
		res[r] = curtime;
		r++;
	}
	FOR(i,n) printf("%I64d ", res[i]);
	printf("\n");
	return 0;
}