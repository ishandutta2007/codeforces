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

template<typename Char, typename Index>
void buildKMPTable(const Char p[/*m*/], int m, Index fail[/*m+1*/]) {
	fail[0] = -1;
	for(int j = 0, t = -1; j < m; ) {
		while(t >= 0 && p[j] != p[t])
			t = fail[t];
		++ t, ++ j;
		fail[j] = j < m && p[j] == p[t] ? fail[t] : t;
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	char *S = new char[n+1], *T = new char[m+1];
	scanf("%s", S);
	scanf("%s", T);
	const int A = 26;
	vector<vi> fails(A);
	rep(a, A) {
		vector<char> t(m);
		rep(i, m) t[i] = T[i] == 'a' + a;
		fails[a].resize(m+1);
		buildKMPTable(&t[0], m, &fails[a][0]);
	}
	vector<vector<unsigned> > matches(A, vector<unsigned>(n, 0));
	rep(a, A) rep(b, A) {
		for(int i = 0, k = 0; i < n; i ++) {
			while(k >= 0 && (T[k] == 'a' + a) != (S[i] == 'a' + b)) k = fails[a][k];
			if(++ k == m) {
				matches[a][i-m+1] |= 1U << b;
				k = fails[a][k];
			}
		}
	}
	vector<int> indices(A, -1);
	rep(i, m) if(indices[T[i] - 'a'] == -1)
		indices[T[i] - 'a'] = i;
	vi ans;
	vector<int> pairs(A);
	rer(i, 0, n - m) {
		bool ok = true;
		pairs.assign(A, -1);
		rep(a, A) {
			int j = indices[a];
			if(j == -1) continue;
			int b = S[i + j] - 'a';
			if(pairs[a] != -1) {
				ok &= b == pairs[a];
			}else {
				ok &= pairs[b] == -1;
				pairs[a] = b;
				pairs[b] = a;
			}
			ok &= matches[a][i] >> b & 1;
		}
		if(ok)
			ans.push_back(i);
	}
	printf("%d\n", (int)ans.size());
	rep(i, ans.size()) {
		if(i != 0) putchar(' ');
		printf("%d", ans[i] + 1);
	}
	puts("");
	return 0;
}