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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef double dbl;
const int MOD = 1e9 + 7;
const int T = 6;

ll sum[N];
ll sum2[N];
ll sump[N];
ll cnt[N];
ll deg[N];
ll answer[N];
ll d2[N];

int get(int x, int i) {
    return x / deg[i] % 10;
}


void gen(int pos, int y, int i, int cof) {
    if (pos == T) {
        answer[i] += sum2[y] * cof;
        return;
    }
    gen(pos + 1, y, i, cof);
    if (get(y, pos) != 9) {
        gen(pos + 1, y + deg[pos], i, cof * -1);
    }
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
    freopen("test.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x] += 1;
        sum[x] += x;
        sum2[x] += x * 1ll * x;
    }
    deg[0] = 1;
    for (int i = 0; i < T; i++) deg[i + 1] = deg[i] * 10;


    vector<int> tmp(T);
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < deg[T]; j++) {
            int x = get(j, i);
            if (x == 0) {
                for (int k = 8; k >= 0; k--) {
                    cnt[j + k * deg[i]] += cnt[j + (k + 1) * deg[i]];
                    sum[j + k * deg[i]] += sum[j + (k + 1) * deg[i]];
                    sum2[j + k * deg[i]] += sum2[j + (k + 1) * deg[i]];
                }
            }
        }
    }
    d2[0] = 1;
    for (int i = 0; i < deg[T]; i++) d2[i + 1] = (d2[i] * 2) %  MOD;
    for (int i = 0; i < deg[T]; i++) {
        sum[i] %= MOD;
        sum2[i] %= MOD;
        sump[i] = (sum[i] * sum[i] - sum2[i] + MOD) % MOD;;
        if (cnt[i] >= 1)
            sum2[i] = (sum2[i] * d2[cnt[i] - 1]) % MOD;
        if (cnt[i] >= 2)
            sump[i] = (sump[i] * d2[cnt[i] - 2]) % MOD;
        sum2[i] = (sum2[i] + sump[i]) % MOD;
    }

    for (int i = 0; i < deg[T]; i++) {
        gen(0, i, i, 1);
    }
    
    ll res = 0;
    for (int i = 0; i < deg[T]; i++) {
        answer[i] = (answer[i] % MOD + MOD) % MOD;
        res ^= answer[i] * i;
    }

    cout << res << endl;
    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}