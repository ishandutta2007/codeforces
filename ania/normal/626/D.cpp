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

int a[2020], suff[10101], occ[5050];
double res=0;

int main() {
	int n,mxv=0;
	scanf("%d",&n);
	FOR(i,n) scanf("%d", &a[i]);
	sort(a,a+n);
	FOR(i,n) FOR(j,i) {
		occ[a[i]-a[j]]++;
		mxv=max(mxv,a[i]-a[j]);
	}
	for (int i=mxv; i>0; i--) suff[i] = suff[i+1] + occ[i];
	FORI(i,mxv) FORI(j,mxv) {
		res += 8.0 * suff[i+j+1] / n / (n-1) * occ[i] * occ[j] / n / (n-1);
	}
	printf("%.10lf\n", res/(n*(n-1)));
	return 0;
}