#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <vector>
#include <cstdio>
#include <random>
#include <chrono>
#include <queue>
#include <cmath>
#include <list>
#include <set>
#include <map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef pair<long long, int> pli;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> base;

/*
int a[20], b[20], c[20], n;

void flip(int x) {
    a[x] -= 2;
    if (x == 0) {
        a[x + 1]++;
        a[n - 1]++;
    } else {
        a[(x + 1) % n]++;
        a[x - 1]++;
    }
}

bool check() {
    for (int i = 0; i < 200; ++i) {
        int x = rand() % n;
        if (a[x] > 1) {
            flip(x);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 2) return false;
    }
    return true;
}

void rec() {
    for (int i = 0; i < n; ++i) b[i] = a[i];
    for (int j = 0; j < 100; ++j) {
        int x = rand() % n;
        int y = rand() % n;
        swap(a[x], a[y]);
        for (int i = 0; i < n; ++i) c[i] = a[i];
        if (check()) {
            for (int i = 0; i < n; ++i) {
                cout << c[i] << ' ';
            }
            cout << endl;
        }
        for (int i = 0; i < n; ++i) a[i] = c[i];
    }
    cout << endl;
    for (int i = 0; i < n; ++i) a[i] = b[i];
    int pos = 0;
    for (int i = n - 1; i >= 1; --i) {
        if (a[i] < a[i - 1] && a[i - 1] != 1) {
            a[i - 1]--;
            a[i]++;
            while (a[i] > a[i - 1]) {
                a[i]--;
                a[i + 1]++;
                i++;
            }
            pos = 1;
            break;
        }
    }
    if (pos) {
        rec();
    }
}



void solve() {
    n = 7;
    a[0] = n;
    rec();
}

*/

const int mod = 1e9 + 7;

void solve() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        long long n;
        scanf("%lld", &n);
        printf("%lld\n", (1 + (n / 4) % mod * ((n / 4 + 1) % mod) + ((n % 4 < 2) ? n / 4 : n / 2)) % mod);
    }
}


int main() {
#ifdef HAMLET
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}