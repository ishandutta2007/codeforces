#include <bits/stdc++.h>
using namespace std;

typedef long long int longl;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,x;
	unordered_set<int> S;
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		cin>>x;
		S.insert(x);
	}	

	bool mark=0;
	int count=0;
	vector<int> ans;
	for (int i = 1; i <=pow(10,9) ; ++i)
	{
		if((m-i)<0)
		{
			break;
		}
		if(S.find(i)==S.end())
		{
			ans.push_back(i);
			count++;
			m-=i;
		}
	}
	cout<<count<<endl;
	for (int i = 0; i < count; ++i)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}