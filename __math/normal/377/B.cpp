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

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

struct P{
	int first, second, third;
	bool operator< (const P& r) const{
		return first != r.first ? first < r.first : second < r.second;
	}
};

int n, m, s;
Pii a[ten(5)];
P b[ten(5)];

int min_cost_id[ten(5)];
int ans[ten(5)];

bool C(int md){
	priority_queue<Pii, vector<Pii>, greater<Pii>> q;
	ll current_s = 0;
	int id = n - 1;
	for (int i = m - 1; i >= 0; i -= md){
		int target = a[i].first; //x
		while (id >= 0 && b[id].first >= target){
			q.push(Pii(b[id].second, b[id].third)); //cost,id
			id--;
		}

		if (q.empty()) return false;
		Pii p = q.top(); q.pop();
		current_s += p.first;
		if (current_s > s) return false;
		for (int j = 0; j < md; j++){
			if (i - j < 0) break;
			ans[a[i - j].second] = p.second;
		}
	}
	return true;
}

int main(){
	cin >> n >> m >> s;
	FOR(i, m) cin >> a[i].first, a[i].second = i;
	FOR(i, n) cin >> b[i].first;
	FOR(i, n) cin >> b[i].second;
	FOR(i, n) b[i].third = i + 1;

	sort(a, a + m);
	sort(b, b + n);
	if (!C(m)){
		puts("NO");
		return 0;
	}

	int l = 0, r = m;
	while (r - l != 1){
		int md = (l + r) / 2;
		if (C(md)) r = md;
		else l = md;
	}

	C(r); //L

	puts("YES");
	FOR(i, m) printf("%d%c", ans[i], i == m - 1 ? '\n' : ' ');

	return 0;
}