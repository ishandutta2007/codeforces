#include<bits/stdc++.h>
using namespace std;
int v[101010],guessed[101010];
int del[101010];
int l[101010];
int r[101010];
int n;
int guess(int x)
{
	guessed[x]=1;
	cout<<"? "<<x<<endl;
	fflush(stdout);
	cin>>v[x];
	
	
	
	for(int i=1;i<=n;i++)
	{
		int tmp=min(abs(x-i),n-abs(x-i));
		l[i]=max(l[i],v[x]-tmp);
		r[i]=min(r[i],v[x]+tmp);
	}
	
	for(int i=1;i<=n;i++)
	if(l[i]==r[i])
	{
		guessed[i]=1;
		v[i]=l[i];
	}
	
	for(int i=1;i<=n/2;i++)
	if(l[i]>r[i+n/2]||r[i]<l[i+n/2])
	{
		del[i]=1;
		del[i+n/2]=1;
	}
	
	for(int i=1;i<=n/2;i++)
	if(guessed[i]==1&&guessed[i+n/2]==1&&v[i]==v[i+n/2])
	{
		cout<<"! "<<i<<endl;
		fflush(stdout);
		exit(0);
	}
}
int main()
{
	cin>>n;
	
	if(n%4!=0)
	{
		cout<<"! -1"<<endl;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		l[i]=-1000000000;
		r[i]=1000000000;
	}
	guess(1);
	guess(n/2+1);
	int l=2,r=n/2;
	while(l<r)
	{
		int m=(l+r)/2;
		guess(m);
		guess(m+n/2);
		if((v[1]<v[1+n/2])^(v[m]<v[m+n/2]))
			r=m+1;
		else
			l=m-1;
	}
	if(l==r)
	{
		guess(l);
		guess(l+n/2);
	}
	cout<<"! -1"<<endl;
	return 0;
}