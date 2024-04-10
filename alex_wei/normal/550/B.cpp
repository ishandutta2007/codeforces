#include<bits/stdc++.h>
using namespace std;
int n,l,r,x,ans,c[16];
int main()
{
	cin>>n>>l>>r>>x;
	for(int i=0;i<n;i++)cin>>c[i];
	for(int i=1;i<(1<<n);i++){
		int sum=0,mi=1e9,mx=0;
		for(int j=0;j<n;j++)
			if((i>>j)&1)
				sum+=c[j],mi=min(mi,c[j]),mx=max(mx,c[j]);
		ans+=l<=sum&&sum<=r&&mx-mi>=x;
	}
	cout<<ans<<endl;
    return 0;
}