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

struct FenwickTree {
	typedef int T;
	vector<T> v;
	FenwickTree(int n): v(n, 0) {}
	void add(int i, T x) {
		for(; i < (int)v.size(); i |= i+1) v[i] += x;
	}
	T sum(int i) {	//[0, i)
		T r = 0;
		for(-- i; i >= 0; i = (i & (i+1)) - 1) r += v[i];
		return r;
	}
	T sum(int left, int right) {	//[left, right)
		return sum(right) - sum(left);
	}
};



int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> paper(n, 1);
	int left = 0, right = n;
	bool reversed = false;
	FenwickTree ft(n);
	rep(i, n) ft.add(i, 1);

	rep(ii, q) {
//		rep(i, right - left) cerr << paper[!reversed ? left+i : right-1-i] << ", "; cerr << endl;
		int ty;
		scanf("%d", &ty);
		if(ty == 1) {
			int p;
			scanf("%d", &p);
			int w = right - left;
			if(p * 2 > w) {
				reversed ^= true;
				p = w - p;
			}
			if(!reversed) {
				rep(i, p) {
					int x = paper[left+i];
					paper[left+p+(p-1-i)] += x;
					ft.add(left+p+(p-1-i), x);
				}
				left += p;
			}else {
				rep(i, p) {
					int x = paper[right-1-i];
					paper[right-1-p-(p-1-i)] += x;
					ft.add(right-1-p-(p-1-i), x);
				}
				right -= p;
			}
		}else {
			int l, r;
			scanf("%d%d", &l, &r);
			int ans = 0;
			if(!reversed) {
//				reu(i, l, r) ans += paper[left+i];
				ans = ft.sum(left + l, left + r);
			}else {
//				reu(i, l, r) ans += paper[right-1-i];
				ans = ft.sum(right - r, right - l);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}