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

int cnt[maxn];

set<int> canWithOne[maxn];
set<int> canWithOneInv[maxn];
set<int> canWithTwo[maxn];

set<int> canWithOnlyTwo[maxn];

int a[maxn], b[maxn], c[maxn];

int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    //freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    vector<int> ans;
    vector<int> st;

    for (int i = 1; i <= n; i++) {
        cnt[i] = 4;
    }

    for (int i = 1; i <= 4 * n; i++) {
        st.pb(i);
        scanf("%d %d %d", a + i, b + i, c + i);
    }

    set<int> was;

    while (!st.empty()) {
        int id = st.back();
        st.pop_back();

        if (was.count(id)) {
            continue;
        }

        int prvA = cnt[a[id]];

        cnt[a[id]]--;
        cnt[b[id]]++;
        cnt[c[id]]++;

        if (cnt[b[id]] <= 9 && cnt[c[id]] <= 9) {
            vector<int> nw;
            nw.pb(b[id]);
            if (b[id] != c[id]) {
                nw.pb(c[id]);
            }

            for (int v : nw) {
                if (cnt[v] == 9) {
                    for (int x : canWithOneInv[v]) {
                        if (b[x] == v) {
                            canWithOne[c[x]].erase(x);
                        } else {
                            canWithOne[b[x]].erase(x);
                        }

                        canWithTwo[b[x]].insert(x);
                        canWithTwo[c[x]].insert(x);
                    }
                }
            }

            if (cnt[a[id]] < 9 && prvA == 9) {
                while (!canWithOne[a[id]].empty()) {
                    int v = *canWithOne[a[id]].begin();
                    canWithOne[a[id]].erase(v);
                    canWithOneInv[c[v]].erase(v);
                    canWithOneInv[b[v]].erase(v);
                    st.pb(v);
                }

                while (!canWithTwo[a[id]].empty()) {
                    int v = *canWithTwo[a[id]].begin();
                    canWithTwo[b[v]].erase(v);
                    canWithTwo[c[v]].erase(v);

                    canWithOne[b[v]].insert(v);
                    canWithOneInv[c[v]].insert(v);
                    canWithOne[c[v]].insert(v);
                    canWithOneInv[b[v]].insert(v);
                }
            }

            while (cnt[a[id]] < 8) {
                if (!canWithOnlyTwo[a[id]].empty()) {
                    int v = *canWithOnlyTwo[a[id]].begin();
                    canWithOnlyTwo[a[id]].erase(v);
                    st.pb(v);
                } else {
                    break;
                }
            }

            ans.pb(id);
            was.insert(id);
        } else {
            if (b[id] != c[id]) {
                if (cnt[b[id]] > 9 && cnt[c[id]] > 9) {
                    canWithTwo[b[id]].insert(id);
                    canWithTwo[c[id]].insert(id);
                } else if (cnt[b[id]] > 9) {
                    canWithOne[b[id]].insert(id);
                    canWithOneInv[c[id]].insert(id);
                } else {
                    canWithOne[c[id]].insert(id);
                    canWithOneInv[b[id]].insert(id);
                }
            } else {
                canWithOnlyTwo[b[id]].insert(id);
            }

            cnt[c[id]]--;
            cnt[b[id]]--;
            cnt[a[id]]++;
        }
    }

    //assert(ans.size() == 4 * n);

    printf("YES\n");

    for (int x : ans) {
        printf("%d ", x);
    }

    return 0;
}