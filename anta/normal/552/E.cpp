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


int main() {
	string s;
	while(cin >> s) {
		int n = (int)(s.size() + 1) / 2;
		vector<vector<ll> > val(n+1, vector<ll>(n+1));
		rer(i, 0, n) {
			ll x = 0, prod = 0;
			rer(j, i+1, n) {
				char d = s[(j-1) * 2], op = j == i+1 ? '+' : s[(j-1) * 2 - 1];
				if(op == '+') {
					x += prod;
					prod = d - '0';
				}else {
					prod *= d - '0';
				}
//				cerr << "val " << s.substr(i * 2, (j - i) * 2 - 1) << ": " << x + prod << endl;
				val[i][j] = x + prod;
			}
		}
		vector<pair<ll,ll> > left(n), right(n+1);
		{	ll prod = 1, add = 0;
			rep(i, n) {
				left[i] = mp(prod, add);
				char d = s[i * 2], op = i == n-1 ? '+' : s[i * 2 + 1];
				if(op == '+')
					prod = 1, add = val[0][i+1];
				else
					prod *= d - '0';
			}
		}
		{	ll prod = 1, add = 0;
			right[n] = mp(1, 0);
			for(int i = n-1; i >= 0; -- i) {
				char d = s[i * 2], op = i == 0 ? '+' : s[i * 2 - 1];
				if(op == '+')
					prod = 1, add = val[i][n];
				else
					prod *= d - '0';
				right[i] = mp(prod, add);
			}
		}
		ll ans = val[0][n];
		rep(i, n) {
			rer(j, i+1, n) {
//				cerr << s.substr(0, i * 2) << '(' << s.substr(i * 2, (j - i) * 2 - 1) << ')' << s.substr(j * 2 - 1) << ": ";
				ll x = left[i].second + left[i].first * val[i][j] * right[j].first + right[j].second;
//				cerr << left[i].second << " + " << left[i].first << " * " << val[i][j] << " * " << right[j].first << " + " << right[j].second << " = " << x << endl;
				amax(ans, x);
			}
		}
		cout << ans << endl;
	}
	return 0;
}