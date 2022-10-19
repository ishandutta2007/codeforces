#include <iostream>
#include <vector>
using namespace std;
const int N=1000000;

int n,A;
vector<int> a[N+5];
int main()
{
	int i,k,j;
	cin>>n>>A;
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		a[k].push_back(i);
	}
	for(i=1;i<=N;++i)
	{
		if(A==i || a[i].empty())
			continue;
		int k=0;
		bool z=true;
		for(j=0;j<a[A].size();++j)
		{
			while(a[i][k]<a[A][j])
			{
				if(k==a[i].size())
					break;
				++k;
				if(k==a[i].size())
					break;
			}
			if(k<(j+1))
			{
				z=false;
				break;
			}
		}
		if(z)
		{
			cout<<i<<endl;
//			system("pause");
			return 0;
		}
	}
	cout<<"-1"<<endl;
//	system("pause");
	return 0;
}