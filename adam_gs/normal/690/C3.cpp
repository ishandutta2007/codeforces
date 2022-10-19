#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
const int LIM=2e5+7, LG=20;
vector<int>V[LIM];
int odl[LIM], pre[LIM], post[LIM], nxt[LIM][LG], lpre, lpost;
void DFS(int x) {
    ++lpre;
    pre[x]=lpre;
    for(auto i : V[x]) {
        nxt[i][0]=x;
        odl[i]=odl[x]+1;
        DFS(i);
    }
    ++lpost;
    post[x]=lpost;
}
bool oc(int a, int b) {
    return pre[a]<=pre[b] && post[a]>=post[b];
}
int lca(int a, int b) {
    if(oc(a, b)) return a;
    if(oc(b, a)) return b;
    for(int i=LG-1; i>=0; --i) if(!oc(nxt[a][i], b)) a=nxt[a][i];
    return nxt[a][0];
}
int odleglosc(int a, int b) {
    return odl[a]+odl[b]-2*odl[lca(a, b)];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i, n-1) {
        int a;
        cin >> a; --a;
        V[a].pb(i+1);
    }
    DFS(0);
    for(int j=1; j<LG; ++j) {
        rep(i, n) nxt[i][j]=nxt[nxt[i][j-1]][j-1];
    }
    int ans=0, a=0, b=0;
    for(int i=1; i<n; ++i) {
        int x=odleglosc(a, i), y=odleglosc(i, b);
        if(max(x, y)>ans) {
            ans=max(x, y);
            if(x>y) b=i; else a=i;
        }
        cout << ans << " ";
    }
}