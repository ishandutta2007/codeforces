#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=15;
int T;
int a[N],nn;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		if (n<9) printf("0\n");
		else if (n%10==9) 
		{
			printf("%d\n",n/10+1);
		}
		else
		{
			int t=n%10;
			n=n-t-1;
			printf("%d\n",n/10+1);
		}
	}
	return 0;
}