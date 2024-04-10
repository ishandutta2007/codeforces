#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[100005],b[100005];
ll l,r,num,sl,sr;
int main()
{
	cin>>n>>k,l=1,r=n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n+1;i++){
		if(i<=n&&(i==1||a[i]==a[i-1]))b[i]=b[i-1]+1;
		else{
			b[i]=1;
			for(int j=i-b[i-1];j<i;j++)
				b[j]=b[i-1];
		}
	}
	if(b[n]==n)cout<<0,exit(0);
	while(k>=0&&l+b[l]<=r){
		if(l+b[l]-1<=n-r+b[r]){
			ll sum=l+b[l]-1;
			ll pls=a[l+b[l]]-a[l];
			if(pls*sum<=k)k-=pls*sum,l+=b[l];
			else cout<<a[r]-a[l]-(k/sum),exit(0);
		}
		else{
			ll sum=n-r+b[r];
			ll pls=a[r]-a[r-b[r]];
			if(pls*sum<=k)k-=pls*sum,r-=b[r];
			else cout<<a[r]-a[l]-(k/sum),exit(0);
		}
//		cout<<k<<" "<<l<<" "<<r<<endl;
	}
	cout<<0;
    return 0;
}