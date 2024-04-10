#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

int a[25],b[25],t[15],b1,a1;

bool check(int x)
{
	for (int i=x-1;i>=0;i--) if (t[i]) return 1;
	return 0;
}

void pri(int w)
{
	for (int i=b1;i>=w;i--) putchar(b[i]+'0');
	for (int i=b[w-1]-1;i>=0;i--)
		if (t[i]) {putchar(i+'0');t[i]--;break;}
	for (int i=9;i>=0;i--)
		for (int j=1;j<=t[i];j++)
			putchar(i+'0');
}

int main()
{
	LL x,y;
	scanf("%I64d%I64d",&x,&y);
	while (x) a[++a1]=x%10,x/=10,t[a[a1]]++;
	while (y) b[++b1]=y%10,y/=10;
	if (a1<b1)
	{
		for (int i=1;i<=a1;i++)
			for (int j=9;j>=0;j--)
				if (t[j]) {putchar(j+'0');t[j]--;break;}
	}
	else
	{
		int w=1;
		for (int i=b1;i>=1;i--)
			if (t[b[i]]) t[b[i]]--;
			else {w=i+1;break;}
		if (w==1) pri(1);
		else
		{
			while (!check(b[w-1])) t[b[w]]++,w++;
			pri(w);
		}
	}
	return 0;
}