#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n,i,j,k;
	char a[1001],b[1001];
	scanf("%d%s%s",&n,a,b);
	sort(a,a+n),sort(b,b+n);
	for(i=0,j=0;i<n;i++) if(b[i]>=a[j]) j++;
	for(i=n-1,k=n-1;i>=0;i--) if(b[k]>a[i]) k--;
	printf("%d\n%d\n",n-j,n-k-1);
}