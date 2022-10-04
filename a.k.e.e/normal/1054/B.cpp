#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN=100005,MOD=1000000007;

int n,a[MAXN];

int main()
{
	scanf("%d",&n);
	int mx=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>mx+1)return 0*printf("%d\n",i);
		mx=max(mx,a[i]);
	}
	printf("-1\n");
	return 0;
}