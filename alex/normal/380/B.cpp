#pragma comment(linker, "/STACK:600000000")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>

#include <ctime>
#include <cassert>

using namespace std;

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "b";

const int NMAX = 7010;

int n, q, cnt[NMAX];
int a[NMAX], b[NMAX], c[NMAX], d[NMAX], tp[NMAX], l[NMAX], r[NMAX];
vector<int> ans;
int used[1010100], L[100 * NMAX], R[100 * NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> q;
cnt[1] = 1;
	seta(L, 255);
	seta(R, 255);
for(int level = 1; level < n; level = level + 1){
    cnt[level + 1] = 0;
    for(int position = 1; position <= cnt[level]; position = position + 1){
        if(!(position & (position - 1))){
            L[position] = cnt[level + 1] + 1;
            R[position] = cnt[level + 1] + 2;
            cnt[level + 1] = cnt[level + 1] + 2;            
        }else{
            R[position] = cnt[level + 1] + 1;
            L[position] = R[position];
            cnt[level + 1] = cnt[level + 1] + 1;
        }
    }
}

	seta(used, 0);
	forn(i, q) {
		scanf("%d", &tp[i]);
		if (tp[i] == 1) {
			scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
		}
		else {
			int x, y;
			scanf("%d%d", &x, &y);
			forn(j, ans.size())
				used[ans[j]] = 0;
			ans.clear();
			l[0] = y, r[0] = y;
			forn(j, n - x + 1) 
				if (j) {
					l[j] = L[l[j - 1]], r[j] = R[r[j - 1]];
				}
				
			forn(j, i)
				if (tp[j] == 1 && a[j] >= x) {
					if (!(b[j] > r[a[j] - x] || c[j] < l[a[j] - x]))
						if (!used[d[j]]) {
							used[d[j]] = 1;
							ans.pb(d[j]);
						}
				}
			printf("%d\n", ans.size());
		}
	}
	
	return 0;
}