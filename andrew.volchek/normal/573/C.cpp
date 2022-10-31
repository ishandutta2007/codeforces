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

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

template<typename U, typename V>
ostream& operator << (ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream& operator << (ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

//-----------------------------------------------------------------------------

const int maxn = 1e5 + 5;

vector<int> g[maxn];
map<pair<int,int>, int> dp[5];
vector<int> order;

bool get(int v, int pr, int t) {
    return dp[t][mp(v, pr)];
}

int cnt[5];

void dfs(int v, int pr = -1) {
    order.pb(v);
    for (int to : g[v]) {
        if (to != pr) {
            dfs(to, v);
        }
    }

    fill(cnt, cnt + 5, 0);


    for (int to : g[v]) {
        if (to == pr) {
            continue;
        }


        cnt[0]++;
        cnt[1] += get(to, v, 1);
        cnt[2] += get(to, v, 2) - get(to, v, 1);
        cnt[3] += get(to, v, 3) - get(to, v, 2);
    }


    dp[1][mp(v, pr)] = cnt[0] <= 1 && cnt[1] == cnt[0];
    dp[2][mp(v, pr)] = cnt[0] <= 2 && cnt[1] == cnt[0];
    dp[3][mp(v, pr)] = (cnt[1] + cnt[2] + cnt[3]) == cnt[0] && cnt[3] <= 1;
    dp[4][mp(v, pr)] = (cnt[1] + cnt[2] + cnt[3]) == cnt[0] && cnt[3] <= 2;
}

int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1);

    for (int v : order) {
        fill(cnt, cnt + 5, 0);

        for (int to : g[v]) {
            cnt[0]++;
            cnt[1] += get(to, v, 1);
            cnt[2] += get(to, v, 2) - get(to, v, 1);
            cnt[3] += get(to, v, 3) - get(to, v, 2);
        }

        if ((cnt[1] + cnt[2] + cnt[3]) == cnt[0] && cnt[3] <= 2) {
            cout << "Yes" << endl;
            return 0;
        }

        for (int to : g[v]) {
            cnt[0]--;
            cnt[1] -= get(to, v, 1);
            cnt[2] -= get(to, v, 2) - get(to, v, 1);
            cnt[3] -= get(to, v, 3) - get(to, v, 2);

            dp[1][mp(v, to)] = cnt[0] <= 1 && cnt[1] == cnt[0];
            dp[2][mp(v, to)] = cnt[0] <= 2 && cnt[1] == cnt[0];
            dp[3][mp(v, to)] = (cnt[1] + cnt[2] + cnt[3]) == cnt[0] && cnt[3] <= 1;
            dp[4][mp(v, to)] = (cnt[1] + cnt[2] + cnt[3]) == cnt[0] && cnt[3] <= 2;

            cnt[0]++;
            cnt[1] += get(to, v, 1);
            cnt[2] += get(to, v, 2) - get(to, v, 1);
            cnt[3] += get(to, v, 3) - get(to, v, 2);
        }
    }

    cout << "No" << endl;

    return 0;
}