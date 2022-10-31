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


ll dp[55];

int main() {
    //srand(time(NULL));
    //gen();
    //freopen("a.in", "r", stdin);

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < 55; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    ll n, k;
    cin >> n >> k;

    vector<int> ans;
    int p = 1;

    while (n) {
        if (n > 1 && dp[n - 1] < k) {
            k -= dp[n - 1];
            ans.pb(p + 1);
            ans.pb(p);
            p += 2;
            n -= 2;
            continue;
        }

        ans.pb(p);
        p++;
        n--;
    }

    for (int i = 0; i < ans.size(); i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", ans[i]);
    }

    return 0;
}