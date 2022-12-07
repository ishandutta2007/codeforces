#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1e9
using namespace std;

const int maxn = 210;

int n,m,k,ev;
struct node
{
	int num,last,i;
}a[maxn];
inline bool cmp(const node x,const node y){return x.num==y.num?x.last<y.last:x.num>y.num;}

int ans[maxn];

int main()
{
	scanf("%d%d%d%d",&n,&k,&m,&ev);
	for(int i=1;i<=n;i++) a[i].i=i;
	for(int i=1;i<=ev;i++)
	{
		int x; scanf("%d",&x);
		a[x].num++; a[x].last=i;
	}sort(a+1,a+n+1,cmp);
	
	for(int i=1;i<=n;i++)
	{
		if(i<=k&&a[i].num>0)
		{
			int temp=m-ev;
			int nowi=i;
			for(int j=i+1;j<=n;j++)
			{
				if(temp<a[i].num+1-a[j].num) break;
				temp-=a[i].num+1-a[j].num;
				nowi++;
			}
			if(nowi<=k) { ans[a[i].i]=1; continue; }
		}
		if(!a[i].num||i>k)
		{
			if(ev==m) { ans[a[i].i]=3; continue; }
			if(a[i].num+m-ev<=a[k].num) { ans[a[i].i]=3; continue; }
		}
		ans[a[i].i]=2;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	
	return 0;
}