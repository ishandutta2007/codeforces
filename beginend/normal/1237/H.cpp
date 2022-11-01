#include<bits/stdc++.h>

const int N=4005;

int n,a[N],b[N],tar[4]={0,2,1,3},ans[N];
char s1[N],s2[N];

int trans(char c1,char c2)
{
	return (c2-'0')*2+c1-'0';
}

void rev(int *a,int p)
{
	for (int i=1;i<=(p+1)/2;i++)
	{
		int x=a[i],y=a[p-i+1];
		a[i]=tar[y];a[p-i+1]=tar[x];
	}
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%s%s",s1+1,s2+1);
		n=strlen(s1+1);
		for (int i=1;i<=n/2;i++) a[i]=trans(s1[i*2-1],s1[i*2]),b[i]=trans(s2[i*2-1],s2[i*2]);
		int del1=0,del2=0,k1=0,k2=0;
		n/=2;
		for (int i=1;i<=n;i++)
		{
			if (!a[i]) k1++;
			else if (a[i]==1) del1++;
			else if (a[i]==2) del1--;
			else k2++;
			if (!b[i]) k1--;
			else if (b[i]==1) del2--;
			else if (b[i]==2) del2++;
			else k2--;
		}
		int now1=0,now2=0,pos=0,op=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]==1) now1++;
			else if (a[i]==2) now1--;
			if (b[i]==1) now2--;
			else if (b[i]==2) now2++;
			if (del1-now1*2==del2) {pos=i;op=0;break;}
			if (del2-now2*2==del1) {pos=i;op=1;break;}
		}
		if (del1!=del2&&!pos||k1!=0||k2!=0) {puts("-1");continue;}
		int top=0;
		if (!op&&pos) rev(a,pos),ans[++top]=pos*2;
		if (op&&pos) rev(b,pos);
		for (int i=1;i<=n;i++)
		{
			int pos=0;
			for (int j=i;j<=n;j++)
				if (a[j]==tar[b[n-i+1]]) {pos=j;break;}
			if (pos>1) rev(a,pos-1),ans[++top]=pos*2-2;
			rev(a,pos);ans[++top]=pos*2;
		}
		if (op&&pos) ans[++top]=pos*2;
		printf("%d\n",top);
		for (int i=1;i<=top;i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}