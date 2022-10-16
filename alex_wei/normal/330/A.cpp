#include<bits/stdc++.h>
using namespace std;
int r,c,a[12],b[12],x,y;
char s[12][12];
int main()
{
	cin>>r>>c;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			cin>>s[i][j];
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			if(s[i][j]=='S')
				a[i]=b[j]=1;
	for(int i=1;i<=r;i++)x+=!a[i];
	for(int i=1;i<=c;i++)y+=!b[i];
	cout<<x*c+y*r-x*y;
	return 0;
}