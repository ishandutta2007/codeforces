#include <bits/stdc++.h>
using namespace std;
const int N=6e5;
char s[N],c[N],n,m;
#define rep(i,h,t) for (int i=h;i<=t;i++)
int main()
{
  ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  cin>>s;
  int len=strlen(s),l=strlen(s);
  rep(i,1,len) c[i]=s[i-1];
  int cnt=l;
  rep(i,1,m-1)
  {
    int now=len+1;
    rep(j,len-l+2,len)
    {
      bool tt=1;
      rep(k,j,len) if (c[k]!=s[k-j]) tt=0;
      if (tt) 
      {
        now=j;
        break;
      }
    }
    rep(i,now,now+l-1)
      c[i]=s[i-now];
    len=now+l-1;
  }
  rep(i,1,len) cout<<c[i];
  return 0;
}