#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int n,m,a,b,c;
int main()
{
	int i,j,x;
	cin>>n>>a>>b;
	for(i=0;i<n;++i)
	{
		cin>>x;
		if(x==1)
		{
			if(a)
			{
				--a;
				continue;
			}
			if(b)
			{
				--b;
				++c;
				continue;
			}
			if(c)
			{
				--c;
				continue;
			}
			m++;
		}
		else
		{
			if(b)
			{
				--b;
				continue;
			}
			m+=2;
		}
	}
	cout<<m<<endl;
//	system("pause");
	return 0;
}