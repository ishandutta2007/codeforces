#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, k, m;
int st[maxn];
int len[maxn];
vector<int> a;
int suff[maxn];
int nsuff[maxn];
int col[maxn];
int ncol[maxn];
int head[maxn];
int pos[maxn];
int lcp[maxn];
int t_min[20][maxn];
int lg[maxn];
int last[maxn];
int cmp_char(int i, int j) {
    return a[i] < a[j];
}
void suffix_array() {
    m = a.size();
    for(int i = 0; i < m; i++) {
        suff[i] = i;
    }
    sort(suff, suff + m, cmp_char);
    int cn = 0;
    for(int i = 0; i < m; i++) {
        if(i == 0 || a[suff[i]] != a[suff[i-1]]) {
            col[suff[i]] = cn;
            head[cn]=i;
            cn++;
        } else{
            col[suff[i]] = cn-1;
        }
    }
    for(int t = 1; t <= m; t *= 2) {
        for(int i = 0; i < m; i++) {
            int c = (suff[i] + m - t) % m;
            nsuff[head[col[c]]++] = c;
        }
        cn = 0;
        for(int i = 0; i < m; i++) {
            if(i == 0 || col[nsuff[i]] != col[nsuff[i-1]] || col[(nsuff[i]+t) % m] != col[(nsuff[i-1] + t) % m]) {
                ncol[nsuff[i]] = cn;
                head[cn] = i;
                cn++;
            } else {
                ncol[nsuff[i]] = cn-1;
            }
        }
        for(int i = 0; i < m; i++) {
            suff[i] = nsuff[i];
            col[i] = ncol[i];
        }
    }
    for(int i = 0; i < m; i++) {
        pos[suff[i]] = i;
    }
    int L = 0;
    for(int i = 0; i < m; i++) {
        int j = pos[i];
        if(j == m - 1) {
            lcp[j] = 0;
            L = 0;
            continue;
        }
        while(i + L < m && a[i + L] == a[suff[j + 1] + L]) {
            L++;
        }
        lcp[j] = L;
        L = max(L-1, 0);
    }
}
vector<int> T[4 * maxn];
int val[maxn];
int nxt[maxn];
void build(int v, int l, int r) {
    if(l == r) {
        T[v].emplace_back(nxt[r]);
    } else {
        int mid = (l + r)/2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        for(const int &x: T[v * 2]) T[v].emplace_back(x);
        for(const int &x: T[v * 2 + 1]) T[v].emplace_back(x);
        sort(T[v].begin(), T[v].end());
    }
}
int get(int v, int tl, int tr, int l, int r) {
    if(tl > r || l > tr) return 0;
    if(l <= tl && tr <= r) {
        return T[v].end() - upper_bound(T[v].begin(), T[v].end(), r);
    }
    int mid = (tl + tr)/2;
    return get(v * 2, tl, mid, l, r) + get(v * 2 + 1, mid + 1, tr, l, r);
}
int get_lcp(int l, int r){
    if(l == r) {
        return inf;
    }
    int len = lg[r-l];
    return min(t_min[len][l], t_min[len][r-(1<<len)]);
}
bool good(int st, int en) {
    if(k == 1) return 1;
    int P = pos[st];
    int L = P, R = m-1;
    int resR = P;
    while(L<=R) {
        int mid = (L + R)/2;
        if(get_lcp(P, mid) >= en - st + 1) {
            L = mid+1;
            resR = mid;
        }else {
            R = mid-1;
        }
    }
    L = 0, R = P;
    int resL = P;
    while(L<=R) {
        int mid = (L + R)/2;
        if(get_lcp(mid, P) >= en - st + 1) {
            R = mid-1;
            resL = mid;
        }else {
            L = mid+1;
        }
    }
    return get(1, 0, m-1, resL, resR) >= k;
}

void precalc() {
    for(int i = 0; i < m; i++) {
        t_min[0][i] = lcp[i];
    }
    lg[0] = -1;
    for(int i = 1; i <= m; i++) {
        lg[i] = lg[i/2] + 1;
    }
    for(int t = 1; (1<<t) <= m; t++) {
        for(int j = 0; j+(1<<t) <= m; j++) {
            t_min[t][j] = min(t_min[t-1][j], t_min[t-1][j + (1<<(t-1))]);
        }
    }

    for(int i = m-1; i >= 0; i--) {
        int p = val[suff[i]];
        if(last[p] == 0) {
            nxt[i] = m;
        } else {
            nxt[i] = last[p];
        }
        last[p] = i;
    }
    build(1, 0, m-1);
}


void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        st[i] = a.size();
        len[i] = s.size();
        for(const char &c: s) {
            val[a.size()] = i;
            a.emplace_back(c-'a');
        }
        a.emplace_back(-i);
    }
    suffix_array();
    precalc();
    for(int i = 1; i <= n; i++) {
        int st_pos = st[i];
        int en = st_pos - 1;
        ll ans = 0;
        for(int j = 0; j < len[i]; j++) {
            int cur = st_pos + j;
            if(cur > en) {
                en = cur;
            }
            while(en + 1 < st_pos + len[i] && good(cur, en + 1)) {
                en++;
            }
            if(good(cur, en)) {
                ans += en - cur + 1;
            }
        }
        cout << ans << "\n";
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