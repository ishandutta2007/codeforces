#include <bits/stdc++.h>
#define ll long long

using namespace std;
string s1;
ll sc1,sc,a[200001],b[200001],c[200001],sm,t,x,s,mj,j,n,i,k,scc,r,l;
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k ;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<n;i++)
    {
        ll dp=0;
        dp=a[i]/2;
        if(a[i]%2!=0)dp++;
        sc+=dp;
        b[i]=dp;
        sc1+=a[i];
    }
    if(sc>k)
    {
        cout << -1 << endl;
        return 0;
    }
    if(sc1<k)
    {
        cout << -1 << endl;
        return 0;
    }
    k-=sc;
    for(i=0;i<n;i++)
    {
        ll mx=-1e9,mxj=-1;
      for(j=0;j<n;j++)if(b[j]<a[j] and a[j]>mx){mx=a[j];mxj=j;}
      if(mxj==-1)break;
      if(a[mxj]-b[mxj]>k)
      {
          b[mxj]+=k;
          k=0;
          break;
      }
      ll ccc=a[mxj]-b[mxj];
      b[mxj]+=ccc;
      k-=ccc;
    }
    if(k>0)
    {
        cout << -1 << endl;
        return 0;
    }
    for(i=0;i<n;i++)cout << b[i] << " " ;
   return 0;
}