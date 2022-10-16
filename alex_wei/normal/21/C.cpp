#include<bits/stdc++.h>
using namespace std;
long long n,a[100002],f,ans; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]+=a[i-1];
	for(int i=1;i<n;i++){
		if(a[i]*3==a[n]*2)
			ans+=f;
		if(a[i]*3==a[n])
			f++;
	}
	cout<<ans;
	return 0;
}