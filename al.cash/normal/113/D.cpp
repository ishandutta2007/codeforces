#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i=(a), _b=(b); i>=_b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INFLL = 1000000000000000000LL;

const int h=1<<8, N=22;

int n,m, a,b;
int v[N][N], v0, k;
bool y[N][N];
double p[N];
vi r[N];

double A[h][h+N];

double P(int i, int j) {
	return i==j ? p[i] : y[i][j] ? (1-p[i])/sz(r[i]) : 0.0;
}

int main() {
#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &m, &a, &b);
	REP(i, n) FOR(j, i, n) v[i][j] = v[j][i] = k++;
	v0 = v[a-1][b-1];
	REP(i, m) {
		scanf("%d%d", &a, &b);
		--a; --b;
		r[a].pb(b);
		r[b].pb(a);
		y[a][b] = y[b][a] = 1;
	}
	m = k;
	REP(i, n) scanf("%lf", p+i);
	REP(i, n) FOR(j, i+1, n) {
		REP(x, n) REP(y, n)
			A[v[i][j]][v[x][y]] += P(i, x) * P(j, y);
	}
	REP(i, n) A[v[i][i]][v[i][i]] = 1.0;
	REP(i, n) FOR(j, i+1, n) A[v[i][j]][v[i][j]] -= 1.0;
	REP(i, n) A[v[i][i]][m+i] = 1.0;
	REP(i, m) {
		int u = i;
		FOR(c, i+1, m) if(fabs(A[c][i]) > fabs(A[u][i])) u = c;
		if(u!=i) FOR(j, i, m+n) swap(A[i][j], A[u][j]);
		double t = A[i][i];
		FOR(j, i, m+n) A[i][j] /= t;
		REP(c, m) if(c!=i) {
			t = A[c][i];
			FOR(j, i, m+n) A[c][j] -= t * A[i][j];
		}
	}
	//REP(i, m) { REP(j, m) printf("%.3lf ", A[i][j]); printf("|"); REP(j, n) printf(" %.3lf", A[i][m+j]); printf("\n"); } printf("\n");
	REP(i, n) printf("%.9lf ", A[v0][m+i]);
	printf("\n");
#ifdef LocalHost
	cout << endl << "Time: " << clock() << endl;
#endif
//	system("PAUSE");
	return 0;
}