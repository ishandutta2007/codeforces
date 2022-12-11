#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 500100;

int x[maxn], preddist[524288 * 2 + 100], ance[maxn], k = 524288;
map<int, int> ma;
pair<int, pair<int, int> > pa[maxn];
int ans[maxn];

void update(int u) {
	u /= 2;
	if(u == 0) return;
	preddist[u] = min(preddist[u * 2], preddist[u * 2 + 1]);
	update(u);
}

int getmin(int l, int r) {
	int ret = mod;
	while(l < r) {
		if((l & 1) == 1) {
			ret = min(ret, preddist[l]);
			l++;
		}
		if((r & 1) == 0) {
			ret = min(ret, preddist[r]);
			r--;
		}
		l /= 2; r /= 2;
	}
	if(l == r) {
		ret = min(ret, preddist[l]);
	}
	return(ret);
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		ance[i] = mod;
		if(ma.count(x[i])) {
			int pos = ma[x[i]];
			preddist[k + i] = i - pos;
			ance[pos] = i;
		} else {
			preddist[k + i] = mod;
		}
		ma[x[i]] = i;
	}
	for(int i = k - 1; i > 0; i--) {
		preddist[i] = min(preddist[i * 2], preddist[i * 2 + 1]);
	}

	for(int i = 0; i < m; i++) {
		pa[i].sc.sc = i;
		scanf("%d%d", &pa[i].fs, &pa[i].sc.fs);
		pa[i].fs--;
		pa[i].sc.fs--;
	}

	sort(&pa[0], &pa[m]);

	int cur = 0;
	for(int i = 0; i < m; i++) {
		while(cur < pa[i].fs) {
			if(ance[cur] != mod) {
				preddist[k + ance[cur]] = mod;
				update(k + ance[cur]);
			}
			cur++;
		}
		ans[pa[i].sc.sc] = getmin(k + pa[i].fs, k + pa[i].sc.fs);
		if(ans[pa[i].sc.sc] == mod) {
			ans[pa[i].sc.sc] = -1;
		}
	}
	for(int i = 0; i < m; i++) {
		printf("%d\n", ans[i]);
	}

	return(0);
}

// by Kim Andrey