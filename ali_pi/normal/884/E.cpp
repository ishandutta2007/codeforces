#include<bits/stdc++.h>

using namespace std;

int n,m;
string s,A,B;
int d[1<<15];
int ans;

int get(int v){
  return d[v]==v?v:d[v]=get(d[v]);
}

int mrg(int v,int u){
  v=get(v),u=get(u);
  if(v==u) return 0;
  return d[u]=v,1;
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=m;i--;B+='0');
  for(int i=m*2;i--;d[i]=i);
  for(int x=0,y=1;cin>>s;B=A){
    A="";
    for(int j=0;j<m/4;j++)
      {
 int x=s[j]>='A'?s[j]-'A'+10:s[j]-'0';
 for(int i=8;i;i/=2)
   A+=char('0'+((x&i)>0));
      }
    swap(x,y);
    for(int j=m;j--;)
      if(A[j]-'0'){
 ans++;
 if(B[j]-'0')
   ans-=mrg(2*j+x,2*j+y);
 if(j and A[j-1]-'0')
   ans-=mrg(2*j+x,2*j+x-2);
      }
    for(int j=m;j--;)
      d[2*j+y]=2*j+y;
  }
  cout<<ans;
}