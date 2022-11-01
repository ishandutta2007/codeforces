#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
//#define int ll

const int maxn = 1e6;
const int mod = 998244353;
const int inf = 1e9;
const ll inf64 = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-6;

int n, a[maxn], b[maxn];
pii c[maxn];
int diff;
bitset<2000000> ban, done;
vi who[2 * maxn];
int x;

void dfs(int v, int man) {
    if(man) {
        done[v] = 1;
        diff++;
        if(!ban[a[v]]) dfs(a[v], 0);
        if(!ban[b[v]] && b[v] <= x) dfs(b[v], 0);
    } else {
        ban[v] = 1;
        diff--;
        for(int to : who[v]) if(!done[to]) dfs(to, 1);
    }
}

bool ok() {
    ban.reset();
    done.reset();
    for(int i = 0; i < n; i++) if(!done[i]) {
        diff = 0;
        dfs(i, 1);
        if(diff > 0) return false;
    }
    return true;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    int lf = 0, rg = 0;
    vi re(2 * n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        re[2 * i] = a[i];
        re[2 * i + 1] = b[i];
    }
    sort(all(re));
    re.erase(unique(all(re)), re.end());
    int dif = sz(re);
    for(int i = 0; i < n; i++) {
        int L = 0, R = dif - 1;
        while(L < R) {
            int M = (L + R) >> 1;
            if(re[M] < a[i]) L = M + 1;
            else R = M;
        }
        a[i] = L;
        L = 0, R = dif - 1;
        while(L < R) {
            int M = (L + R) >> 1;
            if(re[M] < b[i]) L = M + 1;
            else R = M;
        }
        b[i] = L;
        lf = max(lf, a[i]);
        rg = max(rg, b[i]);
    }
    for(int i = 0; i < n; i++) {
        who[a[i]].pb(i);
        who[b[i]].pb(i);
    }
    if(x = rg, !ok()) return cout << -1, 0;
    while(lf < rg) {
        int md = (lf + rg) >> 1;
        if(x = md, ok()) rg = md;
        else lf = md + 1;
    }
    cout << re[lf];
}