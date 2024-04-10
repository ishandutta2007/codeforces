#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,a[100005],mi=1e18,las,tot,r,st;
int main()
{
	cin>>n>>las,r=las;
	for(int i=1;i<=n;i++)
		cin>>a[i],mi=min(mi,a[i]+1);
	while(a[las]+1!=mi){
		a[las]-=mi,tot+=mi;
		las--;
		if(las<1)las=n;
	}
	if(mi==0){
		a[las]+=tot;
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
		exit(0);
	}
	mi--,st=las;
	do{
		a[las]-=mi,tot+=mi;
		las--;
		if(las<1)las=n;
	}while(las!=r);
	a[st]+=tot;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}