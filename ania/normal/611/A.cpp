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

char s1[222], s2[222];
int m[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int d[7]={4,5,6,7,1,2,3};

int main() {
	int x;
	scanf("%d %s %s", &x, s1, s2);
	if (s2[0]=='w') {
		int res=0;
		for (int i=d[x-1]; i<=366; i+=7) res++;
		printf("%d\n",res);
	} else {
		int res=0;
		FOR(i,12) if (x<=m[i]) res++;
		printf("%d\n",res);
	}
	return 0;
}