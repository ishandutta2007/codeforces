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
#define y1 _y1

const ld pi = 3.14159265359;

template < typename T >
T abs(T x) {
    return x > 0 ? x : -x;
}

template < typename T >
T sqr(T x) {
    return x * x;
}

const int maxn = 105;

int a[maxn][maxn];
int c[maxn], d[maxn];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            scanf("%c", &c);
            a[i][j] = c - '0';
        }
        scanf("\n");
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", d + i);
        //cerr << d[i] << " " ;
    }

    vector<int> ans;

    while (true) {
        bool any = false;
        for (int i = 0; i < n; i++) {
            if (c[i] == d[i]) {
                ans.pb(i);
                for (int j = 0; j < n; j++) {
                    if (a[i][j]) {
                        c[j]++;
                    }
                }
                any = true;
                break;
            }
        }
        if (!any) {
            break;
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i) {
            cout << " ";
        }
        cout << ans[i] + 1;
    }



    return 0;
}