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

const int N = 55;

int n;
ll cap[N][N]; // INPUT
ll flow[N][N]; // OUTPUT
int edmonds (int s, int t) {
	ll b, e, q[n], p[n], d, res = 0;
	FOR(i,n) FOR(j,n) flow[i][j]=0;
	while(1) {
		FOR(i,n) p[i] = -1;
		for(q[b=e=0] = s; b <= e; ++b) FOR(v,n)
			if (flow[q[b]][v] < cap[q[b]][v] && p[v]<0)
				p[q[++e]=v] = q[b];
		if (p[t] < 0) break;
		d = cap[p[t]][t] - flow[p[t]][t];
		for(int i=t; i!=s; i=p[i]) d = min(d, cap[p[i]][i] - flow[p[i]][i]);
		for(int i=t; i!=s; i=p[i]) {
			flow[p[i]][i] += d;
			flow[i][p[i]] -= d;
		}
		res += d;
	}
	return res;
}

int m,x;
int g[N][N];

int main() {
	scanf("%d%d%d", &n, &m, &x);
	double low = 0, high = 1e7;
	FOR(i,m) {
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		a--; b--;
		g[a][b] = c;
	}
	FOR(qq,200) {
		double mid = (low+high) / 2;
		FOR(i,n) FOR(j,n) cap[i][j] = g[i][j] / mid;
		int fl = edmonds(0,n-1);
		if (fl >= x) low = mid;
		else high = mid;
	}
	printf("%.10lf\n", (low+high)/2*x);
	return 0;
}