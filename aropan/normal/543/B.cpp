#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#if (_WIN32 || __WIN32__ || _WIN64 || __WIN64__)
#define INT64 "%I64d"
#define UNS64 "%I64u"
#else
#define INT64 "%lld"
#define UNS64 "%llu"
#endif

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

vector < vector <int> > e;
int n, m;
vector < vector <int> > d;

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    #endif
    int n, m;
    cin >> n >> m;
    e.resize(n);
    d.resize(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    const int INF = n + n;
    for (int i = 0; i < n; ++i) {
        vector <int> &l = d[i];
        l.resize(n, INF);
        l[i] = 0;
        queue <int> q;
        q.push(i);
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (auto& y : e[x]) {
                if (l[y] == INF) {
                    l[y] = l[x] + 1;
                    q.push(y);
                }
            }
        }
    }
    int s1, t1, l1;
    int s2, t2, l2;
    cin >> s1 >> t1 >> l1;
    cin >> s2 >> t2 >> l2;
    --s1;
    --t1;
    --s2;
    --t2;
    if (d[s1][t1] > l1 || d[s2][t2] > l2) {
        puts("-1");
        return 0;
    }
    int answer = d[s1][t1] + d[s2][t2];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int d1 = min(d[s1][i] + d[j][t1], d[s1][j] + d[i][t1]) + d[i][j];
            int d2 = min(d[s2][i] + d[j][t2], d[s2][j] + d[i][t2]) + d[i][j];
            if (d1 > l1 || d2 > l2) {
                continue;
            }
            int res = d1 + d2 - d[i][j];
            if (res < answer) {
                answer = res;
            }
        }
    }
    printf("%d\n", m - answer);
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}