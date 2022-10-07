#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 4444;
const long long INF = 1e18 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

//const int BASE = 24;
//const int SZ = (1 << BASE);
//const int MOD = SZ - 1;

//const int BASE = 24;
const int MOD = 20e6;
const int SZ = 20e6 + 1000;

struct HashTable {
    ll value[SZ];
    ll h[SZ];
    int sz;

    HashTable() {
        memset(value, 63, sizeof(value));
    }

    //ll getPos(ll hash) {
    //}

    ll & operator [] (ll hash) {
        int p = hash % MOD;
        for (; h[p] != 0 && h[p] != hash; p++);
        if (h[p] == 0) sz++;
        h[p] = hash;
        return value[p];
    }
};

int n;
int a[N];
HashTable table;
ll pref[N];

ll getSum(int l, int r) {
    return pref[r] - pref[l];
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

ll calcHash(int aa, int b, int c, int d) {
    return (((aa * 1ll * N + b) * N + c) * N + d) + 42;
}

ll rec(int l, int r, int type, int k) {
    ll hash = calcHash(l, r, type, k);
    ll & val = table[hash];
    if (val > INF) {
        if (type == 0) {
            bool step = 0;
            //ll res = -INF;
            val = -INF;
            for (int add = 0; add <= 1; add++) {
                if (k + add <= r - l) {
                    step = 1;
                    val = max(val, getSum(l, l + k + add) + rec(l + k + add, r, type ^ 1, k + add));
                }
            }
            if (!step)
                val = 0;
        }
        if (type == 1) {
            bool step = 0;
            //ll res = INF;
            val = INF;
            for (int add = 0; add <= 1; add++) {
                if (k + add <= r - l) {
                    step = 1;
                    val = min(val, -getSum(r - (k + add), r) + rec(l, r - (k + add), type ^ 1, k + add));
                }
            }
            if (!step)
                val = 0;
        }
    }
    return val;
}

void solve() {
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i]; 
    cout << rec(0, n, 0, 1) << endl;

    //db(table.sz);
    //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
    //freopen("test.txt", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}