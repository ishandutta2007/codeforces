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

int a[100100];

int main() {
	int b,k;
	scanf("%d%d", &b, &k);
	FOR(i,k) scanf("%d", &a[i]);
	int odd = 0;
	if (b%2 == 0) {
		odd = a[k-1] % 2;
	} else {
		FOR(i,k) odd = (odd + a[i]) % 2;
	}
	printf("%s\n", odd ? "odd" : "even");
	return 0;
}