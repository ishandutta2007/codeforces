#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

typedef long long LL;

const int N=100005;
const double eps=1e-10;

int n,a[N],b[N],c[N];
char str[25];

int main()
{
	scanf("%d",&n);
	LL tot=0;
	int t1=0,t2=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",str);
		int L=strlen(str);
		int x=0,f=1;double y=0;
		for (int j=0;j<L;j++)
			if (str[j]!='.')
			{
				if (str[j]!='-') x=x*10+str[j]-'0';
				else f=-1;
			}
			else break;
		x=f*x;
		for (int j=L-1;j>=0;j--)
			if (str[j]!='.') y=(y+str[j]-'0')*0.1;
			else break;
		tot+=x;c[i]=x;
		if (fabs(y)<eps) continue;
		if (str[0]=='-') a[++t1]=i;
		else b[++t2]=i;
	}
	while (tot<0) c[b[t2--]]++,tot++;
	while (tot>0) c[a[t1--]]--,tot--;
	for (int i=1;i<=n;i++) printf("%d\n",c[i]);
	return 0;
}