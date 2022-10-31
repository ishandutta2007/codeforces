#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <ctime>
#include <functional>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
    return x * x;
}

const int maxn = 100005;

int a[maxn];
int s[maxn];
vector<pair<int, int>> b[maxn];
int used[maxn];
int currUsed = 1;

int xr(int l, int r) {
    return s[r] ^ (l ? s[l - 1] : 0);
}

int main() {
    //freopen("a.in", "r", stdin);

    for (ll l = 1; l < maxn; l++) {
        for (ll r = l + 1; ; r++) {
            ll cnt = r * (r + 1) / 2 - (l - 1) * l / 2;
            if (cnt >= maxn) {
                break;
            }

            b[cnt].pb(mp(l, r));
        }
    }

    for (int i = 1; i < maxn; i++) {
        currUsed++;
        for (auto p : b[i]) {
            used[xr(p.fst, p.snd)] = currUsed;
        }
        while (used[a[i]] == currUsed) {
            a[i]++;
        }

        s[i] = s[i - 1] ^ a[i];
    }

    int n;
    cin >> n;



    if (a[n]) {
        int ans = 1e9;
        for (auto p : b[n]) {
            if (!xr(p.fst, p.snd)) {
                ans = min(ans, p.snd - p.fst + 1);
            }
        }
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}