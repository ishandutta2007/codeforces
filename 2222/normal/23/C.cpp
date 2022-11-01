#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)		(a).begin(),(a).end()
#define sz(a)		int((a).size())
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
#define UN(v)		sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)		memset(a,b,sizeof a)
#define pb			push_back
#define X			first
#define Y			second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n;
pii a[211111];
int p[211111];

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	int T;
	for (cin >> T; T --> 0; ) {
		cin >> n;
		ll sx = 0, sy = 0;
		REP (i, 2 * n - 1) {
			p[i] = i;
			scanf("%d%d", &a[i].X, &a[i].Y);
			sx += a[i].X;
			sy += a[i].Y;
		}
		for (; ; ) {
			random_shuffle(p, p + (2 * n - 1));
			ll x = 0, y = 0;
			REP (i, n) x += a[p[i]].X, y += a[p[i]].Y;
			if (2 * x >= sx && 2 * y >= sy) break;
		}
		puts("YES");
		sort(p, p + n);
		REP (i, n) {
			if (i) putchar(' ');
			printf("%d", p[i] + 1);
		}
		cout << endl;
	}
	return 0;
}