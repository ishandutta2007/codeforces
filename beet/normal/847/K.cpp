#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    int N,A,B,K,F;
    cin>>N>>A>>B>>K>>F;

    vector<string>X(N+1),Y(N+1);
    rep(i,N)cin>>X[i+1]>>Y[i+1];

    map<pair<string,string>,int>cnt;

    int ans=0;
    for(int i=1;i<=N;i++){
        int cost;
        if(Y[i-1]==X[i])cost=B;
        else cost=A;
        cnt[{min(X[i],Y[i]),max(X[i],Y[i])}]+=cost;
        ans+=cost;
    }

    vint lis;
    for(auto &p:cnt)lis.pb(p.se);

    sort(all(lis));
    reverse(all(lis));
    for(int i=0;i<K&&lis[i]>F&&i<lis.size();i++)ans-=lis[i]-F;
    cout<<ans<<endl;
    return 0;
}