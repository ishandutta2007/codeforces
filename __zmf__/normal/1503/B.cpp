//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,cnt1,cnt2,t1,t2,p;
int x[10009],xx[10009],y[10009],yy[10009]; 	
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if((i+j)%2==0)x[++t1]=i,y[t1]=j;
			else xx[++t2]=i,yy[t2]=j;
		}
	for(int i=1;i<=n*n;i++)
	{
		scanf("%d",&p);
		if(p==1)
		{
			if(cnt2<t2)
			{
				cnt2++;printf("2 %d %d\n",xx[cnt2],yy[cnt2]);
			//	cout<<cnt2<<" "<<xx[cnt2]<<" "<<yy[cnt2]<<" "<<t2<<endl;
				fflush(stdout);
			}
			else
			{
				if(p==1)p=3;
				else p=1;
				cnt1++;printf("%d %d %d\n",p,x[cnt1],y[cnt1]);
				fflush(stdout);
			}
		}
		else
		{
			if(cnt1<t1)
			{
				cnt1++;printf("1 %d %d\n",x[cnt1],y[cnt1]);
				fflush(stdout);
			}
			else
			{
				if(p==2)p=3;
				else p=2;
				cnt2++;printf("%d %d %d\n",p,xx[cnt2],yy[cnt2]);
				fflush(stdout);
			}
		}
	}
	return 0;
}