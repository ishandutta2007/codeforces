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

const int Alphas = 26;

int fromExcelNumbering(const string &s) {
	int n = (int)s.size();
	int r = 0, a = 1;
	rep(i, n) {
		r += a;
		a *= Alphas;
	}
	a = 1;
	rep(i, n) {
		r += (s[n - 1 - i] - 'A') * a;
		a *= Alphas;
	}
	return r;
}

string toExcelNumbering(int x) {
	string r;
	int n = 0, a = 1;
	while(x >= a) {
		x -= a;
		a *= Alphas;
		++ n;
	}
	r.resize(n);
	rep(i, n) {
		r[n - 1 - i] = 'A' + x % Alphas;
		x /= Alphas;
	}
	return r;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		rep(ii, n) {
			string s;
			cin >> s;
			size_t i = s.find('C');
			string ans;
			if(i != string::npos && 0 < i && isdigit(s[i - 1])) {
				string r = s.substr(1, i), c = s.substr(i+1);
				int R = atoi(r.c_str());
				int C = atoi(c.c_str());
				string cc = toExcelNumbering(C);
				printf("%s%d\n", cc.c_str(), R);
			} else {
				i = 0;
				while(!isdigit(s[i])) ++ i;
				int x = fromExcelNumbering(s.substr(0, i));
				string r = s.substr(i);
				printf("R%sC%d\n", r.c_str(), x);
			}
		}
	}
	return 0;
}