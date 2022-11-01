#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

const long double EPS = 1e-9;

typedef long long ll;
typedef long double ld;

int a[1000000];

int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int ans = 100000000;
    ans = min(ans, a);
    ans = min(ans, b);
    ans = min(ans, c / 2);
    ans = min(ans, d / 7);
    ans = min(ans, e / 4);
    cout << ans;
    return 0;
}