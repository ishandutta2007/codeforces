#include <cstdio>
using namespace std;

typedef long long ll;

const int MAXN = 300005;
const int MAXK = 1000005;
const int offset = 1 << 19;

int N, K;
int a[MAXN];
int pref[MAXN];
int cnt[MAXK], tmp[MAXK];
int t[2 * offset];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
}

int merge(int l, int r) {
    return a[l] > a[r] ? l : r;
}

int query(int x, int lo, int hi, int from, int to) {
    if (lo >= to || hi <= from) return 0;
    if (lo >= from && hi <= to) return t[x];
    int mid = (lo + hi) / 2;
    return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

void add(int lo, int hi, int val) {
    for (int i = lo; i < hi; i++)
        cnt[pref[i]] += val;
}

ll rec(int lo, int hi) {
    if (lo == hi) return 0;
    int pos = query(1, 0, offset, lo, hi);
    ll sol = 0;
    if (pos - lo < hi - pos - 1) {
        sol += rec(lo, pos);
        add(lo, pos, -1);
        sol += rec(pos + 1, hi);    
        cnt[pref[pos]]++;
        for (int i = lo; i <= pos; i++)
            sol += (ll)cnt[(pref[i - 1] + a[pos]) % K];    
        add(lo, pos, 1);
    }
    else {
        sol += rec(pos + 1, hi);
        add(pos + 1, hi, -1);
        sol += rec(lo, pos);
        cnt[pref[lo - 1]]++;
        for (int i = pos + 1; i <= hi; i++) 
            sol += (ll)cnt[(pref[i - 1] - a[pos] % K + K) % K];
        cnt[pref[lo - 1]]--;
        cnt[pref[pos]]++;
        add(pos + 1, hi, 1);
    }
    return sol - 1;
}

ll solve() {
    for (int i = 1; i <= N; i++)
        pref[i] = (pref[i - 1] + a[i]) % K;
        
    for (int i = 1; i <= N; i++)
        t[i + offset] = i;
    for (int i = offset - 1; i >= 0; i--)
        t[i] = merge(t[2 * i], t[2 * i + 1]);
    
    return rec(1, N + 1);
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}