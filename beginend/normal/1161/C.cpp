#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=55;
const int inf=1e9;

int n,a[N];

int main()
{
	scanf("%d",&n);
	int mn=inf;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),mn=std::min(mn,a[i]);
	int cnt=0;
	for (int i=1;i<=n;i++) if (a[i]==mn) cnt++;
	if (cnt<=n/2) puts("Alice");
	else puts("Bob");
	return 0;
}