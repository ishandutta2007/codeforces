#include<bits/stdc++.h>
using namespace std;
long long n,a[100002],ans,k;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=-1;
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]){
			k++;
			if(k==2||k==1&&a[i]-a[i-1]<2)
				cout<<"cslnb",exit(0);
		}
	}
	for(int i=1;i<=n;i++){
		long long j=a[i-1]+1;
		if(a[i]>j)
			ans+=a[i]-j,a[i]=j;
	}
	if(ans%2)cout<<"sjfnb";
	else cout<<"cslnb";
    return 0;
}