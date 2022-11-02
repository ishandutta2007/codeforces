#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n;
int a[maxn];
string s;
struct node{
    int l, r, ans;
    node() {
        l = 0;
        r = 0;
        ans = 0;
    }
};
node t[maxn * 4];
node merge(node x, node y) {
    node z;
    int mi = min(x.l, y.r);
    z.ans = x.ans + y.ans + mi;
    z.l = x.l + y.l - mi;
    z.r = x.r + y.r - mi;
    return z;
}
void build(int v, int l,int r) {
    if(l == r) {
        if(s[l] == '(') {
            t[v].l = 1;
        }else {
            t[v].r = 1;
        }
        return;
    }
    int mid = (l + r)/2;
    build(v*2, l, mid);
    build(v*2+1, mid+1, r);
    t[v] = merge(t[v*2], t[v*2+1]);
}
node get(int v, int tl, int tr, int l, int r) {
    if(tl > r || tr < l) return node();
    if(l <= tl && tr <= r) {
        return t[v];
    }
    int mid = (tl + tr)/2;
    return merge(get(v*2, tl, mid, l, r), get(v*2+1, mid+1, tr, l, r));
}
void solve() {
    cin >> s;
    n = s.size();
    build(1, 0, n-1);
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << get(1, 0, n-1,l-1,r-1).ans*2 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}