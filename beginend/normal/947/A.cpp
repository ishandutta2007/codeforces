#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1000005;

int tot,prime[N],low[N];
bool not_prime[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void get_prime(int n)
{
    not_prime[1]=1;
    for (int i=2;i<=n;i++)
    {
        if (!not_prime[i]) prime[++tot]=i,low[i]=i;
        for (int j=1;j<=tot&&i*prime[j]<=n;j++)
        {
            not_prime[i*prime[j]]=1;
            low[i*prime[j]]=prime[j];
            if (i%prime[j]==0) break;
        }
    }
}

int main()
{
	int x2=read();get_prime(x2);
	int tmp=x2,ans=x2;
	while (tmp>1)
	{
		int p2=low[tmp];
		while (tmp%p2==0) tmp/=p2;
		for (int i=0;i<p2;i++)
		{
			int x1=x2-i;
			if (x1<=p2) continue;
			int t=x1;
			while (t>1)
			{
				int p1=low[t];
				while (t%p1==0) t/=p1;
				if (x1-p1+1>p1) ans=min(ans,x1-p1+1);
			}
		}
	}
	printf("%d",ans);
	return 0;
}