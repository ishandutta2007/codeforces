#include <iostream>
#include <set>
#include <vector>
#include <stdlib.h>

using namespace std;

int targ;
int n,m;
vector < pair < int, int > > ans;
bool used[105];
set < long long > sqs;
bool nd = false;

void rec(int x)
{
	if(ans.size() == targ)
	{
		nd= 1;
		return;
	}
	for(int j=0;j<=n;j++)
	{
		if(used[j])
			continue;
		bool good = true;
		for(int k=0;k<ans.size();k++)
		{
			long dx = abs(ans[k].first-x);
			long dy = abs(ans[k].second-j);
			if(sqs.count(dx*dx+dy*dy))
				good = false;
		}

		if(good)
		{
			ans.push_back(make_pair(x,j));
			used[j] = 1;
			rec(x+1);
			if(nd)
				return;
			used[j] = 0;
			ans.erase(ans.begin()+ans.size()-1);
		}
	}
}

int main()
{
	

	cin >> m >> n;




	
	

	for(int i=0;i<150;i++)
	{
		sqs.insert(i*i);
	}
	
	if(n==1&&m==1)
	{
		cout << 2 << endl;
		cout << 0 << ' ' << 1 << endl;
		cout << 1 << ' ' << 0 << endl;
	}
	else
	{
		
		for(int i=0;i<105;i++)
			used[i] = 0;
		bool swp = 0;
		if(n >= m)
		{

		}
		else
		{
			swap(n,m);
			swp = 1;
		}
			cout << m+1 << endl;
			targ = m+1;
			

			used[1] = 1;

			ans.push_back(make_pair(0,1));

			rec(1);

			for(int i=0;i<ans.size();i++)
			{
				if(!swp)
					cout << ans[i].first << ' ' << ans[i].second << endl;
				else
					cout << ans[i].second << ' ' << ans[i].first << endl;
			}
				

	}
	



	return 0;
}