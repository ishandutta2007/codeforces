#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool ispal(string a)
{
	string b=a;
	reverse(b.begin(),b.end());
	return a==b;
}
int main()
{
	string x;
	cin>>x;
	int N=x.size();
	
	for(int i=0;i<=N;i++)
	{
		for(char xa='a';xa<='z';xa++)
		{
			string kya;
			for(int j=0;j<i;j++) kya+=x[j];
			kya+=xa;
			for(int j=i;j<N;j++) kya+=x[j];
			if(ispal(kya))
			{
				cout<<kya;
				return 0;
			}
		}
	}
	cout<<"NA";
	return 0;
}