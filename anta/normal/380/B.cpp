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
#include <list>
#include <cassert>
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
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

const int MaxW = 109315 + 1000;
int positions[MaxW];
bool b[1000001];
int main() {
	{	int pos = 0;
		rep(i, MaxW) {
			positions[i] = pos;
			if(((i+1) & i) == 0)
				pos += 2;
			else
				pos ++;
		}
	}
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<pair<pii,int> > > ints(n);
	vi xs;
	rep(i, m) {
		int ty;
		scanf("%d", &ty);
		if(ty == 1) {
			int t, l, r, x;
			scanf("%d%d%d%d", &t, &l, &r, &x);
			t --, l --, r --;	//
			ints[t].pb(mp(mp(l, r), x));
		}else {
			int t, v;
			scanf("%d%d", &t, &v);
			xs.clear();
			t --, v --;
			int left = v, right = v;
			while(t < n) {
//				cerr << t+1 << ": " << left+1 << ".." << right+1 << endl;
				each(j, ints[t]) {
					pii p = j->first;
					if(p.first <= right && left <= p.second)
						xs.pb(j->second);
				}
				left = positions[left];
				right = positions[right] + (((right+1) & right) == 0);
				t ++;
			}
			int ans = 0;
			each(x, xs) {
				if(!b[*x]) {
					b[*x] = true;
					ans ++;
				}
			}
			each(x, xs) b[*x] = false;
			printf("%d\n", ans);
		}
	}
	return 0;
}