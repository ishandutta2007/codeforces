#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int a1,b1;
	apple(int a1=0,int b1=0):a1(a1),b1(b1){}
}aan[1000005];
int a[100005];
int t1[100005],t2[100005],dy[100005],vist[100005],p[100005],z[100005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int tot=0;
	for(int i=1;i<=n;i++)if(a[i])
		t1[++tot]=a[i],t2[tot]=i;
	if(!tot)
	{
		puts("0");
		return 0;
	}
	if(t1[tot]!=1)
	{
		puts("-1");
		return 0;
	}
	int r1=1,r2=1;
	for(int i=1;i<=tot;i++)
	{
		vist[i]=1;
		if(t1[i]==2)
		{
			r1=max(i+1,r1);
			for(;r1<=tot&&(vist[r1]||t1[r1]!=1);r1++);
			if(r1==tot+1)
			{
				puts("-1");
				return 0;
			}
			p[i]=r1;
			vist[r1]=1;
		}
		if(t1[i]==3)
		{
			r2=max(i+1,r2);
			for(;r2<=tot&&vist[r2];r2++);
			if(r2==tot+1)
			{
				puts("-1");
				return 0;
			}
			p[i]=r2;
			vist[r2]=1;
		}
	}
	memset(vist,0,sizeof(vist));
	for(int i=1;i<=tot;i++)vist[p[i]]=1;
	int wz=1,ann=0;
	for(int i=1;i<=tot;i++)if(t1[i]!=1)
	{
		if(!z[i])
		{
			if(t1[i]==3)
			{
				aan[++ann]=apple(wz,t2[i]);
				aan[++ann]=apple(wz,t2[p[i]]);
				aan[++ann]=apple(++wz,t2[p[i]]);
				z[p[i]]=wz;
				wz++;
			}else
			{
				aan[++ann]=apple(wz,t2[i]);
				aan[++ann]=apple(wz,t2[p[i]]);
				wz++;
			}
		}else
		{
			if(t1[i]==3)
			{
				aan[++ann]=apple(z[i],t2[p[i]]);
				aan[++ann]=apple(wz,t2[p[i]]);
				z[p[i]]=wz;
				wz++;
			}else
			{
				aan[++ann]=apple(z[i],t2[p[i]]);
			}
		}
	}
	for(int i=1;i<=tot;i++)if(t1[i]==1&&!vist[i])
		aan[++ann]=apple(wz++,t2[i]);
	cout<<ann<<endl;
	for(int i=1;i<=ann;i++)printf("%d %d\n",aan[i].a1,aan[i].b1);
	return 0;
}