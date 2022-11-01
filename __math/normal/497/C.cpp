#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int n;
int a[ten(5)], b[ten(5)];
int m;
int c[ten(5)], d[ten(5)], k[ten(5)];

struct P {
	int id;
	int c, d, k;
	P(){};
	P(int id, int c, int d, int k) : id(id), c(c),d(d),k(k){};
	bool operator<(const P& r) const {
		return c < r.c;
	}
};

int main(){
	scanf("%d", &n);
	FOR(i, n) scanf("%d%d", a + i, b + i);
	scanf("%d", &m);
	FOR(i, m) scanf("%d%d%d", c + i, d + i,k + i);

	vector<pair<Pii,int> > AB;
	FOR(i, n) AB.push_back(make_pair(Pii(a[i], b[i]),i));
	sort(AB.begin(), AB.end());

	vector<P> vp;
	FOR(i, m){
		vp.push_back(P(i + 1, c[i], d[i], k[i]));
	}
	sort(vp.begin(), vp.end());

	map<int, vector<P> > mp;
	int vp_cur = 0;
	bool ok = true;
	vector<int> anses(n, -1);
	for (auto ab : AB) {
		while (vp_cur < m && vp[vp_cur].c <= ab.first.first) {
			mp[vp[vp_cur].d].push_back(vp[vp_cur]);
			vp_cur++;
		}
		auto it = mp.lower_bound(ab.first.second);
		if (it == mp.end()) {
			ok = false;
			break;
		} else {
			auto& use_vc = it->second;
			P& use_p = use_vc.back();
			int ab_id = ab.second;
			int p_id = use_p.id;
			anses[ab_id] = p_id;
			use_p.k--;
			if (use_p.k == 0) {
				use_vc.pop_back();
				if (sz(use_vc) == 0) mp.erase(it);
			}
		}
	}

	if (!ok) {
		puts("NO");
	} else {
		puts("YES");
		FOR(i, sz(anses)) printf("%d ", anses[i]);
		puts("");
	}

}