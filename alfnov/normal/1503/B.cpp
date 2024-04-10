#include<bits/stdc++.h>
using namespace std;
int xt1[100005],yt1[100005],xt2[100005],yt2[100005];
int main()
{
	int n;
	cin>>n;
	int a1=0,a2=0,b1=0,b2=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		if((i+j)&1)xt1[++a1]=i,yt1[a1]=j;
		else xt2[++a2]=i,yt2[a2]=j;
	}
	int a;
	for(int i=1;i<=n*n;i++)
	{
		cin>>a;
		if(a!=3)
		{
			if(a1!=b1)b1++,cout<<3<<" "<<xt1[b1]<<" "<<yt1[b1]<<endl;
			else b2++,cout<<3-a<<" "<<xt2[b2]<<" "<<yt2[b2]<<endl;
		}else
		{
			if(a2!=b2)b2++,cout<<1<<" "<<xt2[b2]<<" "<<yt2[b2]<<endl;
			else b1++,cout<<2<<" "<<xt1[b1]<<" "<<yt1[b1]<<endl;
		}
	}
	return 0;
}