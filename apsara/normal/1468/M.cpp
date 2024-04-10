#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 100010;
const int M = 100;
int _, n, c[V];
vector<int> a[V];

template <typename Tk, typename Tv, int N = 12582917 + 9, Tk P = 12582917>
struct Hash_Table{
    int tot, head[N], nxt[N], sk[N]; Tk key[N]; Tv val[N];
    void init(){ tot = 0; memset(head, -1, sizeof(head)); }
    void insert(const Tk &K, const Tv &V){
        int k = K%P; nxt[++tot] = head[k]; head[k] = tot;
        key[tot] = K; val[tot] = V; sk[tot] = k;
    }
    Tv* find(const Tk &K){
        for (int i = head[K%P]; ~i; i = nxt[i])
            if (key[i] == K) return &val[i];
        return nullptr;
    }
    void clear(){
        while (tot){ head[sk[tot--]] = -1; }
    }
};

Hash_Table<LL, int> mp;

const int N = 200000 + 9;
int m[N];
int _a[N], tot;

void solve() {
    memset(m, 0, (tot+5) * sizeof(*m));
    sort(_a + 1, _a + tot + 1);
    auto ed = unique(_a + 1, _a + tot + 1);
    for (int i = 0; i < n; ++i){
        for (int &j : a[i]){
            j = lower_bound(_a + 1, ed, j) - _a;
        }
    }
    //map<PII, int> mp;
    mp.clear();
    for (int i = 0; i < n; ++i) {
        sort(a[i].begin(), a[i].end());
        if (c[i] >= M) continue;
        for (int j = 0; j < c[i]; ++j) {
            for (int k = 0; k < j; ++k) {
                int u = a[i][k];
                int v = a[i][j];
                LL w = ((LL)u << 20) | v;
                auto re = mp.find(w);
                if (re != nullptr) {
                    printf("%d %d\n", *re, i + 1);
                    return;
                }
                mp.insert(w, i + 1);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (c[i] < M) continue;
        //map<int, int> m;
        for (int j = 0; j < c[i]; ++j) {
            m[a[i][j]] = 1;
        }
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (c[j] >= M && j < i) continue;
            int cnt = 0;
            for (int k = 0; k < c[j]; ++k) {
                cnt += m[a[j][k]];
            }
            if (cnt >= 2) {
                printf("%d %d\n", i + 1, j + 1);
                return;
            }
        }
        for (int j = 0; j < c[i]; ++j) {
            m[a[i][j]] = 0;
        }
    }
    puts("-1");
}

int x;
int main() {
    mp.init();
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        tot = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &c[i]);
            a[i].clear();
            for (int j = 0; j < c[i]; ++j) {
                scanf("%d", &x);
                a[i].PB(x);
                _a[++tot] = x;
            }
        }
        solve();
    }
    return 0;
}

/*
3
4
2 1 10
3 1 3 5
5 5 4 3 2 1
3 10 20 30
3
4 1 2 3 4
4 2 3 4 5
4 3 4 5 6
2
3 1 3 5
3 4 3 2

*/