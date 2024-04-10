#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=2e9;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
//#define int ll

int color[maxn];
vector<int> G[maxn];
int v[maxn],t[maxn];
bool is_bi = 1;

void dfs(int now) {
    for (int i:G[now]) {
        if (!color[i]) {
            color[i]=3-color[now];
            dfs(i);
        }
        else if (color[i]==color[now]) is_bi=0;
    }
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int t_; cin>>t_;
    while (t_--) {
        int n,m; cin>>n>>m;
        for (int i=1;i<=n;i++) G[i].clear(),color[i]=0;
        is_bi=1;

        for (int i=1;i<=n;i++) cin>>v[i];
        for (int i=1;i<=n;i++) cin>>t[i];

        ll sum=0;
        for (int i=1;i<=n;i++) sum+=(v[i]-t[i]);

        for (int i=1;i<=m;i++) {
            int x,y; cin>>x>>y;
            G[x].pb(y);
            G[y].pb(x);
        }
        if (sum&1) {
            cout<<"NO\n";
            continue;
        }

        color[1]=1,dfs(1);
        if (!is_bi) cout<<"YES\n";
        else {
            ll sum2=0;
            for (int i=1;i<=n;i++) {
                if (color[i]==1) sum2+=(v[i]-t[i]);
                else sum2-=(v[i]-t[i]);
            }
            if (sum2==0) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}