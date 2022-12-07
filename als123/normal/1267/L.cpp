#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=1000005;
int n,lim,k;
char a[N];
vector<int> vec[1005];
int cnt[30];
int nn=0;
int L,R;
int get_last ()
{
	while (cnt[R]==0) R--;
	cnt[R]--;
	return R;
}
int get_first ()
{
	while (cnt[L]==0) L++;
	cnt[L]--;
	return L;
}
void solve (int l,int r,int t)
{
	if (t>lim) return ;
	
	for (int u=0;u<=26;u++)
	{
		if (cnt[u]+l-1<k)
		{
		//	printf("A:%d %d %d\n",l,r,t);
			int o=cnt[u];
			for (int i=1;i<=o;i++) 	vec[l+i-1].push_back(u);
			cnt[u]=0;
			for (int i=t+1;i<=lim;i++)
			{
				for (int j=o;j>=1;j--)
				vec[l+j-1].push_back(get_last());
			}
			l=l+o;
		}
		else
		{
			//printf("B:%d %d %d\n",l,r,t);
			for (int i=l;i<=k;i++) 
			{
				vec[i].push_back(u);
				cnt[u]--;
			}
			solve(l,k,t+1);
			l=k+1;
			for (int i=t;i<=lim;i++)
			for (int j=l;j<=r;j++)
			{
				vec[j].push_back(get_first());
			}
			break;
		}
	}
}
int main()
{
	L=0;R=26;
	scanf("%d%d%d",&n,&lim,&k);
	scanf("%s",a+1);int nn=0;
	for (int u=1;u<=n*lim;u++) cnt[a[u]-'a']++;
	solve(1,n,1);
	for (int u=1;u<=n;u++)
	{
		int siz=vec[u].size();
		//printf("%d\n",siz);
		for (int i=0;i<siz;i++)
		printf("%c",vec[u][i]+'a');
		if (u!=n) printf("\n");
	}
	return 0;
}