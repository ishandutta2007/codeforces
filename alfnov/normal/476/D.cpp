#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	cout<<(6*n-1)*k<<endl;
	for(int i=1;i<=n;i++)
		cout<<(6*i-5)*k<<" "<<(6*i-4)*k<<" "<<(6*i-3)*k<<" "<<(6*i-1)*k<<endl;
	return 0;
}