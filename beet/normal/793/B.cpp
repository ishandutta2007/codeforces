#include<bits/stdc++.h>
using namespace std;
#define int long long
bool used[4][4][1111][1111];
struct st{
  int t,d,y,x;
  st(){}
  st(int t,int d,int y,int x):t(t),d(d),y(y),x(x){}
};
signed main(){
  int n,m;
  cin>>n>>m;
  string s[n];
  for(int i=0;i<n;i++) cin>>s[i];
  int sy,sx,ty,tx;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i][j]=='S'){
	sy=i;
	sx=j;
      }
      if(s[i][j]=='T'){
	ty=i;
	tx=j;
      }
    }
  }
  int ax[]={1,-1,0,0};
  int ay[]={0,0,1,-1};
  memset(used,0,sizeof(used));
  queue<st> q;
  for(int k=0;k<4;k++){
    q.emplace(0,k,sy,sx);
    used[0][k][sy][sx]=1;
  }
  while(!q.empty()){
    st p=q.front();q.pop();
    int t=p.t,d=p.d,y=p.y,x=p.x;
    //cout<<t<<" "<<d<<" "<<y<<" "<<x<<endl;
    if(y==ty&&x==tx){
      cout<<"YES"<<endl;
      return 0;
    }
    for(int k=0;k<4;k++){
      int ny=y+ay[k],nx=x+ax[k];
      if(ny<0||ny>=n||nx<0||nx>=m) continue;
      if(s[ny][nx]=='*') continue;
      int nt=t+(d!=k),nd=k;
      if(nt>2) continue;
      if(used[nt][nd][ny][nx]) continue;
      used[nt][nd][ny][nx]=1;
      q.emplace(nt,nd,ny,nx);
    }
  }
  cout<<"NO"<<endl;
  return 0;
}