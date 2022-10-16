#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s1 ;
	getline(cin,s1) ;
	int count1=0,count2=0;
	locale loc;
	for (int i = 0; i < s1.size(); ++i)
	{
		if(s1[i]==tolower((s1[i]),loc))
		{
			count1++;
		}
		else
		{
			count2++;
		}
	}
	if(count1>count2)
	{
		transform(s1.begin(),s1.end(),s1.begin(),::tolower);
	}
	else if(count2>count1)
	{
		transform(s1.begin(),s1.end(),s1.begin(),::toupper);
	}
	else
	{
		transform(s1.begin(),s1.end(),s1.begin(),::tolower);
	}
	cout<<s1;
	return 0;
}