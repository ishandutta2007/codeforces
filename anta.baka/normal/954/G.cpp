#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int INF = 1e9, maxn = 5e5;

ll add[maxn], a[maxn];
int n, r;
ll k;

inline bool can(ll x) {
    memset(add, 0, sizeof(add));
    ll ost = k;
    for(int i = 0; i < n; i++) {
        if(i) add[i] += add[i - 1];
        if(a[i] + add[i] >= x) continue;
        ll need = x - (a[i] + add[i]);
        ost -= need;
        if(ost < 0) return false;
        add[i] += need;
        if(i + 2 * r < n) add[i + 2 * r + 1] -= need;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> r >> k;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        add[max(0, i - r)] += x;
        if(i + r + 1 < n) add[i + r + 1] -= x;
    }
    ll lf = 2e18, rg = 2e18;
    for(int i = 0; i < n; i++) {
        if(i) add[i] += add[i - 1];
        lf = min(lf, add[i]);
        a[i] = add[i];
    }
    while(lf < rg) {
        ll md = (lf + rg + 1) >> 1;
        if(can(md)) lf = md;
        else rg = md - 1;
    }
    cout << lf;
}