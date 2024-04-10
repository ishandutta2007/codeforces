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

char memo[601][601];
vector<int> L, R;
string anss;

char rec(int i, int j) {
	if(i > j) return 1;
	char &r = memo[i][j];
	if(r != -1) return r;
	r = 0;
	int Li = L[i], Ri = R[i];
	int cnt = j - i;
	rer(k, 0, cnt) if(Li <= 1 + k * 2 && 1 + k * 2 <= Ri)
		r |= rec(i + 1, i + k) & rec(i + k + 1, j);
	return r;
}
void rec_construct(int i, int j) {
	if(i > j) return;
	int Li = L[i], Ri = R[i];
	int cnt = j - i;
	rer(k, 0, cnt) if(Li <= 1 + k * 2 && 1 + k * 2 <= Ri) {
		if(rec(i + 1, i + k) & rec(i + k + 1, j)) {
			anss += '(';
			rec_construct(i + 1, i + k);
			anss += ')';
			rec_construct(i + k + 1, j);
			return;
		}
	}
	cerr << "err" << endl;
}


int main() {
	int n;
	scanf("%d", &n);
	L.resize(n), R.resize(n);
	rep(i, n) scanf("%d%d", &L[i], &R[i]);
	mset(memo, -1);
	char ans = rec(0, n-1);
	if(ans == 0) {
		puts("IMPOSSIBLE");
	}else {
		anss.clear();
		rec_construct(0, n-1);
		puts(anss.c_str());
	}
	return 0;
}