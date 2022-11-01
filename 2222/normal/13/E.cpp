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

int p[111111], q[111111], c[111111];
int n, m;

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	scanf("%d%d", &n, &m);
	REP (i, n) {
		scanf("%d", p + i);
		p[i] = q[i] = min(i + p[i], n);
		c[i] = 1;
	}
	p[n] = q[n] = -1u / 4;
	REP (x, n)
		for (int i = x - 1, i0 = max(i - 400, 0); i >= i0; --i) 
			if (p[i] == x) q[i] = x, c[i] = 1; else
			if (q[p[i]] == x) c[i] = c[p[i]] + 1, q[i] = x;
	for (; m --> 0; ) {
		int qq;
		scanf("%d", &qq);
		if (qq) {
			int x; scanf("%d", &x);
			--x;
			int r1 = 0, r2 = 0;
			for (; x < n; x = q[x]) r1 = x, r2 += c[x];				
			printf("%d %d\n", r1 + 1, r2);
		} else {
			int x, y; scanf("%d%d", &x, &y);
			--x;
			p[x] = q[x] = min(x + y, n);
			c[x] = 1;
			for (int i = x - 1, i0 = max(i - 400, 0); i >= i0; --i) 
				if (p[i] == x) q[i] = x, c[i] = 1; else
				if (q[p[i]] == x) c[i] = c[p[i]] + 1, q[i] = x;
		}
	}
	return 0;
}