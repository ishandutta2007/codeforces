#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+3;
int inf=1e9+7;
void solve(){
    int n,mi=inf;
    cin>>n;
    int x[n];
    for(int &i:x) cin>>i;
    sort(x,x+n);
    int c=1,cnt[n+1]={};
    for(int i=1;i<n;i++){
        if(x[i]==x[i-1]) c++;
        else{
            cnt[c]++;
            c=1;
        }
    }
    cnt[c]++;
    vector<pair<int,int>>v;
    int ans=n;

    for(int i=1;i<=n;i++) if(cnt[i]){
        v.push_back({i,cnt[i]});
        mi=min(mi,i);
    }
    for(int i=2;i<=min(mi+2,n);i++){
        int tmp=0,imp=0;
        for(auto j:v){
            if(j.first%(i-1)>j.first/(i-1)) imp=1;
            tmp+=((j.first+i-1)/i)*j.second;
        }
        if(!imp) ans=min(ans,tmp);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}