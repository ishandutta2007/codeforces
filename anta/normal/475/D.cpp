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

template<typename T>T gcd(T x, T y){if(y==0)return x;else return gcd(y,x%y);}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	map<int,long long> cur, nx, total;
	rep(i, n) {
		nx.swap(cur);
		nx.clear();
		nx[a[i]] += 1;
		total[a[i]] += 1;
		each(j, cur) {
			int g = gcd(j->first, a[i]);
			nx[g] += j->second;
			total[g] += j->second;
		}
	}
	int q;
	scanf("%d", &q);
	rep(ii, q) {
		int x;
		scanf("%d", &x);
		long long ans = total[x];
//		cerr << x << ": " << ans << endl;
		cout << ans << '\n';
	}
	return 0;
}