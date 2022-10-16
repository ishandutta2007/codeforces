#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=1;j<=n/2;j++)
			cout<<i*n/2+j<<" "<<n*n-i*n/2-j+1<<" ";
		cout<<endl;
	}
	return 0;
}