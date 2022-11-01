#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

const int N = 1e6;
map<int, int> last;
int n, m, a[N], cnt[N], ans[N], xr[N];
vector<pair<int, int> > ask[N];

void upd(int c, int delta) {
    for(int i = c; i < n; i |= i+1)
        cnt[i] ^= delta;
}

int get(int c) {
    int res = 0;
    for(int i = c; i >= 0; i &= i+1, i--)
        res ^= cnt[i];
    return res;
}

int get(int l, int r) {
    return get(r) ^ (l ? get(l-1) : 0);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        last[a[i]] = -1;
        xr[i] = (i ? xr[i-1] : 0) ^ a[i];
    }
    scanf("%d", &m);
    for(int i = 0, l, r; i < m; i++) {
        scanf("%d%d", &l, &r);
        ask[r - 1].push_back(make_pair(l - 1, i));
    }
    for(int i = 0; i < n; i++) {
        int r = last[a[i]];
        if(r != -1)
            upd(r, a[i]);
        upd(i, a[i]);
        last[a[i]] = i;
        for(int j = 0, sz = (int)ask[i].size(); j < sz; j++) {
            pair<int, int> p = ask[i][j];
            ans[p.second] = get(p.first, i) ^ xr[i] ^ (p.first ? xr[p.first-1] : 0);
        }
    }
    for(int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
    return 0;
}