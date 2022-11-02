#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m, k;
string s;
int rev[4 * maxn];
struct node {
    int cnta, cntb, ab, ba;
};
node t[4*maxn];
node merge(node a, node b) {
    node res;
    res.cnta = a.cnta + b.cnta;
    res.cntb = a.cntb + b.cntb;
    res.ab = max(a.ab+b.cntb, a.cnta + b.ab);
    res.ba = max(a.ba + b.cnta, a.cntb + b.ba);
    return res;
}
void build(int v, int l, int r) {
    if(l == r) {
        t[v].cnta = s[l] == '4';
        t[v].cntb = s[l] == '7';
        t[v].ab = 1;
        t[v].ba = 1;
    } else {
        int mid = (l + r)/2;
        build(v * 2,l,mid);
        build(v*2+1, mid+1, r);
        t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }
}
void push(int v) {
    if(rev[v]) {
        swap(t[v*2].ab, t[v*2].ba);
        swap(t[v*2].cnta, t[v*2].cntb);
        rev[2*v] ^= 1;

        swap(t[v*2+1].ab, t[v*2+1].ba);
        swap(t[v*2+1].cnta, t[v*2+1].cntb);
        rev[2*v+1] ^= 1;
        rev[v] = 0;
    }
}
void upd(int v, int tl, int tr, int l,int r) {
    if(tr < l || r < tl) return;
    if(l <= tl && tr <= r) {
        swap(t[v].ab, t[v].ba);
        swap(t[v].cnta, t[v].cntb);
        rev[v] ^= 1;
        return;
    }
    push(v);
    int mid = (tl + tr)/2;
    upd(v * 2, tl, mid, l, r);
    upd(v * 2 + 1, mid+1, tr, l, r);
    t[v] = merge(t[v*2],t[v * 2 + 1]);

}

void solve() {
    cin >> n >> m;
    cin >> s;
    build(1, 0, n-1);
    for(int i = 0; i < m; i++) {
        cin >> s;
        if(s[0] == 'c') {
            cout << t[1].ab << "\n";
        } else {
            int l, r;
            cin >> l >> r;
            upd(1, 0, n-1, l-1, r-1);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}