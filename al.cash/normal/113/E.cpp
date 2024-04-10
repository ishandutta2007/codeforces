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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INFLL = 1000000000000000000LL;

int h,m, mk,hk, k;
ull t[21];
int h1,m1, h2,m2;

ll f (ull hx, ull mx) {
	return hx*((m-1)/t[k]) + mx/t[k] + hx/t[max(0, k-mk)];
}

int main() {
#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &h, &m, &k);
	--k;
	t[0] = 1;
	REP(i, k) t[i+1] = t[i]*10;
	m1 = m-1;
	while(m1) {
		if(m1%10) ++mk;
		m1 /= 10;
	}
	h1 = h-1;
	while(h1) {
		if(h1%10) ++hk;
		h1 /= 10;
	}
	scanf("%d%d", &h1, &m1);
	scanf("%d%d", &h2, &m2);
	ll res = f(h2, m2) - f(h1, m1);
	if(h1>h2 || h1==h2 && m1>m2) res += f(h-1, m-1) + (hk+mk>k);
	cout << res << endl;
#ifdef LocalHost
	cout << endl << "Time: " << clock() << endl;
#endif
//	system("PAUSE");
	return 0;
}