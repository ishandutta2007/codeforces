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
#include <functional>
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
	int H, W;
	scanf("%d%d", &H, &W);
	vector<vi> B(H, vi(W));
	rep(i, H) rep(j, W)
		scanf("%d", &B[i][j]);
	vi row(H), col(W);
	rep(i, H) rep(j, W) {
		row[i] += B[i][j];
		col[j] += B[i][j];
	}
	vector<vi> A(H, vi(W));
	rep(i, H) rep(j, W)
		A[i][j] = row[i] == W && col[j] == H;
	vi rowA(H), colA(W);
	rep(i, H) rep(j, W) {
		rowA[i] += A[i][j];
		colA[j] += A[i][j];
	}
	bool ok = true;
	rep(i, H) rep(j, W)
		ok &= (B[i][j] != 0) == (rowA[i] != 0 || colA[j] != 0);
	if(!ok) {
		puts("NO");
	}else {
		puts("YES");
		rep(i, H) {
			rep(j, W) {
				if(j != 0) putchar(' ');
				printf("%d", A[i][j]);
			}
			puts("");
		}
	}
	return 0;
}