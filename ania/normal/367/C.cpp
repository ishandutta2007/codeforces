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

int t[100100];

int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	FOR(i,m) scanf("%*d%d", &t[i]);
	sort(t,t+m);
	long long res = 0;
	for (int r = 1; r <= m && r*(r-1)/2+1 <= n && (r/2)*r <= n; r++)
		res += t[m-r];
	cout << res << "\n";
	return 0;
}