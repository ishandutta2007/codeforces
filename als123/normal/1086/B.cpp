#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
int n,s;
int du[N];
int main()
{
	scanf("%d%d",&n,&s);
	for (int u=1;u<n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		du[x]++;du[y]++;
	}
	int cnt=0;
	for (int u=1;u<=n;u++) if (du[u]==1) cnt++;
	printf("%.8lf\n",(double)s/cnt*2);
	return 0;
}