#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S ;
	cin>>S ;

	std::vector<int> vec(26,0);

	for (int i = 0; i < S.size(); ++i)
	{
		vec[S[i]-'a']++;
	}

	int k=0;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i]%2!=0)
		{
			k++;
		}
	}

	if(k==0 || k&1)
	{
		cout<<"First";
	}
	else
	{
		cout<<"Second";
	}

	return 0;
}