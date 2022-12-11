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

const int maxn = 333;
char s[maxn][maxn];

int p[maxn], pa[maxn], pos[maxn], res[maxn];
vi all[maxn];

int fi(int a) {
	return pa[a]==a ? a : pa[a]=fi(pa[a]);
}

void un(int a, int b) {
	int fa=fi(a), fb=fi(b);
	pa[fa]=fb;
}

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n) pa[i]=i;
	FOR(i,n) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	FOR(i,n) scanf("%s", s[i]);
	FOR(i,n) FOR(j,n) if (s[i][j]=='1') un(p[i], p[j]);
	FOR(i,n) all[fi(i)].pb(i);
	FOR(i,n) sort(all[i].begin(), all[i].end());
	FOR(i,n) {
		int f=fi(p[i]);
		res[i] = all[f][pos[f]];
		pos[f]++;
	}
	FOR(i,n) printf("%d ", res[i]+1);
	printf("\n");
	return 0;
}