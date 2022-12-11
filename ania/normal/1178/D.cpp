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

const int N = 2020;

int p[N];

int n;

int main() {
	scanf("%d", &n);
	p[0]=p[1]=1;
	for (int i = 2; i*i < N; i++) if (p[i]==0) for (int j = i*i; j < N; j+=i) p[j]=1;
	
	//for (n = 3; n <= 1000; n++) {
	
	int m = n;
	while (p[m]) m++;
	
	printf("%d\n", m);
	for (int i = 1; i < n; i++) printf("%d %d\n", i, i+1);
	printf("1 %d\n", n);
	m -= n;
	for (int i = 1; i <= m; i++) printf("%d %d\n", i, i+n/2);
	
	//}
	return 0;
}