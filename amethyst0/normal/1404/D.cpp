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

const int maxn = (int)1e6 + 10;

vector <int> ed[maxn];
int g[maxn][2];
int pos[maxn];
bool used[maxn];
bool us[maxn];
pii wh[maxn];

int n;

void take(int x) {
    us[x] = true;
    used[wh[x].first] = true;
    int ps = wh[x].first;
    int it = wh[x].second;
    it ^= 1;
    x = g[ps][it];
    if (x < n) {
        x += n;
    }
    else {
        x -= n;
    }

    if (us[x]) {
        return;
    }

    assert(!used[wh[x].first]);
    take(x);
}

int main() {
    cin >> n;

    if (n % 2 == 0) {
        cout << "First" << endl;

        for (int i = 0; i < 2 * n; i++) {
            printf("%d ", i % n + 1);
        }

        cout << endl;
        int x;
        cin >> x;
        assert(x == 0);
        return 0;
    }

    cout << "Second" << endl;

    for (int i = 0; i < 2 * n; i++) {
        int w;
        scanf("%d", &w);
        w--;
        g[w][pos[w]++] = i;
        wh[i] = mp(w, pos[w] - 1);
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }

        take(g[i][0]);
    }

    ll sum = 0;

    for (int i = 0; i < 2 * n; i++) {
        if (us[i]) {
            sum += i + 1;
        }
    }

    bool ok = false;

    if (sum % (2 * n) == 0) {
        ok = true;
    }

    for (int i = 0; i < 2 * n; i++) {
        if (us[i] == ok) {
            printf("%d ", i + 1);
        }
    }

    cout << endl;
    int x;
    cin >> x;
    assert(x == 0);
}