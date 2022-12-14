#include <bits/stdc++.h>
#define ll unsigned long long
#define p_b push_back
using namespace std;
//vector <ll> tt;
ll st1,st2,stn,st[100001],b[1001],l,r,x,y,n,m,c,k,i,j;
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    st2=1;
    st1=1;
  cin >> x >> y >> l >> r;
 st[0]=l-1;
 //stn=-1;
 for(i=0;i<=64;i++)
 {
     st2=1;
    for(j=0;j<=64;j++)
    {
      if(st2+st1>=l and st1+st2<=r)
      {
          stn++;
          st[stn]=st2+st1;
      }
      if(r/st2<y)break;
      st2*=y;
    }
    if(r/st1<x)break;
    st1*=x;
    //if(st1>=1e18)break;
 }
 stn--;
 stn++;
 stn++;
 st[stn]=r+1;
 sort(st,st+stn+1);
 ll ans=-1e18;
 for(i=1;i<=stn;i++)ans=max(ans,st[i]-st[i-1]);//,cout << ans << endl;
 //for(i=0;i<=stn;i++)cout << st[i] << " "; cout << endl;
 if(ans!=0)ans--;
 cout << ans << endl;
}