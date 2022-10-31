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

const int N = 100000;

vector<long long> divisors;
vector<vector<int> > subdivisors;
vector<long long> ans;

bool rec(int di, int k) {
	if(k == 0 || di == 0) {	//d = 1 
		ans.push_back(divisors[di]);
		return (int)ans.size() < N;
	}
	each(dj, subdivisors[di]) {
		if(!rec(*dj, k-1))
			return false;
	}
	return true;
}

int main() {
	long long X, k;
	cin >> X >> k;
	if(X == 1) {
		puts("1");
		return 0;
	}
	divisors.clear();
	for(int i = 1; i <= X / i; i ++) if(X % i == 0) {
		divisors.push_back(i);
		if((long long)i * i == X) continue;
		divisors.push_back(X / i);
	}
	sort(all(divisors));
	int D = divisors.size();
	subdivisors.assign(D, vector<int>());
	rep(i, D) {
		rer(j, 0, i) if(divisors[i] % divisors[j] == 0)
			subdivisors[i].push_back(j);
	}
	ans.clear();
	rec(D-1, (int)min(k, N + 2LL));
	rep(i, ans.size()) {
		if(i != 0) putchar(' ');
		printf("%I64d", ans[i]);
	}
	puts("");
	return 0;
}