#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
char ss[50];
int n;
int main()
{
	while (true)
	{
		cout<<"next 1 2"<<endl;
		cin>>n;
		for (int i=1;i<=n;i++) cin>>ss;
		cout<<"next 1"<<endl;
		cin>>n;
		for (int i=1;i<=n;i++) cin>>ss;
		if (n==2) break;
	}
	for (int u=1;;u++)
	{
		cout<<"next 0 1 2 3 4 5 6 7 8 9"<<endl;
		cin>>n;
		for (int i=1;i<=n;i++) cin>>ss;
		if (n==1)	
		{
			cout<<"done\n";
			return 0;
		}
	}
	return 0;
}