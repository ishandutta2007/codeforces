#include<bits/stdc++.h>

const int N=1000005;

int n,a[N*2],len[N*2];
char str[N],str1[N];

void manachar()
{
	if (!n) return;
	for (int i=1;i<=n*2;i++) a[i*2-1]=30,a[i*2]=str[i]-26;
	a[n*2+1]=30;
	int mx=0,pos=0;
	for (int i=1;i<=n*2+1;i++)
	{
		if (i<=mx) len[i]=std::min(mx-i+1,len[pos*2-i]);
		else len[i]=1;
		while (i-len[i]>0&&i+len[i]<=n*2+1&&a[i+len[i]]==a[i-len[i]]) len[i]++;
		if (i+len[i]-1>mx) mx=i+len[i]-1,pos=i;
	}
	int ans=0,l,r;
	for (int i=1;i<=n*2+1;i+=2)
	{
		int p=i/2,w=len[i]-1;
		if (w!=2*std::min(p,n-p)) continue;
		if (w>ans) ans=w,l=p-w/2+1,r=p+w/2;
	}
	for (int i=2;i<=n*2;i+=2)
	{
		int p=i/2,w=len[i]-1;
		if (w!=2*std::min(p,n-p+1)-1) continue;
		if (w>ans) ans=w,l=p-(w-1)/2,r=p+(w-1)/2;
	}
	for (int i=l;i<=r;i++) putchar(str[i]);
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%s",str+1);
		n=strlen(str+1);
		int ans=0;
		for (int i=1;i*2<=n;i++)
			if (str[i]==str[n-i+1]) ans++;
			else break;
		for (int i=1;i<=ans;i++) putchar(str[i]),str1[i]=str[i];
		for (int i=ans+1;i<=n-ans;i++) str[i-ans]=str[i];
		n-=ans*2;
		manachar();
		for (int i=ans;i>=1;i--) putchar(str1[i]);
		puts("");
	}
	return 0;
}