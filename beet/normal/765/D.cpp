#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n;
  cin>>n;
  int f[n];
  for(int i=0;i<n;i++) cin>>f[i];
  map<int,int> ma;
  map<int,vector<int> > G;
  int m;
  for(int i=0;i<n;i++){
    f[i]--;
    m=ma.size();
    if(ma.count(f[i])) m=ma[f[i]];
    ma[f[i]]=m;
    G[m].push_back(i);
  }
  m=ma.size();
  int g[n],h[m];
  memset(h,-1,sizeof(h));
  for(int i=0;i<n;i++) g[i]=ma[f[i]];
  for(int i=0;i<n;i++) h[g[i]]=f[i];
  bool a=1;
  for(int i=0;i<m;i++) a&=g[h[i]]==i;
  for(int i=0;i<n;i++) a&=h[g[i]]==f[i];
  if(a){
    cout<<m<<endl;
    for(int i=0;i<n;i++) cout<<g[i]+1<<" \n"[i==n-1];
    for(int i=0;i<m;i++) cout<<h[i]+1<<" \n"[i==m-1];
  }else cout<<-1<<endl;
  return 0;
}