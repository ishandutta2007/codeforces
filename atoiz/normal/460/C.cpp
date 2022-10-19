#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define SZ(x) (int)(x).size()

const int MAX = 100007;
int n, m, w;
vector<long long> D, A, a, d;

bool check(long long x)
{
	d = D;
    a.assign(n+1, 0);
    long long times = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i-1] + d[i];
        if (x <= a[i]) continue;

        long long cur = x - a[i];
        times += cur;
        d[i] += cur;
        if (i + w <= n) d[i+w] -= cur;

        a[i] = a[i-1] + d[i];
    }

    return times <= m;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> w;
    D.assign(n+1, 0);
    A.assign(n+1, 0);
    for (int i = 1; i <= n; ++i) {
		cin >> A[i];
        D[i] = A[i] - A[i-1];
    }

    long long l = 0, r = 1e17;
    while (l < r) {
        int m = (l + r + 1) >> 1;
        if (check(m)) l = m;
        else r = m-1;
    }
    cout << l;
}