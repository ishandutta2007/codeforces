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

const int maxn = (int)5e5 + 10;
char s[maxn];
int cnt[maxn];

ll fnd(pii f) {
    int d = f.second - f.first + 1;
    return (ll)d * (d + 1) / 2;
}

int main() {
    int n;
    cin >> n;
    scanf("%s", s);

    int cur = 0;

    vector <pii> g;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            cur++;
        }
        else {
            cur = 0;
        }

        cnt[i] = cur;
        g.push_back(mp(cur, i));
    }

    sort(all(g));
    reverse(all(g));

    set <pii> q;

    int pos = 0;

    ll sum = 0;
    ll ans = 0;

    for (int i = n; i >= 1; i--) {
        int x = n - i;
        if (!q.empty() && q.rbegin()->second == x - 1) {
            pii f = *q.rbegin();
            q.erase(f);
            sum -= fnd(f);
            f.second++;
            q.insert(f);
            sum += fnd(f);
        }
        else {
            q.insert(mp(x, x));
            sum += fnd(mp(x, x));
        }

        while (pos < (int)g.size() && g[pos].first == i) {
            int x = g[pos].second;
            pos++;

            auto it = q.lower_bound(mp(x + 1, -1));
            assert(it != q.begin());
            it--;

            pii f = (*it);
            q.erase(it);
            sum -= fnd(f);

            if (f.first == x && f.second == x) {
                continue;
            }

            if (f.first == x) {
                q.insert(mp(x + 1, f.second));
                sum += fnd(mp(x + 1, f.second));
            }
            else if (f.second == x) {
                q.insert(mp(f.first, x - 1));
                sum += fnd(mp(f.first, x - 1));
            }
            else {
                q.insert(mp(f.first, x - 1));
                q.insert(mp(x + 1, f.second));
                sum += fnd(mp(f.first, x - 1));
                sum += fnd(mp(x + 1, f.second));
            }
        }

        ans += fnd(mp(0, n - i)) - sum;
    }

    cout << ans << '\n';
}