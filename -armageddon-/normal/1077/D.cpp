#include <bits/stdc++.h>
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define all(A) A.begin(),A.end()
const int inf=1018181818;
using namespace std;
int n,k;
int a[200005];
int s[200005];

bool check(int x)
{
	ll res=0;
	for(int i=1;i<200001;i++)
	{
		res+=s[i]/x;
	}
	return (res>=k);
}

void print(int x)
{
//	cout<<x<<endl;
	int remain=k;
	for(int i=1;i<=200000;i++)
	{
		while(s[i]>=x && remain)
		{
			remain--;
			s[i]-=x;
			printf("%d ",i);
		}
		if(!remain) break;
	}
}

int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		s[a[i]]++;
	}
	int l=1,r=200000,m,ans=0;
	while(l<=r)
	{
		m=(l+r)>>1;
		if(check(m))
		{
			l=m+1;
			ans=m;
		}
		else
		{
			r=m-1;
		}
	}
	print(ans);
	return 0;
}