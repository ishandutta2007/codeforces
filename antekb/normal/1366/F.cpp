#include<bits/stdc++.h>
#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<pair<ld, ld>, int> pld;
const int N=2005, mod=1e9+7;
const ll INF=1e18;
ll dp[2*N][N];
vector<pii> E[N];
int wsp[N];
int n, m, q;
int main(){
    //n=5;
    //m=n-1;
    //q=1e9;
    cin>>n>>m>>q;
    for(int i=0; i<m; i++){
        int u=0, v=0, w=0;
        cin>>u>>v>>w;
        /*u=i+1;
        v=i+2;
        if(i+3<n)w=999999;
        else if(i==n-3)w=1;
        else w=1e6;*/
        E[u].pb(mp(v, w));
        E[v].pb(mp(u, w));
        wsp[u]=max(wsp[u], w);
        wsp[v]=max(wsp[v], w);
    }
    for(int i=2; i<=n; i++){
        dp[0][i]=INF;
    }
    ll ans=0;
    ll maks2;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(dp[i-1][j]==INF){
                continue;
            }
            for(auto u:E[j]){
                dp[i][u.st]=max(dp[i][u.st], dp[i-1][j]+u.nd);
            }
        }
        maks2=0;
        for(int j=1; j<=n; j++){
            if(dp[i][j]==0){
                dp[i][j]=INF;
            }
            else{
                maks2=max(maks2, dp[i][j]);
            }
        }

        if(i<=q) ans=(ans+maks2)%mod;
    }
    //cout<<"\n\n";
    if(q<=m){
        cout<<ans;
        return 0;
    }
    q-=m;
    /*ans=(ans+maks2*1ll*q)%mod;
    q=((q*1ll*(q+1))/2)%mod;
    ans=(ans+maks*1ll*q)%mod;*
    cout<<ans;*/
    stack<int> S;
    stack<ll> S2;
    vector<int> V;
    /*for(int i=0; i<=m; i++){
        for(int j=1; j<=n; ++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    /*mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    cin>>q;
    for(int i=1; i<=n; i++){
        cin>>dp[m][i]>>dp[m][i]>>wsp[i];
        wsp[i]=uniform_int_distribution<int>(1, 10000)(rng);
        dp[m][i]=uniform_int_distribution<int>(1, 10000)(rng);
    }*/
    //ans=0;
    /*ll ans2=0;
    for(int i=1; i<=q; i++){
        ll maks2=0;
        for(int j=1; j<=n; j++){
            maks2=max(maks2, dp[m][j]+i*wsp[j]);
        }
        ans2+=maks2;
    }
   cout<<ans2<<"\n";*/
    for(int i=1; i<=n; i++){
        if(dp[m][i]!=INF)V.pb(i);
        //cout<<i;
        //cout<<i<<" "<<dp[m][i]<<" "<<wsp[i]<<"\n";
    }
    //cout<<"a";
    sort(all(V), [](int x, int y){
        if(wsp[x]!=wsp[y])
        return (wsp[x]<wsp[y]);
        return (dp[m][x]>dp[m][y]);
    });
        //cout<<"a";
    for(auto i:V){
        //cout<<i<<"\n";
            while(S.size() && dp[m][S.top()]<=dp[m][i]){
                //cout<<"p";
                S.pop();
                if(sz(S2))S2.pop();
            }
            //cout<<"a";
            if(S.empty()){
                //cout<<"b";
                //cout<<i<<"a"<<dp[m][i]<<" "<<wsp[i]<<"\n";
                S.push(i);
                continue;
            }
            if(wsp[i]==wsp[S.top()])continue;
            //cout<<"b";
            //cout<<i<<"a"<<dp[m][i]<<" "<<wsp[i]<<"\n";
            ll t=(dp[m][S.top()]-dp[m][i]+(wsp[i]-wsp[S.top()]-1))/(wsp[i]-wsp[S.top()]);
            //cout<<t<<"b\n";
            while(S2.size() && t<=S2.top()){
                S.pop();
                S2.pop();
                t=(dp[m][S.top()]-dp[m][i]+(wsp[i]-wsp[S.top()]-1))/(wsp[i]-wsp[S.top()]);
                //cout<<t<<"bc\n";
            }
            //cout<<t;
            S2.push(t);
            //cout<<S2.top();
            S.push(i);

    }
    //cout<<S.size()<<sz(S2)<<S2.top()<<"\n";
    while(S.size()){
        int t;
        ll id=S.top();
        if(S2.empty()){
            t=0;
            S.pop();
        }
        else{
            if(q<S2.top()){
                S.pop();
                S2.pop();
                continue;
            }
            else{
                t=S2.top()-1;
                S.pop();
                S2.pop();
            }
        }
        //cout<<ans<<" "<<t<<" "<<q<<" "<<id<<"\n";
        ans=(ans+wsp[id]*1ll*(((q*1ll*(q+1))/2-(t*1ll*(t+1))/2)%mod))%mod;
        ans=(ans+(q-t)*1ll*(dp[m][id]%mod))%mod;
        q=t;
    }
    cout<<ans;
}