#include<bits/stdc++.h>
using namespace std;
int n,k,h,p[200006],ans=1,mi=1e9,mx,cnt;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>h,p[h]++,mi=min(mi,h),mx=max(mx,h);
	if(mx==mi)cout<<0,exit(0);
	while(mx>mi){
		p[mx]+=p[mx+1];
		if(cnt+p[mx]>k)ans++,cnt=p[mx];
		else cnt+=p[mx];
		mx--;
	}
	cout<<ans;
	return 0;
}