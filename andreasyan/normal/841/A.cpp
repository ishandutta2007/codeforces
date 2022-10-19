#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
using namespace std;

char a[102];
int n,k;
int b[30];
bool stg()
{
	for(int i=0;i<26;++i)
	{
		if(b[i])
			return false;
	}
	return true;
}
int main()
{
	cin>>n>>k>>a;
	for(int i=0;i<n;++i)
		b[a[i]-'a']++;
	for(int i=0;i<k;++i)
	{
		if(stg())
		{
			cout<<"YES"<<endl;
//			system("pause");
			return 0;
		}
		for(int j=0;j<26;++j)
		{
			if(b[j])
				--b[j];
		}
	}
	if(stg())
	{
		cout<<"YES"<<endl;
//		system("pause");
		return 0;
	}
	cout<<"NO"<<endl;
//	system("pause");
	return 0;
}