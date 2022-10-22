#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
char cc[10];
void wer(int x,int y,int z)
{
  cout<<x<<" "<<y<<" "<<z<<endl;
  fflush(stdout);
}
IL bool pd(int h,int t)
{
  if (t==0) return 0;
  wer(1,t,t+1);
  cin>>cc;
  if(cc[0]=='T') return 1;
  while (h<t)
  {
    int mid=(h+t)/2;
    wer(1,mid,mid+1);
    cin>>cc;
    if (cc[0]=='T') return 1;
    else h=mid+1; 
  }
  
  return 0;
}
int main()
{
/*  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);*/
  ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  int h=1,t=n;
  while (h<t)
  {
    int mid=(h+t)/2;
    wer(1,mid,mid+1);
    cin>>cc;
    if (cc[0]=='T') t=mid;
    else h=mid+1;
  }
  if (pd(1,h-1))
  {
    int ans=h;
    t=t-1; h=1;
    while (h<t)
    {
      int mid=(h+t)/2;
      wer(1,mid,mid+1);
      cin>>cc;
      if (cc[0]=='T') t=mid;
      else h=mid+1;
    }
    wer(2,ans,h);
  } else
  {
    int ans=h;
    h=h+1; t=n;
    while (h<t)
    {
      int mid=(h+t)/2;
      wer(1,mid,mid+1);
      cin>>cc;
      if (cc[0]=='T') t=mid;
      else h=mid+1;
    }
    wer(2,ans,h);
  }
  fflush(stdout);
  return 0;
}