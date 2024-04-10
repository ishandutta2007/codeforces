#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <queue>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

const int maxn = 200005;
int a[maxn];
int b[maxn];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> c;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        c.pb(mp(x, i));
    }

    set<int> wasR;
    set<int> wasL;
    wasR.insert(n);
    wasL.insert(1);

    sort(c.begin(), c.end());

    for (auto x : c) {
        int r = *wasR.lower_bound(x.snd);
        int l = -(*wasL.lower_bound(-x.snd));
        int len = r - l - 1;
        b[len] = max(b[len], x.fst);
        wasR.insert(x.snd);
        wasL.insert(-x.snd);
    }

    for (int i = n - 1; i >= 1; i--) {
        b[i] = max(b[i], b[i + 1]);
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1)
            printf(" ");
        printf("%d", b[i]);
    }

    return 0;
}