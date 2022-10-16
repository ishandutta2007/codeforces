#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	unordered_set <char> S;
	char temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>temp;
			S.insert(temp);
		}
	}

	if( ( S.find('C')!=S.end() ) || ( S.find('M')!=S.end() ) || ( S.find('Y')!=S.end() ) )
	{
		cout<<"#Color";
	}
	else
	{
		cout<<"#Black&White";
	}
	return 0;
}