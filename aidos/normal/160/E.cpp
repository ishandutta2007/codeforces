#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
int s[maxn];
int f[maxn];
int l[maxn];
int r[maxn];
int t[maxn];
vector<int> g[maxn], q[maxn];
int ans[maxn];
vector<int> ti, co;
set<pii> S[maxn];
pii T[maxn * 4];
void build(int v, int l, int r) {
    if(l == r) {
        T[v] = make_pair(-1, -1);
    } else {
        int mid = (l + r)/2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        T[v] = make_pair(-1, -1);
    }
}
void add(int v, int tl, int tr, int pos, pii val) {
    if(tl == tr){
        S[pos].insert(val);
        T[v] = *(--S[pos].end());
    } else {
        int mid = (tl + tr)/2;
        if(pos <= mid) add(v*2, tl, mid, pos, val);
        else add(v*2 + 1, mid+1, tr, pos, val);
        T[v] = max(T[v*2], T[v*2+1]);
    }
}
void del(int v, int tl, int tr, int pos) {
    if(tl == tr){
        S[pos].erase(--S[pos].end());
        if(S[pos].size() > 0) {
            T[v] = *(--S[pos].end());
        }
        else {
            T[v] = make_pair(-1, -1);
        }
    } else {
        int mid = (tl + tr)/2;
        if(pos <= mid) del(v*2, tl, mid, pos);
        else del(v*2 + 1, mid+1, tr, pos);
        T[v] = max(T[v*2], T[v*2+1]);
    }
}
pii get(int v, int tl, int tr, int l, int r) {
    if(tl > r || l > tr) return make_pair(-1, -1);
    if(l <= tl && tr <= r) {
        return T[v];
    }
    int mid = (tl + tr)/2;
    return max(get(v*2, tl, mid, l, r), get(v*2+1, mid+1, tr, l, r));
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n + m; i++) {
        cin >> l[i] >> r[i] >> t[i];
        ti.emplace_back(t[i]);
        co.emplace_back(l[i]);
        co.emplace_back(r[i]);
        ans[i] = -1;
    }
    sort(ti.begin(), ti.end());
    ti.resize(unique(ti.begin(), ti.end()) - ti.begin());

    sort(co.begin(), co.end());
    co.resize(unique(co.begin(), co.end()) - co.begin());
    for(int i = 0; i < n + m; i++) {
        l[i] = lower_bound(co.begin(), co.end(), l[i]) - co.begin();
        r[i] = lower_bound(co.begin(), co.end(), r[i]) - co.begin();
        t[i] = lower_bound(ti.begin(), ti.end(), t[i]) - ti.begin();
        if(i >= n) {
            q[t[i]].emplace_back(i);
        } else {
            g[t[i]].emplace_back(i);
        }
    }
    build(1, 0, co.size()-1);
    for(int i = 0; i < ti.size(); i++) {
        for(int id: q[i]) {
            add(1, 0, co.size()-1, r[id], make_pair(l[id], id));
        }
        for(int id: g[i]) {
            int L=l[id];
            int R = r[id];
            pii h = get(1, 0, co.size()-1, l[id], r[id]);
            while(h.first >= l[id]) {
                ans[h.second] = id + 1;
                del(1, 0, co.size()-1, r[h.second]);
                h = get(1, 0, co.size()-1, l[id], r[id]);
            }
        }

    }
    for(int i = n; i < n + m; i++) {
        cout << ans[i] << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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