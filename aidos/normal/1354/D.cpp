#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;

int n, k;
int t[4 * maxn];
int q;
void add(int v, int tl, int tr, int pos, int val) {
    if(tl == tr) {
        t[v]++;
    }else {
        int mid = (tl + tr)/2;
        if(pos <= mid) add(v * 2, tl, mid, pos, val);
        else add(v * 2 + 1, mid + 1, tr, pos, val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
int pos;
void rec(int v, int tl, int tr, int k) {
    if(tl == tr) {
        t[v]--;
        pos = tl;
        return;
    }
    int mid = (tl + tr)/2;
    if(t[v * 2] >= k) rec(v * 2, tl, mid, k);
    else rec(v * 2 + 1, mid+1, tr, k-t[v * 2]);
    t[v]--;
}
void solve() {
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        add(1, 1, n, x, 1);
    }
    for(int i = 1; i <= q; i++) {
        int x;
        scanf("%d", &x);
        if(x < 0) rec(1, 1, n, -x);
        else add(1, 1, n, x, 1);
    }
    pos = 0;
    if(t[1] > 0) {
        rec(1, 1, n, 1);
    }
    cout << pos << "\n";
}

int main() {
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