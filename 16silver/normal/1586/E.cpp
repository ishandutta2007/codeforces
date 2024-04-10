#include <bits/stdc++.h>
using namespace std;
int par[300001];
vector<vector<int>> adj;
vector<pair<int,int>> qrys;
int gg[300001], lv[300001];
int cnt[300001];
int fd(int a){
    return (a==par[a]?a:par[a]=fd(par[a]));
}
bool zz(int a, int b){
    a=fd(a); b=fd(b);
    if(a==b) return false;
    if(a!=b) par[a]=b;
    return true;
}
void dfs(int a){
    for(int x : adj[a]){
        if(x!=gg[a]){
            gg[x]=a;
            lv[x]=lv[a]+1;
            dfs(x);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    adj.resize(n+1);
    for(int i=1;i<=n;i++) par[i] = i;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(zz(a,b)){
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    dfs(1);
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        qrys.emplace_back(a,b);
        cnt[a]++; cnt[b]++;
    }
    int ans = 0;
    for(int i=1;i<=n;i++) if(cnt[i]%2) ans++;
    if(ans){
        cout << "NO\n";
        cout << ans/2 << "\n";
    }
    else{
        cout << "YES\n";
        for(int i=0;i<q;i++){
            vector<int> ppap, ppbp;
            int ppcp = qrys[i].first, ppdp = qrys[i].second;
            ppap.push_back(ppcp);
            ppbp.push_back(ppdp);
            while(lv[ppcp]>lv[ppdp]){
                ppcp = gg[ppcp];
                if(ppcp!=ppdp) ppap.push_back(ppcp);
            }
            while(lv[ppcp]<lv[ppdp]){
                ppdp = gg[ppdp];
                if(ppcp!=ppdp) ppbp.push_back(ppdp);
            }
            while(ppcp!=ppdp){
                ppcp = gg[ppcp];
                ppap.push_back(ppcp);
                ppdp = gg[ppdp];
                if(ppcp!=ppdp) ppbp.push_back(ppdp);
            }
            ppcp=ppap.size();
            ppdp=ppbp.size();
            cout << ppcp+ppdp << "\n";
            for(int j=0;j<ppcp;j++) cout << ppap[j] << " ";
            for(int j=ppdp-1;j>=0;j--) cout << ppbp[j] << " ";
            cout << "\n";
        }
    }
}