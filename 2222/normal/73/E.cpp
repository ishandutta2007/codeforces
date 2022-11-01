#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <bitset>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n, x;
int a[111111];
bitset <2000222> p;

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> x;
	REP (i, n) scanf("%d", a + i);
	x = min(x, 2000000);
	for (int i = 2; i * i < x; ++i) 
		if (!p[i])
			for (int j = i * i; j < x; j += i)
				p.set(j);
	int res = 0;
	bool one = false;
	REP (i, n) {
		int z = a[i];
		if (2 <= z && z < x) {
			if (!p[z]) {
				p.set(z);
				++res;
			}
		} else if (z == 1) one = true;
	}
	for (int i = 2; i < x; ++i)
		if (!p[i]) {
			puts(one ? "1" : "-1");
			return 0;
		}
	if (one) res = min(res, 1);
	cout << res << endl;
	return 0;
}