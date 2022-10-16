#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,k;
	scanf("%d%d%d", &n, &m, &k);

	int temp;
	unordered_set<int> S;

	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &temp);
		S.insert(temp);
	}

	int init,final;
	int bone=1;
	if(S.find(1)!=S.end())
	{
		cout<<1;
		return 0;
	}
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%d", &init,&final);

		if(init==bone)
		{
			bone=final;
			if(S.find(bone)!=S.end())
			{	
				cout<<bone;
				return 0;
			}
		}
		else if(final==bone)
		{
			bone=init;
			if(S.find(bone)!=S.end())
			{	
				cout<<bone;
				return 0;
			}		    
		}
	}
	cout<<bone;
	return 0;
}