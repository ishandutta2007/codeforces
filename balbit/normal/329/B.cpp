#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b) for (int i = a; i<b; i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i = n-1; i>=0; i--)
#define MN(a,b) a = min((__typeof__(a))(b),a)
#define MX(a,b) a = max((__typeof__(a))(b),a)
#define SZ(x) (int)(x.size())
#define ALL(x) x.begin(),x.end()
#define pii pair<int, int>
#define f first
#define s second 

#ifdef BALBIT
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define bug(x) cerr<<"Line "<<__LINE__<<": "<<#x<<" is "<<x<<endl
#else
#define IOS()
#define bug(x)
#define endl '\n'
#endif
//#define int ll
const int maxn = 1005;
const ll inf = 1ll<<61;
const int iinf = 1<<30;
char g[maxn][maxn];
int dst[maxn][maxn];

pii sum(pii a, pii b){
	return {a.f+b.f,a.s+b.s};
}

signed main(){
	IOS();
	int n, m; cin>>n>>m;
	int s1, s2;
	pii Ed;
	REP(i,n) REP(j,m){
		cin>>g[i][j];
		if (g[i][j]=='E') {
			s1 = i; s2 = j;
		}
		if (g[i][j] == 'S'){
			Ed = {i,j};
		}
	}
	queue<pii> q;
	q.push({s1,s2});
	REP(i,n) REP(j,m) dst[i][j] = iinf;
	dst[s1][s2]=0;
	vector<pii> dd = {{-1,0},{1,0},{0,1},{0,-1}};
	while (!q.empty()){
		pii at = q.front(); q.pop();
		for (pii x: dd){
			pii to = sum(at,x);
			if(to.f<0 || to.s<0 || to.f>=n || to.s>=m) continue;
			if (g[to.f][to.s] != 'T' && dst[to.f][to.s]==iinf){
				dst[to.f][to.s] = dst[at.f][at.s]+1;
				q.push(to);
			}
		}
	}
	int dt = dst[Ed.f][Ed.s];
	bug(dt);
	int re = 0;
	REP(i,n) REP(j,m){
		
		if(dst[i][j]<=dt && g[i][j] >='0' && g[i][j]<='9') {
			bug(dst[i][j]);
			re += g[i][j]-'0';
		}
	}
	cout<<re<<endl;
}