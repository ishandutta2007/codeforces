#include<iostream>
using namespace std;
int a[101],b[101];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	int mi=10;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(a[i]==b[j])
		mi=min(mi,a[i]);
	if(mi<10)
		cout<<mi<<endl;
	else
	{
		int A=10,B=10;
		for(int i=1;i<=n;i++)
			A=min(A,a[i]);
		for(int i=1;i<=m;i++)
			B=min(B,b[i]);
		cout<<min(A,B)<<max(A,B)<<endl;
	}
	return 0;
}