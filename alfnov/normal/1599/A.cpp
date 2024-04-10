#include<bits/stdc++.h>
using namespace std;
int a[200005],l[200005],z[200005];
char s[200005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%s",s+1);
	sort(a+1,a+n+1);
	set<pair<int,int>>se;
	long long h1=0,h2=0;
	if(s[n]=='L')
	{
		for(int i=n;i>=1;i-=2)se.insert(make_pair(a[i],0));
		for(int i=n-1;i>=1;i-=2)se.insert(make_pair(a[i],1));
	}else
	{
		for(int i=n;i>=1;i-=2)se.insert(make_pair(a[i],1));
		for(int i=n-1;i>=1;i-=2)se.insert(make_pair(a[i],0));
	}
	for(int i=n-1;i>=0;i--)
	{
		if(i==0||s[i]==s[i+1])
		{
			auto x=*(se.begin());
			l[i+1]=x.first,z[i+1]=x.second;
			se.erase(x);
		}else
		{
			auto it=se.end();
			it--;
			auto x=*it;
			l[i+1]=x.first,z[i+1]=x.second;
			se.erase(x);
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",l[i]);
		if(z[i]==0)printf("L\n");
		else printf("R\n");
	}
	return 0;
}