#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <iomanip>

using namespace std;

mt19937 Rand(16092002);
mt19937_64 BigRand(16092002);

typedef long long ll;

const int M = 1e9 + 7;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    vector <int> pw(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pw[i] = (pw[i - 1] * (ll) 2) % M;
    }
    vector <int> x(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
    sort(x.begin(), x.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = pw[i];
        cur = (cur * (ll) x[i]) % M;
        ans = (ans + cur) % M;
    }
    for (int i = 0; i < n; i++)
    {
        int cur = pw[n - 1 - i];
        cur = (cur * (ll) x[i]) % M;
        ans = (ans - cur + M) % M;
    }
    printf("%d\n", ans);
}