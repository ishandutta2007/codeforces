#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

int n;
int p[100100];

int main() {
	scanf("%d", &n);
	if (n<=2) {
		printf("1\n");
		FOR(i,n) printf("1 ");
		printf("\n");
		return 0;
	}
	n++;
	for (int i=2;i<=n;i++) p[i]=1;
	for (int i=2;i*i<=n;i++) if (p[i]) for (int j=i*i;j<=n;j+=i) p[j]=0;
	printf("2\n");
	for (int i=2;i<=n;i++) printf("%d ", p[i]+1);
	printf("\n");
	return 0;
}