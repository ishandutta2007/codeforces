#include <bits/stdc++.h>
using namespace std;

int main()
{
	int count=0;
	string name;
	cin>>name;
	unordered_set<char> S;
	for (int i = 0; i < name.size(); ++i)
	{
		if( S.find(name[i])==S.end() )
		{
			S.insert(name[i]);
			count++;
		}
	}
	if(count%2==0)
	{
		cout<<"CHAT WITH HER!"<<endl;
	}
	else
	{
		cout<<"IGNORE HIM!"<<endl;
	}
    return 0;
}