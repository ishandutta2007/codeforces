#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

int N, K, A, B, Q;
int pref[MAXN], suff[MAXN];
int cp[MAXN], cs[MAXN];

void update_pref(int x, int val) {
    for (; x < MAXN; x += x & -x)
        pref[x] += val;
}

int get_pref(int x) {
    int res = 0;
    for (; x; x -= x & -x)
        res += pref[x];
    return res;
}

void update_suff(int x, int val) {
    for (x = MAXN - x; x < MAXN; x += x & -x)
        suff[x] += val;
}

int get_suff(int x) {
    int res = 0;
    for (x = MAXN - x; x; x -= x & -x)
        res += suff[x];
    return res;
}

int main() {
    scanf("%d%d%d%d%d", &N, &K, &A, &B, &Q);
    
    while (Q--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int d, a;
            scanf("%d%d", &d, &a);
            int old = cp[d];
            cp[d] = min(cp[d] + a, B);
            update_pref(d, cp[d] - old);
            old = cs[d];
            cs[d] = min(cs[d] + a, A);
            update_suff(d, cs[d] - old);
        }
        else {
            int p;
            scanf("%d", &p);
            printf("%d\n", get_pref(p - 1) + get_suff(p + K));
        }
    }
    
    return 0;
}