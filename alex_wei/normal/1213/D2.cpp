#include<bits/stdc++.h>
using namespace std;
#define ll long long
int k,n,a[200005],p[200005],ans=1e9,avi[200005],g[200005][30];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[a[i]]++;
	for(int i=1;i<=200000;i++)
		if(p[i]){
			avi[i]=p[i];
			int j=i/2,num=1;
			while(j){
				g[j][num]+=p[i],avi[j]+=p[i];
				j/=2;
				num++;
			}
			g[0][num]+=p[i];
			avi[0]+=p[i];
		}
	for(int i=0;i<=200000;i++)
		if(avi[i]>=k){
			int tot=0,pos=0;
			while(p[i]<k){
				while(!g[i][pos])pos++;
				tot+=pos,g[i][pos]--;
				p[i]++;
			}
			ans=min(ans,tot);
		}
	cout<<ans;
    return 0;
}