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
template<class T> void chmax(T& a, T b) { a = max(a, b); }
template<class T> void chmin(T& a, T b) { a = min(a, b); }

#pragma comment(linker,"/STACK:36777216")

const int MOD = ten(9) + 9;

vector<int> e[ten(5) + 10],re[ten(5) + 10];
int up[ten(5) + 10];

int main(){
	int m; scanf("%d", &m);
	vector<Pii> v;
	FOR(i, m){
		int x, y; scanf("%d%d", &x, &y);
		v.emplace_back(x, y);
	}

	map<Pii, int> mp;
	FOR(i, m) mp[v[i]] = i;
	FOR(i, m){
		for (int dx = -1; dx <= 1; dx++) {
			auto it = mp.find(Pii(v[i].first + dx, v[i].second - 1));
			if (it != mp.end()) {
				e[i].push_back(it->second);
				re[it->second].push_back(i);
			}
		}
	}

	FOR(i, m) for (auto to : e[i]) up[to]++;
	set<int> ids;
	FOR(i, m){
		bool ok = true;
		for (auto fr : re[i]) if (sz(e[fr]) == 1) ok = false;
		if (ok) ids.insert(i);
	}

	static bool used[ten(5)];
	vector<ll> ans;
	FOR(_i, m){
		int ch = -1;
		if (_i % 2 == 0) ch = *ids.rbegin();
		else ch = *ids.begin();

		ans.push_back(ch);
		ids.erase(ch);
		used[ch] = true;
		static vector<int> check_list;
		check_list.clear();
		for (auto to : e[ch]) {
			if(!used[to]) check_list.push_back(to);
		}
		for (auto par : re[ch]) {
			if (!used[par]) {
				for (auto to : e[par]) {
					if (!used[to]) check_list.push_back(to);
				}
			}
		}
		for (auto o : check_list) {
			bool ok = true;
			for (auto parent : re[o]) {
				if (used[parent]) continue;
				int cnt = 0;
				for (auto to : e[parent]) {
					if (!used[to]) cnt++;
				}
				if (cnt == 1) ok = false;
			}
			if (ok) ids.insert(o);
			else {
				auto it = ids.find(o);
				if (it != ids.end()) ids.erase(it);
			}
		}
	}

	ll out = 0;
	FOR(i,m) {
		(out = out * m + ans[i]) %= MOD;
	}

	cout << out << endl;
}