#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,p;
  cin>>n>>p;
  int a[p],b[p],d[p];
  for(int i=0;i<p;i++) cin>>a[i]>>b[i]>>d[i];
  int to[n],from[n],cap[n];
  memset(to,-1,sizeof(to));
  memset(from,-1,sizeof(from));
  memset(cap,-1,sizeof(cap));
  for(int i=0;i<p;i++){
    a[i]--;
    b[i]--;
    to[a[i]]=b[i];
    from[b[i]]=a[i];
    cap[a[i]]=d[i];
  }
  vector<int> tank,tap,diam;
  for(int i=0;i<n;i++){
    if(~to[i]&&!~from[i]){
      int k=i,tmp=cap[i];
      while(~to[k]){
	tmp=min(tmp,cap[k]);
	k=to[k];
      }
      tank.push_back(i);
      tap.push_back(k);
      diam.push_back(tmp);
    }
  }
  cout<<tank.size()<<endl;
  for(int i=0;i<(int)tank.size();i++)
    cout<<tank[i]+1<<" "<<tap[i]+1<<" "<<diam[i]<<endl;
  return 0;
}