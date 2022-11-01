#include <stdio.h>
#include <deque>
#include <algorithm>
using namespace std;

const int N = 3e5;
int a[N], t2[4 * N];
deque<int> comp[N];
int tSet2[4 * N];

inline void build2(int v, int vl, int vr) {
    tSet2[v] = -1;
    if(vl == vr) {
        t2[v] = a[vl];
        return;
    }
    int vm = vl + (vr - vl) / 2;
    build2(v * 2 + 1, vl, vm);
    build2(v * 2 + 2, vm + 1, vr);
    t2[v] = t2[v * 2 + 1] + t2[v * 2 + 2];
}

inline void push2(int v, int vl, int vr) {
    if(tSet2[v] != -1) {
        if(vl != vr) {
            tSet2[v * 2 + 1] = tSet2[v];
            tSet2[v * 2 + 2] = tSet2[v];
        }
        t2[v] = 1ll * tSet2[v] * (vr - vl + 1);
        tSet2[v] = -1;
    }
}

inline void upd2(int v, int vl, int vr, int l, int r, int n) {
    push2(v, vl, vr);
    if(vr < l || vl > r)
        return;
    if(l <= vl && vr <= r) {
        tSet2[v] = n;
        push2(v, vl, vr);
        return;
    }
    int vm = vl + (vr - vl) / 2;
    upd2(v * 2 + 1, vl, vm, l, r, n);
    upd2(v * 2 + 2, vm + 1, vr, l, r, n);
    t2[v] = t2[v * 2 + 1] + t2[v * 2 + 2];
}

inline long long get2(int v, int vl, int vr, int l, int r) {
    push2(v, vl, vr);
    if(vr < l || vl > r)
        return 0;
    if(l <= vl && vr <= r)
        return t2[v];
    int vm = vl + (vr - vl) / 2;
    return get2(v * 2 + 1, vl, vm, l, r) + get2(v * 2 + 2, vm + 1, vr, l, r);
}

int main()
{
    int n, q, cur = 0;
    scanf("%d%d", &n, &q);
    build2(0, 0, q-1);
    for(int i = 0; i < q; i++) {
        int type, x;
        scanf("%d%d", &type, &x);
        x--;
        if(type == 1) {
            comp[x].push_back(cur);
            upd2(0, 0, q-1, cur, cur, 1);
            cur++;
        } else if(type == 2) {
            while(!comp[x].empty()) {
                upd2(0, 0, q-1, comp[x].front(), comp[x].front(), 0);
                comp[x].pop_front();
            }
        } else {
            upd2(0, 0, q-1, 0, x, 0);
        }
        printf("%d\n", get2(0, 0, q-1, 0, q-1));
    }
    return 0;
}