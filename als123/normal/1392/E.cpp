#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=60;
LL bin[60];
LL n,q,sum;
LL a[N][N];
LL lb (LL x)	{return x&(-x);}
int main()
{
	cin>>n;
	bin[1]=1;for (LL u=2;u<=55;u++) bin[u]=bin[u-1]<<1;
	LL tot=0;
	for (LL u=1;u<=n;u++)
	{
		if (u%2==0) 
		{
			for (LL i=1;i<=n;i++) a[u][i]=0;
			continue;
		}
		for (int i=1;i<=n;i++)
		a[u][i]=bin[i+tot*2];
		tot++;
	}
	for (LL u=1;u<=n;u++)
	{
	for (LL i=1;i<=n;i++)	cout<<a[u][i]<<" ";
	cout<<"\n";
	}
	cin>>q;
	while (q--)
	{
		cin>>sum;
		sum-=1;
		cout<<"1 1"<<endl;
		LL xx=1,yy=1;
		while (sum>0)
		{
			LL t=lb(sum);sum-=t;
			//printf("t:%lld\n",t);
			if (a[xx][yy+1]==t) {yy++;cout<<xx<<" "<<yy<<endl;continue;}
			for (LL i=yy;i<=n;i++)
			if (a[xx+2][i]==t)
			{
				cout<<xx+1<<" "<<yy<<endl;
				for (LL j=yy+1;j<=i;j++) cout<<xx+1<<" "<<j<<endl;
				cout<<xx+2<<" "<<i<<endl;
				xx+=2;yy=i;
				break;
			}
		}
		if (xx!=n)
		{
			xx++;cout<<xx<<" "<<yy<<endl;
		}
		for (LL j=yy+1;j<=n;j++) cout<<xx<<" "<<j<<endl;
		
	}
	return 0;
}