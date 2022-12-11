#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
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
const int maxn = 200100;

pair<int, int> deo[4 * 2 * 2 * maxn];
set<pair<int, int> > lft, rgh;
int lfr[maxn], rgr[maxn], pss[maxn];
int lfk[maxn], rgk[maxn], stm[maxn], pssk[maxn];
vector<pair<int, pair<int, int> > > vc;

void add(int pos, int val, int id, int v, int tl, int tr) {
	if(tl > pos || tr < pos) {
		return;
	}
	if(tl == pos && tl == tr) {
		deo[v] = mp(val, id);
		return;
	}
	int tm = (tl + tr) >> 1;
	add(pos, val, id, v * 2 + 1, tl, tm);
	add(pos, val, id, v * 2 + 2, tm + 1, tr);
	deo[v] = max(deo[v * 2 + 1], deo[v * 2 + 2]);
}

pair<int, int> getmax(int lf, int rg, int v, int tl, int tr) {
	if(lf > rg) {return(mp(0, -1));}
	if(lf == tl && rg == tr) {
		return(deo[v]);
	}
	int tm = (tl + tr) >> 1;
	return(max(getmax(lf, min(rg, tm), v * 2 + 1, tl, tm), getmax(max(lf, tm + 1), rg, v * 2 + 2, tm + 1, tr)));
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
		scanf("%d%d", &lfr[i], &rgr[i]);
		vc.pb(mp(lfr[i], mp(1, i)));
		vc.pb(mp(rgr[i], mp(4, i)));
	}

	for(int i = 0; i < m; i++) {
		scanf("%d%d%d", &lfk[i], &rgk[i], &stm[i]);
		vc.pb(mp(lfk[i], mp(2, i)));
		vc.pb(mp(rgk[i], mp(3, i)));
	}

	sort(vc.begin(), vc.end());

	ll ans = 0, idx1 = -1, idx2 = -1;

	for(int i = 0; i < (int)vc.size(); i++) {
		if(vc[i].sc.fs == 1) {
			int id = vc[i].sc.sc;
			lft.insert(mp(lfr[id], id));
			rgh.insert(mp(rgr[id], id));
			pss[id] = i;
		}
		if(vc[i].sc.fs == 2) {
			ll prans = ans;
			int id = vc[i].sc.sc;
			ans = max(ans, (min(rgh.size() > 0 ? (*rgh.rbegin()).fs : lfk[id] - 1, rgk[id]) - lfk[id] + 1) * 1ll * stm[id]);
			if(prans != ans) {
				idx1 = id;
				idx2 = (*rgh.rbegin()).sc;
			}
			pssk[id] = i;
		}
		if(vc[i].sc.fs == 3) {
			ll prans = ans;
			int id = vc[i].sc.sc;
			ans = max(ans, (rgk[id] - max(lft.size() > 0 ? (*lft.begin()).fs : rgk[id] + 1, lfk[id]) + 1) * 1ll * stm[id]);
			if(prans != ans) {
				prans = ans;
				idx1 = id;
				idx2 = (*lft.begin()).sc;
			}
			ans = max(ans, getmax(pssk[id], i, 0, 0, vc.size() - 1).fs * 1ll * stm[id]);
			if(prans != ans) {
				idx1 = id;
				idx2 = getmax(pssk[id], i, 0, 0, vc.size() - 1).sc;
			}
		}
		if(vc[i].sc.fs == 4) {
			int id = vc[i].sc.sc;
			lft.erase(mp(lfr[id], id));
			rgh.erase(mp(rgr[id], id));
			add(pss[id], rgr[id] - lfr[id] + 1, id, 0, 0, vc.size() - 1);
		}
	}
	if(ans && ans - stm[idx1]) {
		printf("%I64d\n", ans - stm[idx1]);
		printf("%I64d %I64d\n", idx2 + 1, idx1 + 1);
	} else {
		printf("0\n");
	}

	return(0);
}

// by Kim Andrey