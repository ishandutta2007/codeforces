#include<bits/stdc++.h>
using namespace std;
int n,k,a[1002],d,num[1002],ans; 
int main()
{
	cin>>n>>k,d=(n+1)/2;
	for(int i=1;i<=n;i++)
		cin>>a[i],num[a[i]]++;
	for(int i=1;i<=k;i++)
		while(num[i]>1&&d)
			ans+=2,num[i]-=2,d--;
	for(int i=1;i<=k;i++)
		while(num[i]&&d)
			ans++,num[i]--,d--;
	cout<<ans;
    return 0;
}