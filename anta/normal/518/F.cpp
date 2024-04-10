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
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

template<typename V>
void rotate_left_square(V &a, int n) {
	int n1 = n / 2, n2 = n - n1;
	rep(j, n1) rep(i, n2) {
		//a[j][i], a[n-1-i][j], a[n-1-j][n-1-i], a[i][n-1-j]
		auto t = a[i][n-1-j];
		a[i][n-1-j] = a[n-1-j][n-1-i];
		a[n-1-j][n-1-i] = a[n-1-i][j];
		a[n-1-i][j] = a[j][i];
		a[j][i] = t;
	}
}
template<typename V>
void rotate_left(V &a, int H, int W) {
	rotate_left_square(a, max(H, W));
	int pad = max(0, H - W);
	if(pad > 0) {
		for(int i = 0; i < W; i ++)
			for(int j = 0; j < H; ++ j)
				a[i][j] = a[i+pad][j];
	}
}

template<typename T>
struct RectangeSum {
	vector<vector<T> > sum;
	template<typename U>
	void init(int h, int w, U &a){
		sum.assign(h+1, vector<T>(w+1));
		rer(y, 0, h) rer(x, 0, w) sum[y][x] = (y == 0 || x == 0) ? 0 :
			sum[y-1][x] + sum[y][x-1] - sum[y-1][x-1] + a[y-1][x-1];
	}
	//[l, r), [t, b)
	inline T get(int t, int l, int b, int r) const {
		return sum[b][r] - sum[b][l] - sum[t][r] + sum[t][l];
	}
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<char*> s(max(n, m)+1);
	rep(i, max(n, m)+1)
		s[i] = new char[max(n, m)+1];
	rep(i, n)
		scanf("%s", s[i]);
	long long straight = 0, turnonce = 0, zigzagR = 0, zigzagL = 0, uturn = 0;
	RectangeSum<int> rsum;
	rep(rot, 4) {
		vector<vector<bool> > b(n, vector<bool>(m));
		rep(i, n) rep(j, m) b[i][j] = s[i][j] == '#';
		rsum.init(n, m, b);
		//straight line segment
		reu(j, 1, m-1) {
			bool ok = true;
			rep(i, n)
				ok &= s[i][j] == '.';
			straight += ok;
		}
		//turn once
		reu(j, 1, m-1) reu(i, 1, n-1) {
			bool ok = true;
			ok &= rsum.get(0, j, i+1, j+1) == 0;
			ok &= rsum.get(i, j, i+1, m) == 0;
			turnonce += ok;
		}
		//zigzag
		reu(i, 1, n-1) {
			int cnt = 0;
			reu(j, 1, m-1) {
				if(s[i][j] == '#') {
					cnt = 0;
					continue;
				}
				if(rsum.get(i, j, n, j+1) == 0)
					zigzagR += cnt;

				if(rsum.get(0, j, i+1, j+1) == 0)
					++ cnt;
			}
			cnt = 0;
			for(int j = m-2; j >= 1; -- j) {
				if(s[i][j] == '#') {
					cnt = 0;
					continue;
				}
				if(rsum.get(i, j, n, j+1) == 0)
					zigzagL += cnt;

				if(rsum.get(0, j, i+1, j+1) == 0)
					++ cnt;
			}
		}
		//u-turn
		reu(i, 1, n-1) {
			int cnt = 0;
			bool prevok = false;
			reu(j, 1, m-1) {
				if(s[i][j] == '#') {
					cnt = 0, prevok = false;
					continue;
				}
				bool ok = rsum.get(0, j, i+1, j+1) == 0;
				if(ok)
					uturn += cnt;

				cnt += prevok;
				prevok = ok;
			}
		}
		rotate_left(s, n, m);
		swap(n, m);
	}
	/*
#define TO_S(x) #x
#define DBG(x) cerr << TO_S(x) << ": " << (x) << endl;
	DBG(straight);
	DBG(turnonce);
	DBG(zigzagR);
	DBG(zigzagL);
	DBG(uturn);
	*/
	long long ans = straight / 2 + turnonce + zigzagR / 2 + zigzagL / 2 + uturn;
	cout << ans << endl;
	return 0;
}