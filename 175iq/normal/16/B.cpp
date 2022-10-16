#include <bits/stdc++.h>
using namespace std;


bool sortbysec(const pair<int,int>& a, const pair<int,int>& b)
{
	return (a.second>b.second);
}

int main()
{
	int n,m;
	cin>>n>>m;
	std::vector<pair<int,int> > A;
	pair<int,int> temp;
	
	for (int i = 0; i < m; ++i)
	{
		cin>>temp.first>>temp.second;
		A.push_back(make_pair(temp.first,temp.second));
	}

	sort(A.begin(),A.end(),sortbysec);
	long long int ans=0;


	int i=0;
	while(n)
	{	
		if(n>=A[i].first)
		{
			ans+= (A[i].first)*(A[i].second);
			n-=A[i].first;
			i++;
			if(i==m)
			{
			    break;
			}
		}
		else
		{
			ans+=n*A[i].second;
			n=0;
		}
	}
	cout<<ans;
}