#include <iostream>
#include <vector>
using namespace std;
const int N=1000006;

int a[N];
int n;
int z,k;
long long ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]%2==1)
			k++;
		else
			++z;
		ans+=a[i];
	}
	if(ans%2==1)
	{
		cout<<"First"<<endl;
	}
	if(ans%2==0 && k==0)
	{
		cout<<"Second"<<endl;
	}
	if(ans%2==0 && k>0)
	{
		cout<<"First"<<endl;
	}
//	system("pause");
	return 0;
}