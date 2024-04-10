#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;
int n,m;
vector<int> v[3500];
ll get(int k){
    int cnt=v[1].size();
    vector<int> p;
    ll res=0;
    for(int i=2;i<=m;i++){
        int q=max(0,(int)v[i].size()-k+1);
        for(int j=0;j<q;j++)
            res+=v[i][j],cnt++;
        for(int j=q;j<v[i].size();j++)
            p.pb(v[i][j]);
    }
    //cout<<res<<" "<<cnt<<" "<<k<<endl;
    sort(p.begin(),p.end());
    for(int i=0;i<k-cnt;i++)
        res+=p[i];
    return res;              
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int p,c;
        scanf("%d%d",&p,&c);
        v[p].pb(c);
    }
    for(int i=1;i<=m;i++)
        sort(v[i].begin(),v[i].end());
    ll ans=1e18;
    for(int i=1;i<=n;i++)
        ans=min(ans,get(i));
    printf("%lld",ans);
}