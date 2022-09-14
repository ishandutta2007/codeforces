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
typedef double ld;
#define uint unsigned int

const int maxn = (int)2e5 + 10;
ll a[maxn], b[maxn];
vector <pair <ll, pii> > e;
int p[maxn];

int getp(int x) {
    return (p[x] == x ? x : p[x] = getp(p[x]));
}

int main() {
    int n, m;

    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }

    ll sum = 0;

    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);

        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            x--;
            e.push_back(mp(a[i] + b[x], mp(x, n + i)));
        }
    }

    sort(all(e));
    reverse(all(e));

    for (int i = 0; i < n + m; i++) {
        p[i] = i;
    }

    for (auto f : e) {
        int x = f.second.first;
        int y = f.second.second;
        x = getp(x);
        y = getp(y);
        if (x == y) {
            sum += f.first;
        }
        else {
            p[x] = y;
        }
    }

    cout << sum << '\n';
}