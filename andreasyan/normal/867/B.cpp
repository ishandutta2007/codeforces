#include <iostream>
#include <set>
using namespace std;
const int N=1000000;

int a[N+3];
int n;
set<int> s;
int main()
{
	cin>>n;
	a[0]=1;
	for(int i=1;i<=10;++i)
	{
		for(int j=0;j<=N;++j)
		{
			if(j+i<=N)
				a[j+i]+=a[j];
		}
		for(int j=1;j<=N;++j)
		{
			if(a[j]==n)
			{
				cout<<j<<' '<<i<<endl;
				for(int k=1;k<=i;++k)
					cout<<k<<' ';
				cout<<endl;
//				system("pause");
				return 0;
			}
		}
	}
	return 0;
}