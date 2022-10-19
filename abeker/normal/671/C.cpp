#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 200005;
const int offset = 1 << 18;

struct node {
    ll sum;
    int lazy, right;
    node(ll sum, int lazy, int right) : sum(sum), lazy(lazy), right(right) {}
    node() : sum(0), lazy(MAXN), right(0) {}
};

int N;
int pos[MAXN];
node t[2 * offset];

void load() {
    memset(pos, -1, sizeof pos);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        pos[x] = i;
    }   
}

void update_mx(int &mx1, int &mx2, int val) {
    if (val >= mx1) {
        mx2 = mx1;
        mx1 = val;
    }
    else if (val > mx2)
        mx2 = val;
}

void update_mn(int &mn1, int &mn2, int val) {
    if (val <= mn1) {
        mn2 = mn1;
        mn1 = val;
    }
    else if (val < mn2)
        mn2 = val;
}

node merge(node L, node R) {
    return node(L.sum + R.sum, MAXN, min(L.right, R.right));
}

void prop(int x, int len) {
    if (t[x].lazy == MAXN) return;
    t[x].sum = (ll)len * t[x].lazy;
    t[x].right = t[x].lazy;
    if (x < offset)
        t[2 * x].lazy = t[2 * x + 1].lazy = t[x].lazy;
    t[x].lazy = MAXN;
}

void update(int x, int lo, int hi, int from, int to, int val) {
    prop(x, hi - lo);
    if (lo >= to || hi <= from) return;
    if (lo >= from && hi <= to) {
        t[x].sum = (ll)(hi - lo) * val;
        t[x].right = val;
        if (x < offset) 
            t[2 * x].lazy = t[2 * x + 1].lazy = val;
        return;
    }
    int mid = (lo + hi) / 2;
    update(2 * x, lo, mid, from, to, val);
    update(2 * x + 1, mid, hi, from, to, val);
    t[x] = merge(t[2 * x], t[2 * x + 1]);
}

int find(int x, int lo, int hi, int val) {
    if (x >= offset) return x - offset;
    int mid = (lo + hi) / 2;
    prop(2 * x, mid - lo);
    prop(2 * x + 1, hi - mid);
    if (t[2 * x].right <= val) return find(2 * x, lo, mid, val);
    return find(2 * x + 1, mid, hi, val);
}

void update(int from, int to, int val) {
    prop(1, offset);
    to = min(to, find(1, 0, offset, val));
    if (from < to) update(1, 0, offset, from, to, val);
}

ll solve() {
    for (int i = 0; i < N; i++)
        t[i + offset] = node(N - i, MAXN, N - i);
    
    for (int i = offset - 1; i >= 0; i--)
        t[i] = merge(t[2 * i], t[2 * i + 1]);
        
    ll sol = 0;
    for (int i = MAXN - 1; i; i--) {
        int maks1 = -1, maks2 = -1;
        int mini1 = N, mini2 = N;
        for (int j = i; j < MAXN; j += i) {
            if (pos[j] == -1) continue;
            update_mx(maks1, maks2, pos[j]);
            update_mn(mini1, mini2, pos[j]); 
        }
        if (maks2 != -1) {
            update(0, N - maks1, mini2 + 1);
            update(N - maks1, N - maks2, mini1 + 1);
            update(N - maks2, N, 0);
        }
        sol += (ll)N * (N + 1) / 2 - t[1].sum;
    }
    
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}