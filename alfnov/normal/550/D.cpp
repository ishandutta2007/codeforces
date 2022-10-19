#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	cin>>k;
	if(k%2==1)
	{
		cout<<"YES"<<endl;
		int n=2*k-1,m=(k-1)/2+(k-1)*(k-1)+k-1;
		int N=2*n,M=2*m+1;
		cout<<N<<" "<<M<<endl;
		cout<<n<<" "<<n+n<<endl;
		for(int i=1;i<=k-1;i++)for(int j=k;j<=2*k-2;j++)
			cout<<i<<" "<<j<<endl;
		for(int i=k;i<=2*k-2;i++)cout<<i<<" "<<n<<endl;
		for(int i=1;i<=k-1;i+=2)cout<<i<<" "<<i+1<<endl;
		for(int i=n+1;i<=n+k-1;i++)for(int j=n+k;j<=n+2*k-2;j++)
			cout<<i<<" "<<j<<endl;
		for(int i=n+k;i<=n+2*k-2;i++)cout<<i<<" "<<2*n<<endl;
		for(int i=n+1;i<=n+k-1;i+=2)cout<<i<<" "<<i+1<<endl; 
	}else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}