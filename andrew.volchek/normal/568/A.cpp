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
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>

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

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}


const int maxn = 4e7;

char p[maxn];
char pal[maxn];

int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    auto toN = [](string s) {
        int res = 0;
        for (char c : s) {
            res = res * 10 + c - '0';
        }
        return res;
    };

    for (int i = 1; i < 10000; i++) {
        int x = i;
        string s;
        while (x) {
            s += x % 10 + '0';
            x /= 10;
        }

        reverse(s.begin(), s.end());

        string s2 = s;
        reverse(s2.begin(), s2.end());

        if (toN(s + s2) < maxn) {
            pal[toN(s + s2)] = 1;
        }

        for (int j = 0; j < 10; j++) {
            s += '0' + j;
            if (toN(s + s2) < maxn) {
                pal[toN(s + s2)] = 1;
            }
            s.pop_back();
        }
    }

    for (int i = 1; i < 10; i++) {
        pal[i] = 1;
    }

    for (ll i = 2; i < maxn; i++) {
        if (p[i]) {
            continue;
        }

        for (ll j = i * i; j < maxn; j += i) {
            p[j] = 1;
        }
    }

    p[1] = 1;

    ll n, m;
    cin >> n >> m;

    ll ans = -1;

    int pr = 0, palC = 0;
    for (int i = 1; i < maxn; i++) {
        pr += !p[i];
        palC += pal[i];
        if (m * pr <= palC * n) {
            ans = i;
        }
    }

    if (ans == -1) {
        cout << "Palindromic tree is better than splay tree" << endl;
    } else {
        cout << ans << endl;
    }

    cerr << (ld)clock() / CLOCKS_PER_SEC << endl;


    return 0;
}