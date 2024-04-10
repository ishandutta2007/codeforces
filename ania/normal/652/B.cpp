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

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &a[i]);
	sort(a,a+n);
	int x=0;
	for (; 2*x < n; x++) {
		b[2*x] = a[x];
	}
	for (int i = n-1; i >= 0; i--) if (i&1)
		b[i] = a[x++];
	FOR(i,n) printf("%d ", b[i]);
	printf("\n");
	return 0;
}