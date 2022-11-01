#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e6;
int a[N], ind[N];
long long b[N], t[4*N];
vector<long long> tSet(4*N, -1);
pair<int,int> w[N];

inline void push(int v, int vl, int vr) {
    if(tSet[v] != -1) {
        if(vl != vr) {
            tSet[v*2+1] = tSet[v];
            tSet[v*2+2] = tSet[v];
        }
        t[v] = tSet[v] * (vr - vl + 1);
        tSet[v] = -1;
    }
}

inline void update(int v, int vl, int vr, int l, int r, long long x) {
    push(v, vl, vr);
    if(r < vl || vr < l)
        return;
    if(l <= vl && vr <= r) {
        tSet[v] = x;
        push(v, vl, vr);
        return;
    }
    int vm = (vl + vr) >> 1;
    update(v*2+1, vl, vm, l, r, x);
    update(v*2+2, vm+1, vr, l, r, x);
    t[v] = t[v*2+1] + t[v*2+2];
}

inline long long query(int v, int vl, int vr, int l, int r) {
    push(v, vl, vr);
    if(r < vl || vr < l)
        return 0;
    if(l <= vl && vr <= r)
        return t[v];
    int vm = (vl + vr) >> 1;
    return query(v*2+1, vl, vm, l, r) + query(v*2+2, vm+1, vr, l, r);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        w[i] = make_pair(a[i], i);
    }
    sort(w, w+n);
    for(int i = 0; i < n; i++)
        ind[w[i].second] = i;
    update(0, 0, n-1, ind[n-1], ind[n-1], 1ll);
    for(int i = n - 2; i >= 0; i--) {
        update(0, 0, n-1, ind[i], ind[i], 1ll);
        if(ind[i])
            b[i] = query(0, 0, n-1, 0, ind[i]-1);
    }
    update(0, 0, n-1, 0, n-1, 0ll);
    update(0, 0, n-1, ind[n-1], ind[n-1], b[n-1]);
    update(0, 0, n-1, ind[n-2], ind[n-2], b[n-2]);
    long long ans = 0;
    for(int i = n - 3; i >= 0; i--) {
        update(0, 0, n-1, ind[i], ind[i], b[i]);
        if(ind[i] > 1)
            ans += query(0, 0, n-1, 0, ind[i]-1);
    }
    printf("%I64d", ans);
    return 0;
}