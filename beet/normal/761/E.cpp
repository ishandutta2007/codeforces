#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 50
ll len[MAX];
typedef pair<ll,ll> P;
P pos[MAX];
vector<ll> G[MAX];
ll ax[]={1,-1,0,0};
ll ay[]={0,0,1,-1};
ll an[]={1,0,3,2};
void dfs(ll v,ll u,P p,ll d,ll l){
  if(G[v].size()>4){
    cout<<"NO"<<endl;
    exit(0);
  }
  pos[v]=p;
  int k=0;
  for(int i=0;i<(int)G[v].size();i++){
    if(G[v][i]==u) continue;
    if(k==d) k++;
    P np=p;
    np.first+=ax[k]*len[l];
    np.second+=ay[k]*len[l];
    dfs(G[v][i],v,np,an[k],l-1);
    k++;
  }
}
int main(){
  len[0]=1LL;
  for(ll i=1;i<MAX;i++) len[i]=len[i-1]*2LL;
  ll n;
  cin>>n;
  for(ll i=0;i<n-1;i++){
    ll u,v;
    cin>>u>>v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);    
  }
  dfs(0,-1,P(0,0),-1,n+1);
  cout<<"YES"<<endl;
  for(ll i=0;i<n;i++) cout<<pos[i].first<<" "<<pos[i].second<<endl;
  return 0;
}