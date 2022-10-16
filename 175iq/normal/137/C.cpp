#include <bits/stdc++.h>
using namespace std;

typedef long long int longl;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;

	std::vector<pair<int,int> > vec;

	int x,y;
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>y;
		vec.push_back(make_pair(x,y));
	}

	sort(vec.begin(),vec.end());

	int max=vec[0].second;
	int count=0;
	for (int i = 1; i < vec.size(); ++i)
	{
		if(vec[i].second>=max)
		{
			max=vec[i].second;
		}
		else
		{
			count++;
		}
	}
	cout<<count;
	return 0;
}