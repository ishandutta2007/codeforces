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

struct sfsdgsgvkjsdgkvsad {
    int n = 0;
    vector<vector<int> > ans;
    vector<int> G[maxn];
    int used[maxn],visit[maxn];
    map<pair<ll,ll>, int> M;
    map<pair<int,int>,vector<int> > edge;
    int depth[maxn];

    int getidx(ll x,ll y) {
        ll g = __gcd(x,y);
        x/=g,y/=g;
        if (M[{x,y}]) return M[{x,y}];
        else {
            M[{x,y}]=++n;
            return M[{x,y}];
        }
    }

    void dfs(int now,int p)
    {
        vector<int> tmp,tmp2;
        visit[now]=1;
        for (int i:G[now])
            if (!visit[i]){
                depth[i]= depth[now]+1;
                dfs(i,now),tmp2.pb(i);

                if (!used[i]) tmp.pb(i);
            }
        for (int i:G[now])
            if (i!=p&&(depth[i]<depth[now])) {
                tmp.pb(i);
            }

        {
            if (p!=-1) {
                for (int i:G[now])
                    if (i==p) tmp.pb(i);
            }
            //cout<<":"<<now<<' '<<sz(tmp)<<'\n';
            //for (int i:tmp) cout<<i<<' ';
            //cout<<'\n';
            for (int i=0;i+1<sz(tmp);i+=2) ans.pb({tmp[i],now,tmp[i+1]});

            if (!(sz(tmp)&1)) used[now]=1;
            for (int i:tmp2) used[i]=1;
        }
    }

    void make_edge(ll a,ll b,ll c,ll d) {
        static int cnt = 0;
        pair<ll,ll> p1={c*b,d*(a+b)},p2={(c+d)*b,d*a};
        int x=getidx(p1.F,p1.S),y=getidx(p2.F,p2.S);
        G[x].push_back(y);
        G[y].push_back(x);
        cnt++;
        if (x>y) swap(x,y);
        //cout<<x<<' '<<y<<'\n';
        edge[{x,y}].push_back(cnt);
    }

    void solve() {
        for (int i=1;i<=n;i++)
        if (!visit[i]) dfs(i,-1);
        cout<<sz(ans)<<'\n';
        for (auto vv:ans) {
            pii p1={vv[0],vv[1]},p2={vv[1],vv[2]};
            if (p1.F>p1.S) swap(p1.F,p1.S);
            if (p2.F>p2.S) swap(p2.F,p2.S);
            cout<<edge[p1].back()<<' ';
            edge[p1].pop_back();
            cout<<edge[p2].back()<<'\n';edge[p2].pop_back();
        }
    }

}solver;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for (int i=1;i<=n;i++) {
        int a,b,c,d; cin>>a>>b>>c>>d;
        solver.make_edge(a,b,c,d);
    }
    solver.solve();
}