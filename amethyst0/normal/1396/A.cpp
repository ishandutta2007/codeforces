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
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)1e5 + 10;
ll v[maxn];
int n;

void build(int l, int r) {
    if (l > r) {
        cout << 1 << ' ' << 1 << '\n' << 0 << '\n';
        return;
    }

    cout << l + 1 << ' ' << r + 1 << '\n';

    for (int i = l; i <= r; i++) {
        ll x = v[i] % n;
        if (x < 0) {
            x += n;
        }

        v[i] += x * (n - 1);
        printf("%lld ", x * (n - 1));
    }

    printf("\n");
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
        //v[i] = -rand();
    }

    build(0, n - 2);
    build(1, n - 1);

    cout << 1 << ' ' << n << '\n';

    for (int i = 0; i < n; i++) {
        assert(v[i] % n == 0);
        printf("%lld ", -v[i]);
    }

    printf("\n");
}