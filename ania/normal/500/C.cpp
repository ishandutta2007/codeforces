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

int a[1111], w[1111], used[1111];

int main() {
	int n,m,res=0;
	scanf("%d%d", &n, &m);
	FOR(i,n) scanf("%d", &w[i]);
	FOR(i,m) {
		scanf("%d", &a[i]);
		a[i]--;
		for (int j = i-1; j>= 0; j--) {
			if (a[j]==a[i]) break;
			//printf("i=%d, lift %d\n", i, a[j]);
			if(!used[a[j]]) res += w[a[j]];
			used[a[j]]=true;
		}
		for (int j = i-1; j>= 0; j--) {
			if (a[j]==a[i]) break;
			used[a[j]]=false;
		}
	}
	printf("%d\n", res);
	return 0;
}