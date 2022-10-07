#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 5e3 + 10;
const int INF = 1e9;
const int P = 1e9 + 7;
const int SZ = 1 << 14;
const int MOD = SZ - 1;

struct HashT {
    vector < long long > h;
    vector < int > cnt;
    void init() {
        h.assign(SZ, 0);
        cnt.assign(SZ, 0);
    }
    void insert(long long hash) {
        int pos = hash & MOD;
        for (; cnt[pos] != 0 && h[pos] != hash; pos = (pos + 1) & MOD);
        cnt[pos]++;
        h[pos] = hash;
    }
    int getCnt(long long hash) {
        int pos = hash & MOD;
        for (; cnt[pos] != 0 && h[pos] != hash; pos = (pos + 1) & MOD);
        return cnt[pos];
    }
};

char s[N];
char t[N];
long long hs[N];
long long ht[N];
long long st[N];
HashT q, q1;

long long getHash(long long * h, int l, int r) {
    return  h[r] - (h[l] * st[r - l]); 
}



int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n, m;
    scanf("%s%s", s, t);
    n = strlen(s);
    m = strlen(t);
    for (int i = 0; i < n; i++)
        hs[i + 1] = hs[i] * P + s[i];
    for (int i = 0; i < m; i++)
        ht[i + 1] = ht[i] * P + t[i];
    st[0] = 1;
    for (int i = 0; i <= min(n, m); i++)
        st[i + 1] = st[i] * P;
    for (int len = 1; len <= min(n, m); len++) {
        q.init();
        q1.init();
        for (int i = 0; i <= n - len; i++)
            q.insert(getHash(hs, i, i + len));
        for (int i = 0; i <= m - len; i++)
            q1.insert(getHash(ht, i, i + len));
        for (int i = 0; i <= m - len; i++)  
            if (q1.getCnt(getHash(ht, i, i + len)) == 1 && q.getCnt(getHash(ht, i, i + len)) == 1) {
                printf("%d\n", len);
                return 0;
            }
    }
    printf("-1\n");
    return 0;
}