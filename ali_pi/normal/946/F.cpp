#include<bits/stdc++.h>

using namespace std;

int Mod=1e9+7;
int f[101][101][101],len[101],n,m;
char s[101];

int qpow(int x,int y){
  int res=1;
  while (y)
    {
      if (y&1) res=1ll*res*x%Mod;
      x=1ll*x*x%Mod;
      y>>=1;
    }
  return res;
}

int dfs(int x,int l,int r){
  int k;
  if (f[x][l][r]!=-1) return f[x][l][r];
  if (x==1||x==0)
    {
      if (l==r&&s[l]==(char)(x+'0')) return 1;
      return 0;
    }
  int cnt=0;
  cnt+=1ll*dfs(x-1,l,r)*((r==n)?qpow(2,len[x-2]):1)%Mod;cnt%=Mod;
  cnt+=1ll*dfs(x-2,l,r)*((l==1)?qpow(2,len[x-1]):1)%Mod;cnt%=Mod;
  for (k=l;k<r;k++)
    {
      cnt+=1ll*dfs(x-1,l,k)*dfs(x-2,k+1,r)%Mod;
      cnt%=Mod;
    }
  return f[x][l][r]=cnt;
}

int main(){
  int i;
  cin>>n>>m;
  memset(f,-1,sizeof(f));
  len[1]=1;len[0]=1;
  for (i=2;i<=m;i++)
    len[i]=(len[i-1]+len[i-2])%(Mod-1);
  cin>>s+1;
  cout<<dfs(m,1,n);
}