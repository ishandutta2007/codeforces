#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
typedef double ld;
#define uint unsigned int

const int maxn = (int)1e5 + 10;
int v[maxn];

int main() {
    int n, d, m;

    cin >> n >> d >> m;

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    sort(v, v + n);

    vector <int> a, b;

    for (int i = 0; i < n; i++) {
        if (v[i] <= m) {
            a.push_back(v[i]);
        }
        else {
            b.push_back(v[i]);
        }
    }

    ll sum = 0;

    vector <ll> sums;
    sums.push_back(0);

    for (int i = (int)a.size() - 1; i >= 0; i--) {
        sum += a[i];
        sums.push_back(sum);
    }

    sum = 0;

    reverse(all(b));

    ll ans = sums.back();

    for (int i = 1; i <= (int)b.size(); i++) {
        sum += b[i - 1];
        if (d * i + i < (int)b.size()) {
            continue;
        }

        if (d * (i - 1) + i > n) {
            break;
        }

        int tot = (int)a.size();

        if (d * (i - 1) + i > (int)b.size()) {
            tot -= (d * (i - 1) + i - (int)b.size());
        }

        ans = max(ans, sum + sums[tot]);
    }

    cout << ans << '\n';
}