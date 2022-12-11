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

const int maxn = 500500;
char T[maxn];
ll p[maxn], s[maxn], scop[maxn], scos[maxn];

int get(int n, int a, int b, int t) {
	p[0] = T[0]=='w';
	FORI(i,n-1) p[i] = p[i-1] + (T[i]=='w');
	s[0] = 0;
	FORI(i,n-1) s[i] = s[i-1] + (T[n-i]=='w');
	FOR(i,n) scop[i] = 2*i*a + i+1 + p[i]*b;
	FOR(i,n) scos[i] = i*a + i + s[i]*b;
	/*
	printf("   p = "); FOR(i,n) printf("%d ", p[i]); printf("\n");
	printf("   s = "); FOR(i,n) printf("%d ", s[i]); printf("\n");
	printf("scop = "); FOR(i,n) printf("%d ", scop[i]); printf("\n");
	printf("scop = "); FOR(i,n) printf("%d ", scos[i]); printf("\n");*/
	int k = 0, j = 0, res = 0;
	while (j+1 < n && scop[k] + scos[j+1] <= t) j++;
	while (k<n) {
		while (j >= 0 && scop[k] + scos[j] > t) j--;
		if (j<0) break;
		res = max(res, k+j+1);
		k++;
	}
	res = min(res, n);
	return res;
}

int main() {
	int n,a,b,t;
	scanf("%d%d%d%d%s", &n, &a, &b, &t, T);
	int res = get(n,a,b,t);
	for (int i = 1, j = n-1; i < j; i++, j--) swap(T[i], T[j]);
	res = max(res, get(n,a,b,t));
	printf("%d\n", res);
	return 0;
}