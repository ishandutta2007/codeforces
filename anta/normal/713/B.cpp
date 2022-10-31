#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

bool smaller(vi a, vi b) {
	return b[0] <= a[0] && b[1] <= a[1] && a[2] <= b[2] && a[3] <= b[3];
}

int n;
int query(int x1, int y1, int x2, int y2) {
	amax(x1, 0);
	amax(y1, 0);
	amin(x2, n);
	amin(y2, n);
	if(x1 >= x2 || y1 >= y2)
		return 0;
	printf("? %d %d %d %d\n", x1 + 1, y1 + 1, x2, y2);
	fflush(stdout);
	int r;
	scanf("%d", &r);
	return r;
}

int main() {
	while(~scanf("%d", &n)) {
		vi xs, ys;
		rep(r, 2) {
			int x = 0;
			for(int k = 16; k >= 0; -- k) {
				if(query(0, 0, x + (1 << k), n) <= r)
					x += 1 << k;
			}
			xs.push_back(x + 1);
		}
		rep(r, 2) {
			int x = 0;
			for(int k = 16; k >= 0; -- k) {
				if(query(n - x - (1 << k), 0, n, n) <= r)
					x += 1 << k;
			}
			xs.push_back(n - x - 1);
		}
		rep(r, 2) {
			int x = 0;
			for(int k = 16; k >= 0; -- k) {
				if(query(0, 0, n, x + (1 << k)) <= r)
					x += 1 << k;
			}
			ys.push_back(x + 1);
		}
		rep(r, 2) {
			int x = 0;
			for(int k = 16; k >= 0; -- k) {
				if(query(0, n - x - (1 << k), n, n) <= r)
					x += 1 << k;
			}
			ys.push_back(n - x - 1);
		}
		sort(xs.begin(), xs.end());
		xs.erase(unique(xs.begin(), xs.end()), xs.end());
		sort(ys.begin(), ys.end());
		ys.erase(unique(ys.begin(), ys.end()), ys.end());
		vector<vi> rects;
		for(int x1 : xs) for(int x2 : xs) if(x1 < x2) {
			for(int y1 : ys) for(int y2 : ys) if(y1 < y2) {
				if(query(x1, y1, x2, y2) == 1) {
					vi v{ x1, y1, x2, y2 };
					vector<vi> nrects;
					bool ok = true;
					for(auto &x : rects) {
						if(smaller(x, v)) {
							ok = false;
							break;
						} else if(!smaller(v, x)) {
							nrects.push_back(x);
						}
					}
					if(ok) {
						nrects.push_back(v);
						rects = nrects;
					}
				}
			}
		}
		assert(rects.size() == 2);
		sort(rects.begin(), rects.end());
		vi a = rects[0], b = rects[1];
		printf("! %d %d %d %d %d %d %d %d\n",
			a[0] + 1, a[1] + 1, a[2], a[3],
			b[0] + 1, b[1] + 1, b[2], b[3]
			);
		fflush(stdout);
		break;
	}
	return 0;
}