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

const int maxn = 100100;

int a[maxn], b[maxn];
int p[maxn];
int lft[maxn], rgt[maxn];

int main() {
	int n,q;
	scanf("%d%d", &n, &q);
	FOR(i,n) scanf("%d", &a[i]);
	FOR(i,n-1) b[i]=abs(a[i+1]-a[i]);
	int pos = -1;
	FOR(i,n-1) {
		while (pos>=0 && b[i]>b[p[pos]]) pos--;
		lft[i] = pos<0 ? -1 : p[pos];
		if (pos>=0 && b[p[pos]]==b[i]) pos--;
		p[++pos] = i;
	}
	//FOR(i,n-1) printf("%d ", lft[i]); printf("\n");
	pos = -1;
	for (int i = n-1; i >= 0; i--) {
		while (pos>=0 && b[i]>=b[p[pos]]) pos--;
		rgt[i] = pos<0 ? n+1 : p[pos];
		p[++pos] = i;
	}
	//FOR(i,n-1) printf("%d ", rgt[i]); printf("\n");
	FOR(_,q) {
		int L,R;
		scanf("%d%d", &L, &R);
		L--; R-=2;
		long long res = 0;
		REP(i,L,R) {
			int le = i-max(L-1, lft[i])-1, ri = min(R+1, rgt[i])-i-1;
			int len = ri + le + 1;
			//printf("%d -- %d = %d-%d\n", b[i], len, le, ri);
			res += (1LL*len*(len+1)-1LL*le*(le+1)-1LL*ri*(ri+1))/2*b[i];
		}
		printf("%I64d\n", res);
	}
	return 0;
}