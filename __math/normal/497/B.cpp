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
int a[ten(5)];
vector<int> v[2];
int a2v[2][ten(5)+3];

Pii check(int cur, int s){
	if (cur == n) return Pii(0, 0);
	int nwin = 0,nxt = -1;
	for (; nwin < 2; nwin++) {
		int sum = a2v[nwin][cur];
		if (sum + s - 1 >= sz(v[nwin])) continue;
		int nxt_id = v[nwin][sum + s - 1] + 1;
		int sev = nxt_id - cur;
		int other_win = sev - s;
		if (other_win >= s) continue;
		nxt = nxt_id;
		break;
	}
	if (nxt == -1) return Pii(-1, -1);
	Pii p = check( nxt, s);
	if (p.first == -1) return p;

	if (nwin == 0) p.first++;
	else p.second++;
	return p;
}

int main(){
	cin >> n;
	FOR(i, n) cin >> a[i];
	FOR(i, n) a[i]--;
	if (a[n - 1] == 1) FOR(i, n) a[i] ^= 1; // last = 0
	FOR(i, n) v[a[i]].push_back(i);
	FOR(i, n) a2v[a[i]][i+1]++;
	FOR(i, 2) FOR(j, ten(5) + 2){
		a2v[i][j + 1] += a2v[i][j];
	}

	vector<Pii> anses;
	Pii wn;
	for (int i = 1; i <= n; i++) {
		Pii p = check(0, i);
		if (p.first != -1 && p.first > p.second) {
			anses.emplace_back(p.first, i);
		}
	}
	sort(anses.begin(), anses.end());

	printf("%d\n", sz(anses));
	for (auto kv : anses) {
		printf("%d %d\n", kv.first, kv.second);
	}
}