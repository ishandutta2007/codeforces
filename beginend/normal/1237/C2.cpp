#include<bits/stdc++.h>

typedef long long LL;

const int N=50005;

int n,id[N],b[N];
struct data{int x,y,z;}a[N];

bool cmp(int i,int j)
{
	return a[i].x<a[j].x||a[i].x==a[j].x&&a[i].y<a[j].y||a[i].x==a[j].x&&a[i].y==a[j].y&&a[i].z<a[j].z;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),id[i]=i;
	std::sort(id+1,id+n+1,cmp);
	int tmp=0;
	for (int i=1;i<=n;i++)
		if (i<n&&a[id[i]].x==a[id[i+1]].x&&a[id[i]].y==a[id[i+1]].y) printf("%d %d\n",id[i],id[i+1]),i++;
		else b[++tmp]=id[i];
	n=tmp;
	for (int i=1;i<=n;i++) id[i]=b[i];
	for (int i=1;i<=n;i++) std::swap(a[id[i]].x,a[id[i]].z);
	
	std::sort(id+1,id+n+1,cmp);
	tmp=0;
	for (int i=1;i<=n;i++)
		if (i<n&&a[id[i]].x==a[id[i+1]].x&&a[id[i]].y==a[id[i+1]].y) printf("%d %d\n",id[i],id[i+1]),i++;
		else b[++tmp]=id[i];
	n=tmp;
	for (int i=1;i<=n;i++) id[i]=b[i],std::swap(a[id[i]].y,a[id[i]].z);
	
	std::sort(id+1,id+n+1,cmp);
	tmp=0;
	for (int i=1;i<=n;i++)
		if (i<n&&a[id[i]].x==a[id[i+1]].x&&a[id[i]].y==a[id[i+1]].y) printf("%d %d\n",id[i],id[i+1]),i++;
		else b[++tmp]=id[i];
	n=tmp;
	for (int i=1;i<=n;i++) id[i]=b[i];
	
	std::sort(id+1,id+n+1,cmp);
	tmp=0;
	for (int i=1;i<=n;i++)
		if (i<n&&a[id[i]].x==a[id[i+1]].x) printf("%d %d\n",id[i],id[i+1]),i++;
		else b[++tmp]=id[i];
	n=tmp;
	for (int i=1;i<=n;i++) id[i]=b[i],std::swap(a[id[i]].x,a[id[i]].y);
	
	std::sort(id+1,id+n+1,cmp);
	tmp=0;
	for (int i=1;i<=n;i++)
		if (i<n&&a[id[i]].x==a[id[i+1]].x) printf("%d %d\n",id[i],id[i+1]),i++;
		else b[++tmp]=id[i];
	n=tmp;
	for (int i=1;i<=n;i++) id[i]=b[i],std::swap(a[id[i]].x,a[id[i]].z);
	
	std::sort(id+1,id+n+1,cmp);
	tmp=0;
	for (int i=1;i<=n;i++)
		if (i<n&&a[id[i]].x==a[id[i+1]].x) printf("%d %d\n",id[i],id[i+1]),i++;
		else b[++tmp]=id[i];
	n=tmp;
	for (int i=1;i<=n;i++) id[i]=b[i];
	
	std::sort(id+1,id+n+1,cmp);
	for (int i=1;i<=n;i+=2) printf("%d %d\n",id[i],id[i+1]);
	return 0;
}