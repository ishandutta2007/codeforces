#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	std::vector<int> vecy(2*n+1);
	for (int i = 0; i < 2*n+1; ++i)
	{
		cin>>vecy[i];
	}
	for (int i = 1,j=1; (i <= 2*n && j<=k); i+=2)
	{
		if(vecy[i - 1]+1 < vecy[i] && vecy[i] > vecy[i + 1]+1)
		{
			j++;
			vecy[i]--;
		}
	}
	for (int i = 0; i < 2*n+1; ++i)
	{
		cout<<vecy[i]<<" ";
	}
	return 0;
}