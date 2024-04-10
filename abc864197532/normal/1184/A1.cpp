#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll inf=1e12+2;
int main(){
    ll r;
    cin>>r;
    r--;
    vector<ll>v;
    for(ll i=1;i*i<=r;i++){
        if(r%i==0){
            v.push_back(i);
            v.push_back(r/i);
        }
    }
    sort(v.begin(),v.end());
    pair<ll,ll>ans={inf,inf};
    for(ll i:v){
        if(r/i-i-1>0 and (r/i-i-1)%2==0 and i<ans.first){
            ans={i,(r/i-i-1)/2};
        }
    }
    if(ans.first==inf) cout<<"NO\n";
    else cout<<ans.first<<' '<<ans.second<<'\n';
}