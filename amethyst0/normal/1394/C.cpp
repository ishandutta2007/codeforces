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

const int maxn = (int)5e5 + 10;
pii v[maxn];
char s[maxn];

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("%s", s);

        int a = 0, b = 0;

        int len = 0;

        while (s[len]) {
            if (s[len] == 'N') {
                a++;
            }
            else {
                b++;
            }
            len++;
        }

        v[i] = mp(a, b);
    }

    int l = 0;
    int r = (int)1e8 + 10;

    const int inf = (int)1e8;

    while (l != r) {
        int m = (l + r) >> 1;

        int lx = 0, rx = inf, ly = 0, ry = inf;
        int lxy = -inf, rxy = inf;

        for (int i = 0; i < n; i++) {
            lx = max(lx, v[i].first - m);
            rx = min(rx, v[i].first + m);
            ly = max(ly, v[i].second - m);
            ry = min(ry, v[i].second + m);
            lxy = max(lxy, v[i].second - v[i].first - m);
            rxy = min(rxy, v[i].second - v[i].first + m);
        }

        lxy = max(lxy, ly - rx);
        rxy = min(rxy, ry - lx);

        if (lx <= rx && ly <= ry && lxy <= rxy) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }

    cout << l << '\n';

    int lx = 0, rx = inf, ly = 0, ry = inf;
    int lxy = -inf, rxy = inf;

    int m = l;

    for (int i = 0; i < n; i++) {
        lx = max(lx, v[i].first - m);
        rx = min(rx, v[i].first + m);
        ly = max(ly, v[i].second - m);
        ry = min(ry, v[i].second + m);
        lxy = max(lxy, v[i].second - v[i].first - m);
        rxy = min(rxy, v[i].second - v[i].first + m);
    }

    lxy = max(lxy, ly - rx);
    rxy = min(rxy, ry - lx);

    int x = -1;
    int y = -1;

    for (int i = ly; i <= ry; i++) {
        if (lxy <= i - lx && i - lx <= rxy) {
            x = lx;
            y = i;
            break;
        }
    }

    for (int i = lx; i <= rx; i++) {
        if (lxy <= ly - i && ly - i <= rxy) {
            x = i;
            y = ly;
            break;
        }
    }

    assert(x != -1);

    if (x == 0 && y == 0) {
        printf("BN");
    }

    while (x && y) {
        printf("NB");
        x--;
        y--;
    }

    while (x) {
        printf("N");
        x--;
    }

    while (y) {
        printf("B");
        y--;
    }
}