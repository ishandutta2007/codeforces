#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;
const int MOD=1000000007;

int n,q,bin[N],bas[N][25],cnt[N];

bool check(int l,int x)
{
	for (int i=20;i>=0;i--)
		if (x&bin[i])
		{
			if (!bas[l][i]) return 0;
			x^=bas[l][i];
		}
	return x==0;
}

int main()
{
	scanf("%d%d",&n,&q);
	bin[0]=1;
	for (int i=1;i<=max(n,20);i++) bin[i]=bin[i-1]*2%MOD;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<20;j++) bas[i][j]=bas[i-1][j];
		cnt[i]=cnt[i-1];
		int x;scanf("%d",&x);
		for (int j=20;j>=0;j--)
			if (x&bin[j])
			{
				if (!bas[i][j]) {bas[i][j]=x;cnt[i]++;break;}
				else x^=bas[i][j];
			}
	}
	while (q--)
	{
		int l,x;scanf("%d%d",&l,&x);
		if (!check(l,x)) puts("0");
		else printf("%d\n",bin[l-cnt[l]]);
	}
	return 0;
}