#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 1001
LL n,w,b,x,cnt,f[10*N],c[N],v[N];
int main()
{
	cin>>n>>w>>b>>x;
	for(LL i=1;i<=n;i++)
    	cin>>c[i];
	for(LL i=1;i<=n;i++)
	    cin>>v[i];
	f[0]=w;
	for(LL i=1;i<=n;i++) {
	  for(LL j=cnt;j>=0;j--)
	    for(LL k=0;f[j]>=k*v[i] && k<=c[i];k++)
	      f[j+k]=max(f[j+k],f[j]-k*v[i]),cnt=max(cnt,j+k);
	  for(LL j=0;j<=cnt;j++)
	      f[j]=min(f[j]+x,w+b*j);
	  }
	cout<<cnt;
}