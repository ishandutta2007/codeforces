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

const int maxn = 2000000;
const int smaxn = 2000;

int sumpr[maxn+222];
int pr[maxn+222];
int pal[maxn+222];
int sumpal[maxn+222];

int main() {
	FORI(i,maxn) pr[i]=1;
	pr[1]=0;
	for (int i=2;i*i<maxn;i++) if (pr[i]) for (int j=i*i; j<=maxn; j+=i) pr[j]=0;
	FORI(i,maxn) sumpr[i]=sumpr[i-1]+pr[i];
	FOR(i,smaxn) {
		int cur=i, inv=0, base=1;
		while (cur>0) {
			inv = inv*10+(cur%10);
			cur /= 10;
			base *= 10;
		}
		int U = i*base+inv;
		if (U<=maxn) pal[U] = 1;
		FOR(d,10) {
			int V = (i*10+d)*base+inv;
			if (V<=maxn) pal[V] = 1;
		}
	}
	FORI(i,maxn) sumpal[i]=sumpal[i-1]+pal[i];
	//printf("%d %d %d %d %d\n", sumpal[10], sumpal[100], sumpal[1000], sumpal[2000], sumpal[2520]);
	int p,q;
	scanf("%d%d", &p, &q);
	int last=-1;
	FORI(i,maxn) if (1LL*sumpr[i]*q <= 1LL*sumpal[i]*p) last=i;
	if (last==-1) {
		printf("Palindromic tree is better than splay tree\n");
		return 0;
	}
	printf("%d\n", last);
	//for (int i=2450; i<2550; i++) printf("%d -- %d %d -- %.4lf\n", i, sumpr[i], sumpal[i], 1.0*sumpr[i]/sumpal[i]);
	return 0;
}