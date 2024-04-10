#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>

const int N=100005;

int n,a[N];
std::map<int,bool> ma;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),ma[a[i]]=1;
	std::sort(a+1,a+n+1);
	int cnt=0;
	for (int i=2;i<=n;i++)
	{
		if (!a[i]&&a[i]==a[i-1]) {puts("cslnb");return 0;}
		if (a[i]==a[i-1]) cnt++;
	}
	if (cnt>1) {puts("cslnb");return 0;}
	for (int i=2;i<=n;i++) if (a[i]==a[i-1]&&ma[a[i]-1]) {puts("cslnb");return 0;}
	int w=0;
	for (int i=1;i<=n;i++) if (a[i]&1) w^=1;
	int k=(n/2)%2;
	if (k==w) puts("cslnb");
	else puts("sjfnb");
	return 0;
}