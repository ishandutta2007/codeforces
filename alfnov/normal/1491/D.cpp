#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(u>v)
		{
			puts("NO");
			continue;
		}
		if(u==v)
		{
			puts("YES");
			continue;
		}
		int t1=0,t2=0;
		for(int i=1;i<=100;i++)a[i]=b[i]=0;
		while(u)a[++t1]=u&1,u>>=1;
		while(v)b[++t2]=v&1,v>>=1;
		t1=t2=max(t1,t2);
		reverse(a+1,a+t1+1);
		reverse(b+1,b+t2+1);
		int wz=0,bb=t1+1,flag=1;
		for(int i=t1;i>=1;i--)if(a[i]==0&&b[i]==1)wz=i;
		for(int i=t1;i>=wz;i--)if(b[i])
		{
			bb--;
			while(bb>wz&&!a[bb])bb--;
			if(bb<=wz||bb<i)
			{
				flag=0;
				break;
			}
		}
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;
}