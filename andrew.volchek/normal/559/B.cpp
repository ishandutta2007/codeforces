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

const int maxn = 200005;

char a[maxn], b[maxn];

void rec(char *a, int l, int r) {
    int len = (r - l + 1);

    if (len & 1) {
        return;
    } else {
        int c = (l + r) >> 1;

        rec(a, l, c);
        rec(a, c + 1, r);

        bool gr = false;
        for (int i = 0; i < len / 2; i++) {
            if (a[l + i] < a[c + 1 + i]) {
                break;
            } else if (a[l + i] > a[c + 1 + i]) {
                gr = true;
                break;
            }
        }

        if (gr) {
            for (int i = 0; i < len / 2; i++) {
                swap(a[l + i], a[c + 1 + i]);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    //freopen("a.in", "r", stdin);

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("factory.in", "r", stdin);
    //freopen("factory.out", "w", stdout);
#endif


    scanf("%s\n", a);
    scanf("%s\n", b);

    int n = strlen(a);
    rec(a, 0, n - 1);
    rec(b, 0, n - 1);

    bool good = true;
    for (int i = 0; i < n; i++) {
        good &= a[i] == b[i];
    }

    if (good) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}