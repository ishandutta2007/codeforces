#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <climits>
#include <complex>
#include <ctime>
#include <random>
#include <functional>
#include <chrono>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, m, p;
ll f[2000001];
ll g[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) cin >> f[i];
    for (int i = 0; i < m; i++) cin >> g[i];

    int l = 0, r = 0;

    for (int i = 0; i < n + m - 1; i++)
    {
        if (f[l] % p == 0) l++;
        else if (g[r] % p == 0) r++;
        else
        {
            cout << i;
            return 0;
        }
    }
}