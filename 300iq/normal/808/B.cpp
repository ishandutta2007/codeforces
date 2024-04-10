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

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    ll res = sum;
    for (int i = 0; i + k < n; i++)
    {
        sum -= a[i];
        sum += a[i + k];
        res += sum;
    }
    cout << fixed << setprecision(20) << res / (double) (n - k + 1) << endl;
}