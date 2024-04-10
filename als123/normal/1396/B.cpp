#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=105;
int n;
int a[N];
void solve ()
{
	scanf("%d",&n);
	
	for (int u=1;u<=n;u++)scanf("%d",&a[u]);
	if (n==1) {printf("T\n");return ;}
	int lst=-1,op=1;
	while (true)
	{
		int id=-1;
		for (int u=1;u<=n;u++) if (u!=lst&&a[u]!=0)
		{
			if (id==-1) id=u;
			else if (a[u]>a[id]) id=u;
		}
		if (id==-1)
		{
			if (op==1) printf("HL\n");
			else printf("T\n");
			return ;
		 } 
		lst=id;a[id]--;
		op^=1;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--) solve();
	return 0;
}