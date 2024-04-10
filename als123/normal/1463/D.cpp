#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=400005;
int n;
int b[N]; 
bool in[N];
struct qq
{
	int l,r;
	int s1,s2;
	int c,lzy;
}tr[2][N*2];int num;
void bt (int l,int r,int o)
{
	int now=++num;
	tr[o][now].l=l;tr[o][now].r=r;
	tr[o][now].c=tr[o][now].lzy=0;
	if (l==r) return ;
	int mid=(l+r)>>1;
	tr[o][now].s1=num+1;bt(l,mid,o);
	tr[o][now].s2=num+1;bt(mid+1,r,o);
}
void push_down(int now,int o)
{
	int s1=tr[o][now].s1,s2=tr[o][now].s2,lzy=tr[o][now].lzy;
	tr[o][now].lzy=0;
	tr[o][s1].c+=lzy;tr[o][s1].lzy+=lzy;
	tr[o][s2].c+=lzy;tr[o][s2].lzy+=lzy;
}
void change (int now,int l,int r,int c,int o)
{
//	if (now==1) {printf("%d %d %d\n",l,r,c);}
	if (tr[o][now].l==l&&tr[o][now].r==r)
	{
		tr[o][now].lzy+=c;
		tr[o][now].c+=c;
		return ;
	}
	push_down(now,o);
	int mid=(tr[o][now].l+tr[o][now].r)>>1;
	int s1=tr[o][now].s1,s2=tr[o][now].s2;
	if (r<=mid) change(s1,l,r,c,o);
	else if (l>mid) change(s2,l,r,c,o);
	else {change(s1,l,mid,c,o);change(s2,mid+1,r,c,o);}
	tr[o][now].c=min(tr[o][s1].c,tr[o][s2].c);
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int u=1;u<=2*n;u++) in[u]=false;
		num=0;bt(1,2*n,0);num=0;bt(1,2*n,1);
		for (int u=1;u<=n;u++)
		{
			int x;
			scanf("%d",&x);
			in[x]=true;
		}
		for (int u=1;u<=2*n;u++)
		{
			if (in[u]) 
			{
				change(1,1,u,1,0);
			}
			else 
			{
				change(1,1,u,-1,0);
			}
		}
	//	printf("YES\n");
		int ans=0;int L=1,R=2*n;
		for (int u=0;u<=n;u++)
		{
			//printf("%d %d %d\n",u,tr[1][1].c,tr[0][1].c);
			if (tr[0][1].c>=0&&tr[1][1].c>=0) 
			{
				//printf("%d\n",u);
				ans++;
			}
			if (u!=n)
			{
				while (L<=2*n&&in[L]==false) L++;
				change(1,1,L,-1,0);change(1,L,2*n,1,1);
				while (R>0&&in[R]==true) R--;
				change(1,1,R,1,0);change(1,R,2*n,-1,1);
				L++;R--;
			}
		}
		printf("%d\n",ans);
	} 
	return 0;
}