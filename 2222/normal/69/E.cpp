#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
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

int n, m;
int a[111111];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m;
	REP (i, n) scanf("%d", a + i);
	map <int ,int> f;
	set <int> s;
	for (int i = 0; i < n; ++i) {
		if (i - m >= 0) {
			if (--f[a[i - m]] == 0) s.erase(a[i - m]);
			else if (f[a[i - m]] == 1) s.insert(a[i - m]);
		}
		if (++f[a[i]] == 2) s.erase(a[i]);
		else if (f[a[i]] == 1) s.insert(a[i]);
		if (i >= m - 1) {
			if (s.size())
				printf("%d\n", *s.rbegin());
			else 
				puts("Nothing");
		}
	}
	return 0;
}