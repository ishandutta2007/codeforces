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

int a[30303], poss[30303];

int main() {
	int n,t;
	scanf("%d%d", &n, &t);
	t--;
	FOR(i,n-1) scanf("%d", &a[i]);
	for (int i=n-1; i >= 0; i--) {
		poss[i] = i==t || poss[i+a[i]];
	}
	printf("%s\n", poss[0] ? "YES" : "NO");
	return 0;
}