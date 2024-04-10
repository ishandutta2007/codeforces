#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
const int N=5002;

int n,m;
int a[N][N];
string s;
int mx[N];
int smx[N];
int main()
{
	cin>>s;
	n=s.size();
	for(int i=1;i<=n;++i)
	{
//		if(i==3)
//		{
//			cout<<" ";
//		}
		for(int j=0;i+j-1<n;++j)
		{
			int l=j;
			int r=i+j-1;
			if(i==1)
			{
				a[l][r]=1;
				++mx[1];
				continue;
			}
			if(i==2)
			{
				if(s[l]==s[r])
				{
					a[l][r]=2;
					++mx[2];
				}
				continue;
			}
			if(s[l]!=s[r] || !a[l+1][r-1])
				continue;
			if(i%2==1)
			{
				a[l][r]=a[l][(l+r)/2-1]+1;
				++mx[a[l][(l+r)/2-1]+1];
			}
			else
			{
				a[l][r]=a[l][(l+r)/2]+1;
				++mx[a[l][(l+r)/2]+1];
			}
		}
	}
	for(int i=n;i>=1;--i)
	{
		smx[i]=smx[i+1]+mx[i];
	}
	for(int i=1;i<=n;++i)
		cout<<smx[i]<<' ';
//	system("pause");
	return 0;
}