#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

long long ans,m,n,l,r;
vector<bool> x;
void erkuakan()
{
	m=n;
	while(n)
	{
		x.push_back(n%2);
		n/=2;
	}
	n=x.size();
	reverse(x.begin(),x.end());
}
int main()
{
	long long i,j,k;
	cin>>n>>l>>r;
	erkuakan();
	m=2;
	for(i=0;i<n;i++)
	{
		if(x[i])
		{
			for(j=l;j<=r;j++)
			{
				if((j-(m/2))%m==0)
					ans++;
			}
		}
		m*=2;
	}
	cout<<ans<<endl;
//	system("pause");
	return 0;
}