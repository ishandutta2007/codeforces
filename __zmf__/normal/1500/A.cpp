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
const int N=200009,M=5000000;
int n;
struct point
{
	int val,pos;
}a[N];
inline bool cmp(point xxx,point yyy)
{
	return xxx.val<yyy.val;
}
int k[M+9];
inline void solve2()
{
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++)
	{
		if(k[a[i+1].val-a[i].val]>=1)
		{
			puts("YES");
			int x=a[i+1].pos,y=a[i].pos;
			for(int j=1;j<=i-2;j++)
				if(a[i+1].val-a[i].val==a[j+1].val-a[j].val)
				{
					cout<<x<<" "<<a[j].pos<<" "<<a[j+1].pos<<" "<<y;
					return ;
				}
		}
		if(i>=2)k[a[i].val-a[i-1].val]++;
	}
	return ;
}
inline void solve1()
{
	sort(a+1,a+n+1,cmp);
	int flag=0,x,y;
	for(int i=1;i<n;i++)
		if(a[i+1].val==a[i].val&&a[i].pos!=y)
		{
			if(flag==1)
			{
				puts("YES");
				cout<<x<<" "<<a[i].pos<<" "<<y<<" "<<a[i+1].pos;
				return ;
			}
			x=a[i].pos,y=a[i+1].pos;flag++;
		}
	for(int i=1;i<=n;i++)
		if(a[i].val!=a[i-1].val)
				for(int j=i+1;j<=n;j++)
					if(a[j].val!=a[j-1].val)
					{
						k[a[j].val+a[i].val]++;
					}
	for(int i=1;i<n;i++)
		if(a[i+1].val==a[i].val)
		{
			k[2*a[i].val]++;
			break;
		}
	for(int pp=0;pp<=M;pp++)
		if(k[pp]>1)
		{
			puts("YES");
			int flag=0;
			for(int i=1;i<=n;i++)
				if(a[i].val!=a[i-1].val)
					for(int j=i+1;j<=n;j++)
						if(a[j].val!=a[j-1].val&&a[j].val+a[i].val==pp&&flag<=1)
						{
							flag++;cout<<a[i].pos<<" "<<a[j].pos<<" ";
						}
			for(int i=1;i<n;i++)
				if(a[i].val==a[i+1].val&&pp==a[i].val*2&&flag<=1)
				{
					flag++;cout<<a[i].pos<<" "<<a[i+1].pos<<" ";
				}
			return ;
		}
	puts("NO");
	return ;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i].val=read(),a[i].pos=i;
	if(n<=5000)solve1();
	else solve2();
	return 0;
}