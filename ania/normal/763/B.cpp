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

int main() {
	int n;
	scanf("%d", &n);
	printf("YES\n");
	FOR(i,n) {
		int ax, ay, bx, by;
		scanf("%d%d%d%d", &ax, &ay, &bx, &by);
		ax %= 2;
		ay %= 2;
		if (ax<0) ax += 2;
		if (ay<0) ay += 2;
		printf("%d\n", ax*2+ay+1);
	}
	return 0;
}