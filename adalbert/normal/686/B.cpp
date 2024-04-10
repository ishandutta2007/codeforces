#include <iostream>
using namespace std;
long long n,x,h,ans,a[10000];
char c;
int main() 
{
	cin>>n;
	for (int i=1;i<=n;i++)
	cin>>a[i];
	for (int i=1;i<=10009;i++)
	for (int j=1;j<=n-1;j++)
	if (a[j]>a[j+1])
	{
		cout<<j<<' '<<j+1<<'\n';
		h=a[j];
		a[j]=a[j+1];
		a[j+1]=h;
	}
}