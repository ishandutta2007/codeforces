#include<bits/stdc++.h>

const int N=100005;

int a[5],b[5],ans[N],n;

int work(int x)
{
	if (x==0)
	{
		if (b[1]) return b[1]--,1;
		else return -1;
	}
	else if (x==1)
	{
		if (b[0]) return b[0]--,0;
		else if (b[2]) return b[2]--,2;
		else return -1;
	}
	else if (x==2)
	{
		if (b[3]) return b[3]--,3;
		else if (b[1]) return b[1]--,1;
		else return -1;
	}
	else
	{
		if (b[2]) return b[2]--,2;
		else return -1;
	}
}

bool check(int x)
{
	for (int i=0;i<4;i++) b[i]=a[i];
	b[x]--;
	int tot=0;
	ans[++tot]=x;
	for (int i=1;i<n;i++)
	{
		x=work(x);
		if (x==-1) return 0;
		ans[++tot]=x;
	}
	puts("YES");
	for (int i=1;i<=tot;i++) printf("%d ",ans[i]);
	return 1;
}

int main()
{
	for (int i=0;i<4;i++) scanf("%d",&a[i]),n+=a[i];
	for (int i=0;i<4;i++) if (a[i]&&check(i)) return 0;
	puts("NO");
	return 0;
}