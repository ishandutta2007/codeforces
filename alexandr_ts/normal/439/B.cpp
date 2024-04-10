#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef long double ld;

ll a[1000000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, x;
    cin >> n >> x;
    ll s = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll ans = 0;
    for(ll i = 0; i < n; i++)
    {
        ans += x * a[i];
        x = max((ll)1, x - 1);
    }
    cout << ans;
    return 0;
}