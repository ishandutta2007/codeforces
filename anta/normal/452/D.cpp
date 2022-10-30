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

struct Event {
	int t, i;
	bool operator>(const Event &that) const {
		if(t != that.t) return t > that.t;
		else return i < that.i;
	}
};

int main() {
	const int N = 3;
	int k, n[N], t[N];
	scanf("%d", &k);
	rep(i, N) scanf("%d", &n[i]);
	rep(i, N) scanf("%d", &t[i]);
	priority_queue<Event,vector<Event>,greater<Event> > q;
	vector<int> cnt(N), wai(N);
	while(cnt[0] < k && cnt[0] < n[0]) {
		Event e = { t[0], 0 };
		q.push(e);
		++ cnt[0];
	}
	wai[0] = k - cnt[0];
	int ok = 0, ans = -1;
	while(true) {
		Event e = q.top(); q.pop();
		int tt = e.t, i = e.i;
//		cerr << tt << ", " << i << ": " << cnt[i] << ", " << wai[i] << endl;
		-- cnt[i];
		if(wai[i] > 0) {
			Event f = { tt + t[i], i };
			q.push(f);
			++ cnt[i];
			-- wai[i];
		}
		if(i == 2) {
			if(++ ok == k) {
				ans = tt;
				break;
			}
		}else if(cnt[i+1] < n[i+1]) {
			++ cnt[i+1];
			Event f = { tt + t[i+1], i+1 };
			q.push(f);
		}else {
			++ wai[i+1];
		}
	}
	printf("%d\n", ans);
	return 0;
}