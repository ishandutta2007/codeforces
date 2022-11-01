#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

ll a[1000000];

int main()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort (a, a + n);
    ll cur = 0;
    while (a[cur] == a[0])
        cur++;
    ll cur2 = n - 1;
    while (a[cur2] == a[n - 1])
        cur2--;
    if (cur == n)
    {cout << 0 << " " << n * (n - 1) / 2 << endl;return 0;}
    cur2 = n - cur2 - 1;
    cout << a[n - 1] - a[0] << " " << cur * cur2;
    return 0;
}