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

const int N = 100100;

int n,r;
int p[N];
double res[N];

double get(int dif) {
	return sqrt(4.0*r*r-1.0*dif*dif);
}

int main() {
	scanf("%d%d", &n, &r);
	FOR(i,n) {
		scanf("%d", &p[i]);
	}
	FOR(i,n) {
		int x = p[i];
		res[i] = r;
		FOR(j,i) if (abs(x-p[j]) <= 2*r) {
			res[i] = max(res[i], res[j]+get(x-p[j]));
		}
	}
	FOR(i,n) printf("%.8lf ", res[i]);
	printf("\n");
	return 0;
}