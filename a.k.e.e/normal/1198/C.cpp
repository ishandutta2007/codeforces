#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=500005;

int n,m,u[MAXN],v[MAXN];
bool cho[MAXN],sel[MAXN];
void solve()
{
	int ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		if(!cho[u[i]] && !cho[v[i]])
			{sel[i]=1;++ans;cho[u[i]]=cho[v[i]]=1;}
	}
	if(ans>=n)
	{
		printf("Matching\n");
		int cnt=0;
		for(int i=1;i<=m && cnt<n;i++)
			if(sel[i]){printf("%d ",i);++cnt;}
		printf("\n");
	}
	else
	{
		printf("IndSet\n");
		int cnt=0;
		for(int i=1;i<=3*n && cnt<n;i++)
			if(!cho[i]){printf("%d ",i);++cnt;}
		printf("\n");
	}
	for(int i=1;i<=3*n;i++)cho[i]=0;
	for(int i=1;i<=m;i++)sel[i]=0;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}