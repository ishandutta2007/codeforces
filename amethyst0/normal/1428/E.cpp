#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int

const int maxn = (int)1e5 + 10;
int v[maxn];

ll calc(int x, int k) {
    ll val = x / k;
    int cnt = k - x % k;
    return (ll)cnt * val * val + (ll)(k - cnt) * (val + 1) * (val + 1);
}

int main() {
    int n, k;
    cin >> n >> k;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        ans += (ll)v[i] * v[i];
    }

    k -= n;

    set <pair <ll, pii> > s;

    for (int i = 0; i < n; i++) {
        if (v[i] > 1) {
            s.insert(mp(calc(v[i], 1) - calc(v[i], 2), mp(i, 2)));
        }
    }

    while (k--) {
        auto f = *s.rbegin();
        s.erase(f);
        ans -= f.first;

        int i = f.second.first;
        int cnt = f.second.second;

        if (cnt < v[i]) {
            s.insert(mp(calc(v[i], cnt) - calc(v[i], cnt + 1), mp(i, cnt + 1)));
        }
    }

    cout << ans << '\n';
}