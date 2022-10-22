#include <bits/stdc++.h>
using namespace std;
#define IL inline 
#define rint register int
#define rep(i,h,t) for (rint i=h;i<=t;i++)
const int N=2e6;
int f[N][2];
char s1[N],s2[N];
const int INF=1e9;
IL void minn(rint &x,rint y)
{
  if(x>y) x=y;
}
int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  cin>>s1;
  cin>>s2;
  int l=strlen(s1);
  if (s1[0]==s2[0]) f[1][1]=0,f[1][0]=INF;
  else f[1][0]=0; f[1][1]=INF;
  rep(i,1,l)
  {
    f[i][1]=f[i-1][1]+(s1[i-1]!=s2[i-1]);
    if (s1[i-1]==s2[i-2]&&s2[i-1]!=s2[i-2])
      minn(f[i][1],f[i-1][0]+1);
    f[i][0]=f[i-1][1]+(s1[i-1]==s2[i-1]);
    minn(f[i][1],INF);
    minn(f[i][0],INF); 
  }
  cout<<f[l][1]<<endl;
  return 0;
}