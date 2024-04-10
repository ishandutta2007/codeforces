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

int p[ten(3) * 3];
int psum[ten(3) * 3 + 10];

bool ok[ten(3) * 3 + 3][ten(3) * 3 + 3];

int main(){
	int n, k; cin >> n >> k;
	FOR(i, n) cin >> p[i];
	FOR(i, n) if (p[i] == 100) p[i] = 2; else if(p[i] != 0) p[i] = 1;
	for(int i = n; i > 0; i--){
		if (p[i - 1] == 2 || psum[i] == 2) psum[i - 1] = 2;
		else if (p[i - 1] == 0 && psum[i] == 0) psum[i - 1] = 0;
		else psum[i - 1] = 1;
	}

	if (n == 1){
		puts("1");
		return 0;
	}
	queue<Pii> q;
	q.emplace(0, 1);
	ok[0][1] = true;
	int ans = 1;
	FOR(i, k){
		int s = q.size();
		FOR(j, s){
			Pii t = q.front(); q.pop();
			if (t.first >= n - 1 || t.second >= n) continue;

			//if (psum[t.second] <= 1 && p[t.first] <= 1)
			if (psum[t.second] >= 1 && p[t.first] <= 1){
				if (!ok[t.second][t.second + 1]){
					ans++;
					ok[t.second][t.second + 1] = true;
					q.emplace(t.second, t.second + 1);
				}
			}
			if (psum[t.second] <= 1 && p[t.first] >= 1){
				if (!ok[t.first][t.second + 1]){
					ans++;
					ok[t.first][t.second + 1] = true;
					q.emplace(t.first, t.second + 1);
				}
			}
			if (psum[t.second] >= 1 && p[t.first] >= 1){
				if (!ok[t.second + 1][t.second + 2]){
					ans++;
					ok[t.second + 1][t.second + 2] = true;
					q.emplace(t.second + 1, t.second + 2);
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}