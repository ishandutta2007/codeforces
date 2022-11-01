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

int n, m, k;
int a[100500];
int b[100500];

int main() {
    for (; cin >> n >> m >> k; ) {
		REP (i, n) {
			scanf("%d", a + i);
			b[--a[i]] = i;
		}
		ll res = 0;
		REP (i, m) {
			int x;
			scanf("%d", &x);
			int j = b[--x];
			res += j / k + 1;
			if (j > 0) {
				swap(a[j - 1], a[j]);
				b[a[j - 1]] = j - 1;
				b[a[j]] = j;
			}
		}
		cout << res << endl;
	}
    return 0;
}