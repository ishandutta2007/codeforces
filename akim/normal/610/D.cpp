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
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

vector<pair<int, pair<int, int> > > ver, hor;
vector<pair<int, pair<int, int> > > vern, horn;
vector<int> vc, fd;
priority_queue<pair<int, int> > q;

bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
	return(a.sc.fs < b.sc.fs);
}

int deo[4 * maxn];

void upd(int pos, int val, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tr < pos || tl > pos) {
		return;
	}
	if(tl == tr) {
		if(tl < (int)fd.size()) {
			fd[tl] += val;
			deo[v] = (fd[tl] != 0);
		}
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(pos, val, v * 2 + 1, tl, tm);
	upd(pos, val, v * 2 + 2, tm + 1, tr);
	deo[v] = deo[v * 2 + 1] + deo[v * 2 + 2];
}

int getsum(int lf, int rg, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(rg < lf) return(0);
	if(tr < lf || tl > rg) {
		return(0);
	}
	if(lf <= tl && rg >= tr) {
		return(deo[v]);
	}
	int tm = (tl + tr) >> 1;
	return(getsum(lf, rg, v * 2 + 1, tl, tm) +
	getsum(lf, rg, v * 2 + 2, tm + 1, tr));
}

int main() {

	#ifdef SOL
	{
		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x1 == x2) {
			ver.pb(mp(x1, mp(min(y1, y2), max(y1, y2))));
		}
		if(y1 == y2) {
			hor.pb(mp(y1, mp(min(x1, x2), max(x1, x2))));
		}
	}
	{
		sort(ver.begin(), ver.end());
		for(int i = 0; i < (int)ver.size(); i++) {
			if(!vern.empty() && vern.back().fs == ver[i].fs && vern.back().sc.sc >= ver[i].sc.fs) {
				vern.back().sc.sc = max(vern.back().sc.sc, ver[i].sc.sc);
			} else {
				vern.pb(ver[i]);
			}
		}
		ver.swap(vern);
	}
	{
		sort(hor.begin(), hor.end());
		for(int i = 0; i < (int)hor.size(); i++) {
			if(!horn.empty() && horn.back().fs == hor[i].fs && horn.back().sc.sc >= hor[i].sc.fs) {
				horn.back().sc.sc = max(horn.back().sc.sc, hor[i].sc.sc);
			} else {
				horn.pb(hor[i]);
				vc.pb(hor[i].fs);
				fd.pb(0);
			}
		}
		hor.swap(horn);
		sort(hor.begin(), hor.end(), cmp);
	}


//	for(int i = 0; i < ver.size(); i++) {
//		cout << ver[i].fs << " " << ver[i].sc.fs << " " << ver[i].sc.sc << endl;
//	}
//	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
//
//	for(int i = 0; i < hor.size(); i++) {
//		cout << hor[i].fs << " " << hor[i].sc.fs << " " << hor[i].sc.sc << endl;
//	}
//	cout << "--------------------------------------------------------\n";


	ll ans = 0;

	for(int i = 0; i < (int)ver.size(); i++) {
		ans += ver[i].sc.sc - ver[i].sc.fs + 1;
	}
	for(int i = 0; i < (int)hor.size(); i++) {
		ans += hor[i].sc.sc - hor[i].sc.fs + 1;
	}
//	cout << ans << endl;

	for(int i = 0, j = 0; i < (int)ver.size(); i++) {
		while(j < (int)hor.size() && hor[j].sc.fs <= ver[i].fs) {
			int pos = lower_bound(vc.begin(), vc.end(), hor[j].fs) - vc.begin();
//			cout << hor[j].fs << " " << pos << endl;
			q.push(mp(-hor[j].sc.sc, pos));
			upd(pos, 1);
			j++;
		}
		while(!q.empty() && -q.top().fs < ver[i].fs) {
			upd(q.top().sc, -1);
			q.pop();
		}

//		for(int i = 0; i < (int)vc.size(); i++) {
//			cout << vc[i] << " ";
//		}cout << endl;
//		for(int i = 0; i < (int)vc.size(); i++) {
//			cout << fd[i] << " ";
//		}cout << endl;

		ans -= getsum(lower_bound(vc.begin(), vc.end(), ver[i].sc.fs) - vc.begin(), upper_bound(vc.begin(), vc.end(), ver[i].sc.sc) - vc.begin() - 1);
//		cout << ver[i].sc.fs << " " << ver[i].sc.sc << " " << ans << endl;
	}

	printf("%lld", ans);

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim