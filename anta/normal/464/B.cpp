#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <bitset>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int pos[8][3];
bool used[8];
int ps[4];
vector<vi> expos, expossorted;
vector<vi> ans;

long long sq(int x) { return (long long)x * x; }

bool rec1(int i) {
	if(i == 4) {
		expos.assign(4, vi(3));
		rep(k, 3) {
			int a = pos[ps[1]][k] - pos[ps[0]][k];
			int b = pos[ps[2]][k] - pos[ps[0]][k];
			int c = pos[ps[3]][k] - pos[ps[0]][k];
			expos[0][k] = pos[ps[0]][k] + a + b;
			expos[1][k] = pos[ps[0]][k] + a + c;
			expos[2][k] = pos[ps[0]][k] + b + c;
			expos[3][k] = pos[ps[0]][k] + a + b + c;
		}
		long long dist[3] = {};
		rep(j, 3) rep(k, 3) dist[j] += sq(pos[ps[1+j]][k] - pos[ps[0]][k]);
//		cerr << dist[0] << ", " << dist[1] << ", " << dist[2] << endl;
		if(!(dist[0] == dist[1] && dist[1] == dist[2])) return false;
		if(dist[0] == 0) return false;

		expossorted = expos;
		rep(j, 4) sort(all(expossorted[j]));
		sort(all(expossorted));
		vector<vector<int> > rempos;
		rep(j, 8) if(!used[j]) {
			rempos.push_back(vi());
			rep(k, 3) rempos.back().push_back(pos[j][k]);
			sort(all(rempos.back()));
		}
		sort(all(rempos));
		if(expossorted == rempos) {
			ans.assign(8, vi(3));
			rep(j, 4) rep(k, 3) ans[j][k] = pos[ps[j]][k];
			rep(j, 4) rep(k, 3) ans[4+j][k] = expos[j][k];
			return true;
		}
		return false;
	}
	rep(j, 8) if(!used[j]) {
		used[j] = true;
		sort(pos[j], pos[j] + 3);
		do {
			ps[i] = j;
			if(rec1(i+1)) return true;
		}while(next_permutation(pos[j], pos[j] + 3));
		used[j] = false;
	}
	return false;
}

int main() {
	rep(i, 8) rep(j, 3) scanf("%d", &pos[i][j]);
	if(!rec1(0)) {
		puts("NO");
		return 0;
	}
	puts("YES");
	vector<bool> matched(8);
	rep(i, 8) {
		rep(j, 8) if(!matched[j]) {
			vi p(pos[i], pos[i] + 3);
			vi q = ans[j];
			sort(all(p));
			sort(all(q));
			if(p == q) {
				matched[j] = true;
				printf("%d %d %d\n", ans[j][0], ans[j][1], ans[j][2]);
				break;
			}
		}
	}
	return 0;
}