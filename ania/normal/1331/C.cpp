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

int b[7];

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,6) {
		b[i] = n%2;
		n /= 2;
	}
	swap(b[0], b[4]);
	swap(b[2], b[3]);
	FOR(i,6) n += b[i] << i;
	printf("%d\n", n);
	return 0;
}