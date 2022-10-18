#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int l,r,n,num[100000],i;
	bool flag=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&num[i]);
	sort(num,num+n);
	for(l=0,r=1;r<n-1 && flag==0;)
	{
		flag |= num[l]+num[r]>num[r+1];
		if(l==r-1) r++;
		else l++;
	}
	printf("%s\n",flag ? "YES" : "NO");
 }