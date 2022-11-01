#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;
const int MOD=1000000007;

int n,a[55],ny[N],jc[N],f[N],ans[60][60];
char str[N];

int get(char c)
{
	if (c>='a'&&c<='z') return c-'a'+1;
	else return c-'A'+26+1;
}

void add(int x)
{
	if (!x) return;
	for (int j=n/2;j>=x;j--)
		(f[j]+=f[j-x])%=MOD;
}

void del(int x)
{
	if (!x) return;
	for (int j=x;j<=n/2;j++)
		(f[j]+=MOD-f[j-x])%=MOD;
}

int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=n;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=n;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	for (int i=1;i<=n;i++) a[get(str[i])]++;
	f[0]=1;
	int w=1;
	for (int i=1;i<=52;i++) add(a[i]),w=(LL)w*ny[a[i]]%MOD;
	int q;scanf("%d",&q);
	for (int i=1;i<52;i++)
		for (int j=i+1;j<=52;j++)
		{
			del(a[i]);del(a[j]);add(a[i]+a[j]);
			ans[i][j]=ans[j][i]=f[n/2];
			add(a[i]);add(a[j]);del(a[i]+a[j]);
		}
	for (int i=1;i<=52;i++) ans[i][i]=f[n/2];;
	while (q--)
	{
		int x,y;scanf("%d%d",&x,&y);
		x=get(str[x]);y=get(str[y]);
		printf("%d\n",(LL)ans[x][y]*jc[n/2]%MOD*jc[n/2]%MOD*w%MOD);
	}
	return 0;
}