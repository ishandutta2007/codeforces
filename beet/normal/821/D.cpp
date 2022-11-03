#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
signed main(){
  int n,m,k;
  cin>>n>>m>>k;
  int r[k],c[k];
  for(int i=0;i<k;i++) cin>>r[i]>>c[i];
  int s=-1;
  for(int i=0;i<k;i++){
    if(r[i]==1&&c[i]==1) s=i;
  }
  deque<P> q;
  int di[k];
  memset(di,-1,sizeof(di));
  int ans=-1;
  q.push_front(P(s,0));
  while(!q.empty()){
    P p=q.front();q.pop_front();
    int v=p.first,d=p.second;
    if(~di[v]) continue;
    di[v]=d;
    //cout<<d<<":"<<r[v]<<" "<<c[v]<<endl;
    if(abs(r[v]-n)<=1||abs(c[v]-m)<=1){
      if(ans<0||d+1<ans) ans=d+1;
    }
    if(r[v]==n&&c[v]==m){
      if(ans<0||d<ans) ans=d;
    }
    for(int i=0;i<k;i++){
      //cout<<i<<" "<<di[i]<<"+"<<abs(r[i]-r[v])<<" "<<abs(c[i]-c[v])<<endl;
      if(~di[i]) continue;
      //cout<<i<<"+"<<abs(r[i]-r[v])<<" "<<abs(c[i]-c[v])<<endl;
      if(abs(r[i]-r[v])+abs(c[i]-c[v])==1){
	q.push_front(P(i,d));
      }else{
	if(((c[i]!=c[v]&&abs(r[i]-r[v])<=2))||
	   (r[i]!=r[v]&&abs(c[i]-c[v])<=2)){
	  q.push_back(P(i,d+1));
	}
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}