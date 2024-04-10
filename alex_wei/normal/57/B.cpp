#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
long long n,m,k,a[N],b[N],c[N],p[N],ans;
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)cin>>a[i]>>b[i]>>c[i];
	for(int i=0;i<k;i++)cin>>p[i];
	for(int i=0;i<m;i++)
		for(int j=0;j<k;j++)
			if(p[j]<=b[i]&&p[j]>=a[i])
				ans+=c[i]+p[j]-a[i];
	cout<<ans; 
	return 0;
}