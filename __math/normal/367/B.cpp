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
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int n, m, p;
int a[ten(5) * 2], b[ten(5) * 2];
int s[ten(5) * 4];

int main(){
	cin >> n >> m >> p;
	FOR(i, n) cin >> a[i];
	FOR(i, m) cin >> b[i];

	vector<int> press;
	FOR(i, n) press.push_back(a[i]);
	FOR(i, m) press.push_back(b[i]);
	sort(press.begin(), press.end());
	press.erase(unique(press.begin(), press.end()), press.end());
	FOR(i, n) a[i] = lower_bound(press.begin(), press.end(), a[i]) - press.begin();
	FOR(i, m) b[i] = lower_bound(press.begin(), press.end(), b[i]) - press.begin();

	FOR(i, m)s[b[i]]++;
	int sm = 0;
	FOR(i, ten(5) * 4) if (s[i]) sm++;

	vector<int> ans;

	FOR(start, p){
		if (start + (m - 1) *(ll)p > (ll)n) break;
		int cur = sm;
		int _q = start;
		int q;
		for (q = start; q < n; q += p){
			int pq = q - m*p;
			if (pq >= 0){
				_q += p;
				s[a[pq]]++;
				if (s[a[pq]] == 0) cur--;
				else if (s[a[pq]] == 1) cur++;
			}
			s[a[q]]--;
			if (s[a[q]] == 0) cur--;
			else if (s[a[q]] == -1) cur++;
			if (cur == 0) ans.push_back(_q);
		}
		for (int pq = q - m*p; pq < n; pq += p) s[a[pq]]++;
	}

	sort(ans.begin(), ans.end());

	cout << sz(ans) << endl;
	FOR(i, sz(ans)) printf("%d%c", ans[i]+1, i == sz(ans) - 1 ? '\n' : ' ');

	return 0;
}