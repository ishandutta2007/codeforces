#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;
const int N = 1e6;
vector<int> t[4*N];
int a[N], p[N];

void build(int v, int vl, int vr) {
    if(vl == vr) {
        t[v].push_back(p[vl]);
        return;
    }
    int vm = (vl + vr) >> 1;
    build(v * 2 + 1, vl, vm);
    build(v * 2 + 2, vm+1, vr);
    merge(t[v*2+1].begin(), t[v*2+1].end(), t[v*2+2].begin(), t[v*2+2].end(), back_inserter(t[v]));
}

int query(int v, int vl, int vr, int l, int r, int x) {
    if(r < vl || vr < l)
        return 0;
    if(l <= vl && vr <= r) {
        if(t[v].back() <= x)
            return 0;
        int bl = 0, br = (int)t[v].size()-1;
        while(bl < br) {
            int bm = (bl + br) >> 1;
            if(t[v][bm] > x)
                br = bm;
            else
                bl = bm + 1;
        }
        return (int)t[v].size() - bl;
    }
    int vm = (vl + vr) >> 1;
    return query(v*2+1, vl, vm, l, r, x) + query(v*2+2, vm+1, vr, l, r, x);
}

int main() {
    int n;
    map<int, int> cnt;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        p[i] = cnt[a[i]];
    }
    build(0, 0, n-1);
    cnt.clear();
    long long ans = 0;
    for(int i = n-1; i > 0; i--) {
        cnt[a[i]]++;
        ans += query(0, 0, n-1, 0, i-1, cnt[a[i]]);
    }
    printf("%I64d", ans);
    return 0;
}