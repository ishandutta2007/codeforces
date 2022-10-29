#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int cnt,i;
string s;
int main()
{
	while(1)
	{
		cout<<"next"<<' '<<0<<' '<<1<<endl;
		cout.flush();
		cin>>cnt;
		for(i=1;i<=cnt;++i)
			cin>>s;
		cout<<"next"<<' '<<1<<endl;
		cout.flush();
		cin>>cnt;
		for(i=1;i<=cnt;++i)
			cin>>s;
		if(cnt==2)
			break;
	}
	while(1)
	{
		cout<<"next";
		for(i=0;i<=9;++i)
			cout<<' '<<i;
		cout<<endl;
		cout.flush();
		cin>>cnt;
		for(i=1;i<=cnt;++i)
			cin>>s;
		if(cnt==1)
			break;
	}
	cout<<"done";
	return 0;
}