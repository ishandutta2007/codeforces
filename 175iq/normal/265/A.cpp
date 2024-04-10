#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s,t;
	cin>>s;
	cin>>t;
	int count=1;
	int j=0;
	for (int i = 0; i < t.size(); ++i)
	{
		if(t[i]==s[j])
		{
			count++;
			j++;
		}
	}
	cout<<count;
	return 0;
}