#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+7;

int a[maxn];
vector<int> G[maxn];
int sum[maxn];
int have[maxn];
int xorsum;

bool ans;

void dfs(int now,int p) {
    sum[now]=0,have[now]=0;

    int cnt=0;
    for (int i:G[now]) {
        if (i==p) continue;
        dfs(i,now);
        sum[now]^=sum[i];
        have[now]=max(have[now],have[i]);
        if (have[i]) cnt++;
    }

    sum[now]^=a[now];
    if (xorsum==sum[now]) have[now]=1;
    if (sum[now]==0 && have[now]) ans=1;
    if (cnt>=2) ans=1;
    //cout<<now<<' '<<have[now]<<' '<<sum[now]<<'\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while (t--) {
        int n,k; cin>>n>>k;

        xorsum=0;
        ans=0;
        for (int i=1;i<=n;i++) {
            cin>>a[i];
            G[i].clear();
            xorsum^=a[i];
        }



        for (int i=1;i<=n-1;i++) {
            int u,v; cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        if (xorsum==0) {
            cout<<"YES\n";
            continue;
        }
        if (k==2) {
            cout<<"NO\n";
            continue;
        }

        dfs(1,-1);
        cout<<(ans ? "YES\n" : "NO\n");
    }
}