#include <algorithm>
#include <iostream>
#include <assert.h>
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

int main() {
    for (int n; cin >> n; ) {
		int s1 = 0, s2 = 0;
		vector<int> odd;
		REP (i, n) {
			int k;
			scanf("%d", &k);
			vi a(k);
			REP (j, k) scanf("%d", &a[j]);
			s1 += accumulate(a.begin(), a.begin() + (k / 2), 0);
			s2 += accumulate(a.end() - (k / 2), a.end(), 0);
			if (k % 2) odd.pb(a[k / 2]);
		}
		sort(odd.rbegin(), odd.rend());
		REP (i, sz(odd))
			(i & 1 ? s2 : s1) += odd[i];
		cout << s1 << ' ' << s2 << endl;
	}
    return 0;
}