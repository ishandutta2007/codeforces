#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int a[maxn];
int b[maxn];
vector<int> posa[maxn], posb[maxn];
int t[4 * maxn];
int get(int v, int tl, int tr, int l, int r) {
    if(tl > r || l > tr) return inf;
    if(l <= tl && tr <= r) return t[v];
    int mid = (tl + tr)/2;
    return min(get(v*2, tl, mid, l, r), get(v * 2 + 1, mid+1, tr, l, r));
}
void upd(int v, int l, int r, int pos, int val) {
    if(l == r) {
        t[v] = val;
    } else {
        int mid = (l + r)/2;
        if(pos <= mid) upd(v*2, l, mid, pos, val);
        else upd(v * 2 + 1, mid + 1, r, pos, val);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}
void solve() {
    cin >> n;
    for(int i = 0; i <= n; i++) {
        posa[i].clear();
        posb[i].clear();
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        upd(1, 0, n-1, i, a[i]);
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for(int i = n-1; i >= 0; i--) {
        posa[a[i]].push_back(i);
        posb[b[i]].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        if(posa[b[i]].size() == 0) {
            cout << "NO\n";
            return;
        }
        int pos = posa[b[i]].back();
        posa[b[i]].pop_back();
        if(get(1, 0, n-1, 0, pos) < b[i]) {
            cout << "NO\n";
            return;
        }
        upd(1, 0, n-1, pos, inf);
    }
    cout << "YES\n";

}

int main() {
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}