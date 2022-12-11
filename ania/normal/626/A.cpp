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

char s[222];

int main() {
	int n,res=0;
	scanf("%d %s", &n, s);
	FORI(i,n) FOR(j,i) {
		int w=0, h=0;
		REP(k,j,i-1) {
			if (s[k]=='U') w++;
			if (s[k]=='D') w--;
			if (s[k]=='L') h++;
			if (s[k]=='R') h--;
		}
		if (w==0 && h==0) res++;
	}
	printf("%d\n", res);
	return 0;
}