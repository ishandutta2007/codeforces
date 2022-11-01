#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1000005;

int n,m,sta[30],end[30],a[N];
char s[N];

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	{
		int x=s[i]-'A';
		if (!sta[x]) sta[x]=i;
		end[x]=i;
	}
	for (int i=0;i<26;i++)
		if (sta[i]) a[sta[i]]++,a[end[i]+1]--;
	int mx=0;
	for (int i=1;i<=n;i++) a[i]+=a[i-1],mx=max(mx,a[i]);
	if (mx>m) puts("YES");
	else puts("NO");
	return 0;
}