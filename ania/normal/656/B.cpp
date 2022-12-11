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

int V[1000100], M[22], R[22];

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &M[i]);
	FOR(i,n) scanf("%d", &R[i]);
	int L = 1;
	FOR(i,n) L *= M[i] / __gcd(L, M[i]);
	FOR(i,n) {
		for (int x = R[i]; x < L; x += M[i]) V[x]=1;
	}
	int res = 0;
	FOR(i,L) if (V[i]) res++;
	printf("%.6lf\n", 1.*res/L);
	return 0;
}