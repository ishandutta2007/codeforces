#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN=1005,MOD=1000000007;

int n,l[MAXN],r[MAXN],a[MAXN];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)cin>>l[i];
	for(int i=1;i<=n;i++)cin>>r[i];
	for(int i=1;i<=n;i++)
		a[i]=n-(l[i]+r[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
			if(a[j]>a[i])--l[i];
		for(int j=i+1;j<=n;j++)
			if(a[j]>a[i])--r[i];
		if(l[i] || r[i])return 0*printf("NO\n");
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}