#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if (a<c) swap(a,c);if (a<b) swap(a,b);
		if (b<c) swap(b,c);
		int t=a-c+b-c;
		if ((t+3)%6==0) {t+=3;c--;} 
		if (t%6!=0) {printf("NO\n");continue;} 
		//printf("%d\n",t);
		t=t/6;c=c-t;
		if (c<0) {printf("NO\n");continue;} 
		if (c%3!=0) {printf("NO\n");continue;} 
		printf("YES\n"); 
	}
	return 0;
}