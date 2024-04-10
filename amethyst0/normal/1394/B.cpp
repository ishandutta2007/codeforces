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

mt19937 rr(time(NULL));

const int p = (int)1e9 + 7, q = (int)1e9 + 9;

int add(int x, int y, int mod) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
    return x;
}

int sub(int x, int y, int mod) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
    return x;
}

const int maxn = (int)2e5 + 10;

vector <pii> ed[maxn];

pii operator +(pii a, pii b) {
    a.first = add(a.first, b.first, p);
    a.second = add(a.second, b.second, q);
    return a;
}

pii hsh[100][100];
pii st[maxn];
int k;

int go(int pos, pii cur, pii nd) {
    if (pos == k) {
        return cur == nd;
    }

    int ans = 0;

    for (int i = 0; i <= pos; i++) {
        ans += go(pos + 1, cur + hsh[pos][i], nd);
    }
    return ans;
}

int main() {
    int n, m;

    st[0] = mp(1, 1);

    for (int i = 1; i < maxn; i++) {
        st[i] = mp((ll)st[i - 1].first * 1234564 % p, (ll)st[i - 1].second * 123617821 % q);
    }

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        x--;
        y--;
        ed[x].push_back(mp(w, y));
    }

    bool ok = true;

    for (int i = 0; i < n; i++) {
        sort(all(ed[i]));
        if (ed[i].empty()) {
            ok = false;
            break;
        }

        for (int j = 0; j < (int)ed[i].size(); j++) {
            int u = ed[i][j].second;
            hsh[(int)ed[i].size() - 1][j] = hsh[(int)ed[i].size() - 1][j] + st[u];
        }
    }

    if (!ok) {
        cout << 0 << '\n';
        return 0;
    }

    pii nd = mp(0, 0);

    for (int i = 0; i < n; i++) {
        nd = nd + st[i];
    }

    cout << go(0, mp(0, 0), nd) << '\n';
}