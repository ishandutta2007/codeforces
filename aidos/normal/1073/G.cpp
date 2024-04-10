#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n, q;
string s;
int suff[maxn];
int col[maxn];
int head[maxn];
int nsuff[maxn];
int ncol[maxn];
int pos[maxn];
int lcp[maxn];
int lg[maxn];
int t[18][maxn];
bool cmps(int i, int j) {
    return s[i] < s[j];
}
void suffix_array() {
    s += "#";
    n++;
    for(int i = 0; i < n; i++) {
        suff[i] = i;
    }
    sort(suff,suff + n, cmps);
    int cn = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0 || s[suff[i]] != s[suff[i-1]]) {
            col[suff[i]] = cn;
            head[cn] = i;
            cn++;
        } else {
            col[suff[i]] = cn - 1;
        }
    }
    for(int len = 1; len <= n; len *= 2) {
        for(int i = 0; i < n; i++) {
            int j = suff[i] - len;
            if(j < 0) j += n;
            int c = col[j];
            nsuff[head[c]++] = j;
        }
        cn = 0;
        for(int i = 0; i < n; i++) {
            if(i == 0 || col[nsuff[i]] != col[nsuff[i - 1]] || col[(nsuff[i] + len) % n] != col[(nsuff[i-1] + len) % n]) {
                ncol[nsuff[i]] = cn;
                head[cn] = i;
                cn++;
            } else {
                ncol[nsuff[i]] = cn-1;
            }
        }
        for(int i = 0; i < n; i++) {
            suff[i] = nsuff[i];
            col[i] = ncol[i];
        }
    }
    for(int i = 0; i < n; i++) {
        suff[i] = suff[i + 1];
    }
    n--;
    for(int i = 0; i < n; i++) {
        pos[suff[i]] = i;
    }
    s.pop_back();
    int len = 0;
    for(int i = 0; i < n; i++) {
        int j = pos[i];
        if(j == n-1) {
            len = 0;
            lcp[j] = 0;
            continue;
        }
        while(suff[j] + len < n && suff[j + 1] + len < n && s[suff[j] + len] == s[suff[j + 1] + len]) {
            len++;
        }
        lcp[j] = len;
        len = max(len-1, 0);
    }
    for(int i = 0; i < n; i++) {
        t[0][i] = lcp[i];
    }
    lg[0] = -1;
    for(int i = 1; i <= n; i++) {
        lg[i]=lg[i/2] + 1;
    }
    for(int len = 1; (1<<len) <= n; len++) {
        for(int i = 0; i + (1<<len) - 1 < n; i++) {
            t[len][i] = min(t[len-1][i], t[len-1][i+(1<<(len-1))]);
        }
    }
}
int get_min(int l, int r) {
    if(l == r+1) {
        return n - suff[l];
    }
    int len = lg[r-l + 1];
    return min(t[len][l], t[len][r-(1<<len) + 1]);
}
int p[maxn];
int get(int v) {
    if(p[v] == v) return v;
    return p[v] = get(p[v]);
}
int sz[maxn][2];
void calc() {
    int x, y;
    vector<pii> a;
    cin >> x >> y;
    y += x;
    for(int i = 0; i < y; i++) {
        int z;
        cin >> z;
        z--;
        a.emplace_back(make_pair(pos[z], i < x));
    }
    sort(a.begin(), a.end());
    vector < pii > w;
    for(int i = 0; i + 1 < a.size(); i++) {
        w.emplace_back(make_pair(get_min(a[i].first, a[i+1].first-1), i));
    }
    sort(w.begin(), w.end());
    for(int i = 0; i < y; i++) {
        p[i] = i;
        sz[i][0] = sz[i][1] = 0;
        sz[i][a[i].second] = 1;
    }
    reverse(w.begin(), w.end());
    ll ans = 0;
    for(int i = 0; i < w.size(); i++) {
        ll d = w[i].first;
        int l = w[i].second;
        int r = l + 1;
        int pa = get(l);
        int pb = get(r);
        ans += d * sz[pa][0] * sz[pb][1];
        ans += d * sz[pa][1] * sz[pb][0];
        p[pa] = pb;
        sz[pb][0] += sz[pa][0];
        sz[pb][1] += sz[pa][1];
        //cout << l << " " << r << " " << d << "\n";
    }
    cout << ans << "\n";
}
void solve(){
    cin >> n >> q >> s;
    suffix_array();
    for(int i = 0; i < n; i++) {
        //cout << s.substr(suff[i]) << "\n";
        //if(i + 1 < n) cout << get_min(i, i) << "\n";
    }
    for(int i = 0; i < q; i++) {
        calc();
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