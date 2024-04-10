#include<cstdio>
#include<algorithm>
int a[222222],n,k,c;
int main()
{
	int i,l=1,r;
	scanf("%d%d",&n,&k);c=n;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	for(r=2;r<=n;r++)
		if(a[l]+k>=a[r]&&a[l]<a[r])
			while(a[l]+k>=a[r]&&a[l]<a[r])c--,l++;
		else while(l<r&&a[l]+k<a[r])l++;
	printf("%d\n",c);
}