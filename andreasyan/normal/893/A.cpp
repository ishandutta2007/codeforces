#include <iostream>
using namespace std;

int n;
int a[200];
int main()
{
	int x,y,z;
	x=1;
	y=2;
	z=3;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	for(int i=0;i<n;++i)
	{
		int k;
		k=a[i];
		if(k==z)
		{
			cout<<"NO"<<endl;
//			system("pause");
			return 0;
		}
		else if(k==x)
		{
			swap(y,z);
		}
		else
		{
			swap(x,z);
		}
	}
	cout<<"YES"<<endl;
//	system("pause");
	return 0;
}