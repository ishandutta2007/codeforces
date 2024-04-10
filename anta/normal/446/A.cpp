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

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	int ans = -1;
	rep(lr, 2) {
		vector<pair<int,int> > segments;
		for(int i = 0; i < n; ) {
			int j = i + 1;
			while(j < n && a[j-1] < a[j]) j ++;
			amax(ans, j - i);
			segments.push_back(mp(i, j));
			i = j;
		}
		rep(i, segments.size()) {
			int l = segments[i].first, r = segments[i].second;
			if(r == n) continue;
			amax(ans, r - l + 1);
			//a[r-1]
			if(i+1 < (int)segments.size()) {
				if(segments[i+1].first != r) cerr << "assert" << endl;
				int L = l + 1 == r ? -INF : a[r-2];
				int R = a[r];
				if(R - L >= 2) {
					amax(ans, segments[i+1].second - l);
				}
			}
		}
		reverse(all(a));
		rep(i, n) a[i] = -a[i];
	}
	printf("%d\n", ans);
	return 0;
}