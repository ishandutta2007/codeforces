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

const int MOD = (int)1e+9 + 7;

vector < vector <int> > e;
vector <ll> f;
vector <ll> answer;
int n;

void dfs_f(int x)
{
    f[x] = 1;
    for (auto& y : e[x]) {
        dfs_f(y);
        (f[x] *= f[y] + 2) %= MOD;
    }
    f[x] = (f[x] + MOD - 1) % MOD;
}

void dfs_s(int x, ll F)
{
    vector <ll> l;
    ll v;

    v = 1;
    for (auto& y : e[x]) {
        (v *= f[y] + 2) %= MOD;
        l.push_back(v);
    }

    v = 1;
    for (size_t i = e[x].size(); i-- > 0; ) {
        int y = e[x][i];
        dfs_s(y, (v * (i > 0? l[i - 1] : 1) % MOD * (F + 2) % MOD + MOD - 1) % MOD);
        (v *= f[y] + 2) %= MOD;
    }

    answer[x] = (f[x] + 1) * (F + 2) % MOD;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    #endif
    scanf("%d", &n);
    e.resize(n);
    f.resize(n);
    answer.resize(n);
    for (int i = 1; i < n; ++i) {
        int x;
        scanf("%d", &x);
        --x;
        e[x].push_back(i);
    }
    dfs_f(0);
    dfs_s(0, -1);

    for (int i = 0; i < n; ++i) {
        if (i) {
            printf(" ");
        }
        printf("%d", (int)answer[i]);
    }
    printf("\n");
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}