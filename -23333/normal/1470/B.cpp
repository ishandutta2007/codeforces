#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=4e5;
int a[N],ve[N],cnt,b[N],ans[3],f[N*10];
map<int,int> p;
#define ll long long
int main()
{
	ios::sync_with_stdio(false);
	int N1=1e6;
	rep(i,2,N1)
	  if (!f[i])
	  {
	  	ve[++cnt]=i;
	  	for (int j=2;j*i<=1e6;j++) f[i*j]=1;
	  }
	int T;
	cin>>T;
	while(T--)
	{
	int n;
	cin>>n;
	rep(i,1,n) cin>>a[i];
	p.clear();
	rep(i,1,n)
	{
	  b[i]=1;
	  int k=sqrt(a[i]);
      rep(j,1,cnt)
      {
      	int cnt2=0;
        if (ve[j]>k) break;
        while (a[i]%ve[j]==0) a[i]/=ve[j],cnt2++;
        if (cnt2%2==1) b[i]*=ve[j];
      }
   //   cout<<b[i]<<endl;
      b[i]*=a[i];
      p[b[i]]++;
    }
    ans[0]=0; ans[1]=0;
    rep(i,1,n) ans[0]=max(ans[0],p[b[i]]);
	rep(i,1,n)
	{ 
	 // cout<<p[b[i]]<<" ";
	  ans[1]+=(p[b[i]]%2==0||b[i]==1)?p[b[i]]:0;
	  p[b[i]]=0;
    }
	ans[1]=max(ans[1],ans[0]);
    int q;
	cin>>q;
	rep(i,1,q)
	{
		ll x;
		cin>>x;
		if (x==0) cout<<ans[0]<<endl;
		else cout<<ans[1]<<endl;
	}
    }
	return 0;
}