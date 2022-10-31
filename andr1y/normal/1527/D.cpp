// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll grt[N], res[N];
vector<ll> d[N];
ll tin[N], tout[N], timer=0, sz[N], pp[N], h[N];
bool act[N];
void dfs(ll v, ll p=-1){
    tin[v]=++timer;
    sz[v]=1;
    pp[v]=p;
    h[v]=(p==-1?0:h[p]+1);
    for(auto i : d[v]){
        if(i==p) continue;
        dfs(i, v);
        sz[v]+=sz[i];
    }
    tout[v]=timer;
}
bool upper(ll a, ll b){
    return tin[a]<=tin[b]&&tout[a]>=tout[b];
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin>>n;
        for(ll a, b, i=1;i<n;i++){
            cin>>a>>b;
            d[a].push_back(b);
            d[b].push_back(a);
        }
        for(ll i =0;i<n;i++){
            act[i]=0, timer=0, tin[i]=0, tout[i]=0;
        }
        for(ll i = 0;i<=n+3;i++) grt[i]=0;
        grt[0]=(n*(n-1))/2;
        dfs(0);
        ll v1=0, v2=0, gov1=0, gov2=0;
        act[0]=1;
        ll actn=1;
        ll ts=1;
        for(auto i : d[0]){
            grt[1]+=ts*sz[i];
            ts+=sz[i];
        }
        for(ll i = 1;i<n;i++){
            if(act[i]){
                grt[i+1]=grt[i];
                continue;
            }
            if(v1==0||upper(v1, i)){
                v1=i;
                while(!act[v1]){
                    if(h[v1]==1) gov1=v1;
                    act[v1]=1, v1=pp[v1], actn++;
                }
                v1=i;
            }else if(v2==0||upper(v2, i)){
                ll vv2=v2;
                v2=i;
                while(!act[v2]){
                    if(h[v2]==1) gov2=v2;
                    act[v2]=1, v2=pp[v2], actn++;
                }
                if(v2!=vv2){
                    //printf("BRK1 %lld %lld %lld %lld\n", v1, v2, i, vv2);
                    break;
                }
                v2=i;
            }else{
                //cout<<"BRK2\n";
                break;
            }
            //printf("COUNT %lld : %lld %lld %lld %lld\n", i+1, v1, v2, sz[v1|v2], actn);//DEB
            grt[i+1] = ((v1!=0&&v2!=0)?(sz[v1]*sz[v2]):(sz[v1|v2]*(n-sz[gov1|gov2])));
        }
        //for(ll i = 0;i<=n;i++) cout<<grt[i]<<' ';cout<<'\n';//DEB
        for(ll i = 0;i<=n;i++) cout<<grt[i]-grt[i+1]<<' ';
        cout<<'\n';
        for(ll i = 0;i<n;i++) d[i].clear();
    }
}