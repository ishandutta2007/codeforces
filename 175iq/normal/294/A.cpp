#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	std::vector<int> a(n+1,0);
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}
	int m;
	cin>>m;
	std::vector<int> vecx;
	std::vector<int> vecy;
	int alpha,beta;
	for (int i = 0; i < m; ++i)
	{
		cin>>alpha>>beta;
		vecx.push_back(alpha);
		vecy.push_back(beta);
	}
	for (int i = 0; i < m; ++i)
	{
		if(vecx[i]==1)
		{
			a[2]+=(a[1]-vecy[i]);
			a[1]=0;
		}
		else if(vecx[i]==n)
		{
			a[n-1]+=(vecy[i]-1);
			a[n]=0;
		}
		else
		{
			a[vecx[i]-1]+=(vecy[i]-1);
			a[vecx[i]+1]+=(a[vecx[i]]-vecy[i]);
			a[vecx[i]]=0;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}