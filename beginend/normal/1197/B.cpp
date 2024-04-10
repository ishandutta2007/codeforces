#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,a[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int pos=0;
	for (int i=1;i<=n;i++) if (a[i]==n) {pos=i;break;}
	int l=pos-1,r=pos+1;
	for (int i=n-1;i>=1;i--)
		if (a[l]==i) l--;
		else if (a[r]==i) r++;
		else {puts("NO");return 0;}
	puts("YES");
	return 0;
}