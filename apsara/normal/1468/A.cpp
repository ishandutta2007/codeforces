#include <bits/stdc++.h>
using namespace std;

const int N = 500000 + 9;

int a[N], sk[N], top, len[N];

vector<int> vc[N];

struct Segment_Tree{
    int m, maxv[N*4];
    void init(int n){
        for (m = 1; m <= n; m <<= 1);
        memset(maxv, 0, (m*2+5) * sizeof(*maxv));
    }
    void upd(int o, int k){
        o |= m; maxv[o] = max(maxv[o], k);
        for (o >>= 1; o; o >>= 1) maxv[o] = max(maxv[o<<1], maxv[o<<1|1]);
    }
    int q(int L, int R){
        int res = 0;
        for (--L += m, ++R += m; R-L ^ 1; L >>= 1, R >>= 1){
            if ((~L & 1) && maxv[L^1] > res) res = maxv[L^1];
            if ((R & 1) && maxv[R^1] > res) res = maxv[R^1];
        }
        return res;
    }
} segt;

void solve(){
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    for (int i = 1; i <= n; ++i) vc[i].clear();
    memset(len, 0, (n+5) * sizeof(*len));
    top = 0;
    for (int i = n; i >= 1; --i){
        while (top && a[i] > a[sk[top]]){
            vc[i].push_back(sk[top]); --top;
        }
        sk[++top] = i;
    }
    segt.init(n);
    for (int i = 1; i <= n; ++i){
        for (int j : vc[i]){
            len[j] = max(len[j], segt.q(1, a[j]) + 2);
        }
        len[i] = max(len[i], segt.q(1, a[i]) + 1);
        segt.upd(a[i], len[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, len[i]);
    printf("%d\n", ans);
}

int main(){
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}