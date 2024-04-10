#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int N=55;

int n;
int a[N*2];
bool c[N*2];
int ans=999999999;
int main()
{
	//in
	cin>>n;
	for(int i=0;i<n*2;++i)
		cin>>a[i];
	////
	sort(a,a+n*2);
	for(int i=0;i<n*2;++i)
	{
		for(int j=i+1;j<n*2;++j)
		{
			int yans=0;
			for(int k=0;k<n*2;++k)
				c[k]=false;
			c[i]=true;
			c[j]=true;
			for(int k=0;k<n*2;++k)
			{
				if(c[k])
					continue;
				c[k]=true;
				if(!c[k+1])
				{
					yans+=(a[k+1]-a[k]);
					c[k+1]=true;
					continue;
				}
				if(!c[k+2])
				{
					yans+=(a[k+2]-a[k]);
					c[k+2]=true;
					continue;
				}
				if(!c[k+3])
				{
					yans+=(a[k+3]-a[k]);
					c[k+3]=true;
					continue;
				}
			}
			ans=min(ans,yans);
		}
	}
	cout<<ans<<endl;
	return 0;
}