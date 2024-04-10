#include <bits/stdc++.h>
#define pb push_back
#define sz(a) ((int) a.size())
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
const int N = 100000;
int n, q, TIME = 0, out[N], h[N], r[N], prv[N];
vector<int> tr[N], es, ln(5*N, 0);
pii st[5*N][20];

void dfs(int v, int pr, int deep) {
    h[v] = deep++;
    r[v] = sz(es);
    es.pb(v);
    for(int i=0, sz=sz(tr[v]); i<sz; i++)
        if(tr[v][i] != pr)
            TIME++, prv[tr[v][i]]=v, dfs(tr[v][i], v, deep), r[v] = sz(es), es.pb(v);
    out[v] = TIME++;
}

pii get(int l, int r) { // < h, v >
    int log = ln[r-l+1];
    return min(st[l][log], st[r - (1<<log) + 1][log]);
}

int LCA(int u, int v) {
    u = r[u]; v = r[v];
    if(u > v) swap(u, v);
    return get(u, v).ss;
}

int solve(int p, vector<int> &dp, vector<int> tr[], bool is[]) {
    int cnt = 0;
    for(int i=0, sz=sz(tr[p]); i<sz; i++)
        cnt += solve(tr[p][i], dp, tr, is), dp[p] += dp[tr[p][i]];
    if(is[p]) {
        dp[p] += cnt;
        return 1;
    }
    if(cnt==1)
        return 1;
    if(cnt>1) {
        dp[p]++;
        return 0;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=1, u, v; i<n; i++)
        cin >> u >> v, u--, v--, tr[u].pb(v), tr[v].pb(u);
    dfs(0, 0, 0);
    int m = sz(es), esl = 0;
    for(int p = 1; p<=m; p*=2, esl++) ln[p] = esl;
    for(int i=2; i<=m; i++) if(!ln[i]) ln[i] = ln[i-1];
    for(int i=0; i<m; i++) st[i][0] = {h[es[i]], es[i]};
    for(int j=1; j<=esl; j++) for(int i=0; i<m; i++)
        if(i + (1<<j) <= m)
            st[i][j] = min(st[i][j-1], st[i + (1<<(j-1))][j-1]);
    vector<bool> now(n, 0);
    cin >> q;
    for(int i=0, k; i<q; i++) {
        cin >> k;
        vector<int> c(k);
        for(int i=0; i<k; i++) cin >> c[i], c[i]--, now[c[i]]=1;
        bool stop = 0;
        for(int i=0; i<k; i++) if(c[i]&&now[prv[c[i]]]) { stop=1; break; }
        for(int i=0; i<k; i++) now[c[i]]=0;
        if(stop) { cout<<"-1\n"; continue; }
        sort(c.begin(), c.end(), [](int p1, int p2){ return out[p1]<out[p2]; });
        vector<int> cl(1, c[0]);
        for(int i=1; i<k; i++) cl.pb(LCA(c[i-1], c[i])), cl.pb(c[i]);
        sort(cl.begin(), cl.end(), [](int p1, int p2){ return out[p1]<out[p2]; });
        vector<int> cll;
        for(int i=0, sz=sz(cl); i<sz; i++) if(!i || cl[i]!=cl[i-1]) cll.pb(cl[i]);
        vector<int> t[cll.size()];
        stack<pii> st;
        for(int i=0, sz=sz(cll); i<sz; i++) {
            while(!st.empty() && LCA(cll[i], st.top().ff)==cll[i])
                t[i].pb(st.top().ss), st.pop();
            st.push({cll[i], i});
        }
        vector<int> dp(sz(cll), 0);
        bool is[sz(cll)];
        for(int i=0,j=0,sz=sz(cll); i<sz; i++) if(j<k&&c[j]==cll[i]) {is[i]=1; j++;} else is[i]=0;
        solve(sz(cll)-1, dp, t, is);
        cout << dp.back() << "\n";
    }
    return 0;
}