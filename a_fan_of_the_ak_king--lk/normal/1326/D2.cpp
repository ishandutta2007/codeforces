#include<bits/stdc++.h>
using namespace std;
const int N=2000005,E=262144;
const int M=998244353;
int n,t,i,hw[N<<1],y;
char a[N],s[N<<1],c[N];
void manacher()
{
    int maxright=0,mid;
    for(int i=1;i<n;i++)
    {
        if(i<maxright)
            hw[i]=min(hw[(mid<<1)-i],hw[mid]+mid-i);
        else
            hw[i]=1;
        for(;s[i+hw[i]]==s[i-hw[i]];++hw[i]);
        if(hw[i]+i>maxright)
        {
            maxright=hw[i]+i;
            mid=i;
        }
    }
}
void change()
{
    s[0]=s[1]='#';
    for(int i=0;i<n;i++)
    {
        s[i*2+2]=a[i];
        s[i*2+3]='#';
    }
    n=n*2+2;
    s[n]=0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",c);
		n=strlen(c);
		for(i=0;i<n&&c[i]==c[n-i-1];++i);
		if(i==n)
		{
			printf("%s\n",c);
			continue;
		}
		int p=i;
		int m=n;
		n=0;
		for(i=p;i<m-p;++i)
			a[n++]=c[i];
		int tb=n;
		change();
		manacher();
		int ans1=0,ans2=0;
		for(i=0;i<n;++i)
			if(ans1<hw[i]-1&&i==hw[i])
				ans1=hw[i]-1;
		for(i=n-1;i>=0;--i)
			if(ans2<hw[i]-1&&n-i==hw[i])
				ans2=hw[i]-1;
		if(ans1>ans2)
		{
			for(i=0;i<p;++i)
				printf("%c",c[i]);
			for(i=0;i<ans1;++i)
				printf("%c",a[i]);
			for(i=m-p;i<m;++i)
				printf("%c",c[i]);
		}
		else
		{
			for(i=0;i<p;++i)
				printf("%c",c[i]);
			for(i=tb-ans2;i<tb;++i)
				printf("%c",a[i]);
			for(i=m-p;i<m;++i)
				printf("%c",c[i]);
		}
		printf("\n");
	}
}