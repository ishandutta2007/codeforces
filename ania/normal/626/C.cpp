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

int n,m;

bool ok(int h) {
	int a = h/2, b = h/3, c = h/6;
	a-=c;
	b-=c;
	a = n-a;
	b = m-b;
	if (a<0) a=0;
	if (b<0) b=0;
	if (a+b <= c) return 1;
	return 0;
}

int main() {
	scanf("%d%d", &n, &m);
	int le = 0, ri = 3*(n+m+5);
	while (le+1 < ri) {
		int mi = (le+ri)/2;
		if (ok(mi)) ri=mi;
		else le=mi;
	}
	printf("%d\n", ri);
	return 0;
}