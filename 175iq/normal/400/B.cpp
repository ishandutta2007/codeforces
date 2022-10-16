#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	bool G=0;
	bool S=0;
	char a;
	int J_G=0 , J_S=0;
	unordered_set<int> M;
	for (int i = 0; i < n; ++i)
	{
		S=0;
		G=0;
		for (int j = 0; j < m; ++j)
		{
			cin>>a;
			if(a=='G')
			{
				if(S)
				{
					cout<<"-1";
					return 0;
				}
				else
				{
					J_G=j;
					G=1;
				}
			}
			else if(a=='S')
			{
				S=1;
				if(!G)
				{
					cout<<"-1";
					return 0;
				}
				else
				{
					J_S=j;
				}
			}
		}
		M.insert(J_S-J_G+1);
	}
	cout<<M.size();
	return 0;
}