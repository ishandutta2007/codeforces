#include <bits/stdc++.h>
using namespace std;

typedef long long int longl;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin>>n>>m;

	queue<int> Q;
	std::vector<bool> mark(20001,0);
	std::vector<int> level(20001,0);

	Q.push(n);
	mark[n]=1;
	level[n]=0;

	int temp,ans;
	while(!Q.empty())
	{
		temp=Q.front();
		Q.pop();
		if(temp==m)
		{
			ans=level[m];
			break;
		}
		if(2*temp<=20000 && 2*temp>0)
		{
			if(!mark[2*temp])
			{	
				Q.push(2*temp);
				mark[2*temp]=1;
				level[2*temp]=level[temp]+1;
			}
		}
		if(temp-1>0 && temp-1<=20000)
		{
			if(!mark[temp-1])
			{
				Q.push(temp-1);
				mark[temp-1]=1;
				level[temp-1]=level[temp]+1;
			}
		}
	}

	cout<<ans;
	return 0;
}