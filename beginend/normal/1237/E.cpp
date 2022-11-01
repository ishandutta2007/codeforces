#include<bits/stdc++.h>

const int N=1000005;

int n,lef[N],rig[N],a[N],tim;

void dfs(int x,int c)
{
	if (lef[x]) dfs(lef[x],c^1);
	a[++tim]=c;
	if (rig[x]) dfs(rig[x],c);
}

int main()
{
	scanf("%d",&n);
	if (n==1) {puts("1");return 0;}
	int k=1;
	while (k*4-1<=n) k<<=1;
	if (n==k*2-1) {puts("0");return 0;}
	for (int i=1;i<k;i++) lef[i]=i*2,rig[i]=i*2+1;
	dfs(1,1);
	int s=0;
	for (int i=1;i<tim;i++) if (a[i]==a[i+1]) s++;
	int ret=n-(k*2-1);
	if (ret==s||ret==s+1) puts("1");
	else puts("0");
	return 0;
}