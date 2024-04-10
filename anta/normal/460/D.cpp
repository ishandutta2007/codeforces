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

long long L, R; int K;
long long memo[42][1<<3][1<<3][1<<3];
vector<long long> hukugen;

long long rec(int i, int lt, int gt, int eq) {
	long long &x = memo[i+1][lt][gt][eq];
	if(x != -1) return x;
	if(i == -1) return eq == 0 ? 0 : INFL;
	x = INFL;
	int l = L >> i & 1, r = R >> i & 1;
	rep(j, 1 << K) {
		bool ok = true; int nlt = lt, ngt = gt;
		rep(k, K) {
			ok &= (lt >> k & 1) || (j >> k & 1) <= r;
			ok &= (gt >> k & 1) || l <= (j >> k & 1);
			nlt |= ((j >> k & 1) < r) << k;
			ngt |= (l < (j >> k & 1)) << k;
		}
		if(!ok) continue;
		int neq = eq & (
			((j >> 0 & 1) == (j >> 1 & 1)) << 0 |
			((j >> 0 & 1) == (j >> 2 & 1)) << 1 |
			((j >> 1 & 1) == (j >> 2 & 1)) << 2 );
		int y = 0;
		rep(k, K) y ^= j >> k & 1;
		amin(x, rec(i-1, nlt, ngt, neq) | ((long long)y << i));
	}
	return x;
}

void rec_hukugen(int i, int lt, int gt, int eq) {
	if(i == -1) {
		assert(eq == 0);
		return;
	}
	long long x = memo[i+1][lt][gt][eq];
	int l = L >> i & 1, r = R >> i & 1;
	rep(j, 1 << K) {
		bool ok = true; int nlt = lt, ngt = gt;
		rep(k, K) {
			ok &= (lt >> k & 1) || (j >> k & 1) <= r;
			ok &= (gt >> k & 1) || l <= (j >> k & 1);
			nlt |= ((j >> k & 1) < r) << k;
			ngt |= (l < (j >> k & 1)) << k;
		}
		if(!ok) continue;
		int neq = eq & (
			((j >> 0 & 1) == (j >> 1 & 1)) << 0 |
			((j >> 0 & 1) == (j >> 2 & 1)) << 1 |
			((j >> 1 & 1) == (j >> 2 & 1)) << 2 );
		int y = 0;
		rep(k, K) y ^= j >> k & 1;
		long long nx = rec(i-1, nlt, ngt, neq) | ((long long)y << i);
		if(nx == x) {
			rep(k, K) hukugen[k] |= (long long)(j >> k & 1) << i;
			return rec_hukugen(i-1, nlt, ngt, neq);
		}
	}
	assert(false);
}

int main() {
	//0
	//
	long long l, r; int k;
	cin >> l >> r >> k;
	vector<long long> ans;
	long long ansxor;
	if(k >= 4 && r - (l + (l % 2 == 1)) + 1 >= 4) {
		//n[n..n+3]0
		rep(i, 4)
			ans.push_back(l + (l % 2 == 1) + i);
		ansxor = 0;
	}else if(k == 4) {
		assert(l % 2 == 1 && r - l + 1 == 4);
		pair<long long,int> p(INFL,-1);
		rep(i, 1 << 4) if(i != 0) {
			long long x = 0;
			rep(j, 4) if(i >> j & 1)
				x ^= l + j;
			amin(p, mp(x, i));
		}
		rep(j, 4) if(p.second >> j & 1)
			ans.push_back(l + j);
		ansxor = p.first;
	}else {
		//k <= 3
		L = l, R = r;
		ansxor = INFL;
		for(K = 1; K <= k; ++ K) {
			mset(memo, -1);
			long long x = rec(40, 0, 0, (1 << K) - 1);
			if(ansxor > x) {
				ansxor = x;
				hukugen.assign(K, 0);
				rec_hukugen(40, 0, 0, (1 << K) - 1);
				ans = hukugen;
			}
		}
	}
	sort(all(ans));
	assert(ans.size() <= k);
	assert(unique(all(ans)) == ans.end());
	long long x = 0;
	rep(i, ans.size()) x ^= ans[i];
	assert(x == ansxor);
	cout << x << endl;
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		if(i != 0) cout << ' ';
		cout << ans[i];
	}
	cout << endl;
	return 0;
}