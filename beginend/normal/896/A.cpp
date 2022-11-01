#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=100005;
const LL inf=(LL)1e18;

LL f[N];
char s1[34]="What are you doing while sending ";
char s2[31]="? Are you busy? Will you send ";
char s3[76]="What are you doing at the end of the world? Are you busy? Will you save us?";

char solve(int n,LL k)
{
	if (f[n]<k) return '.';
	if (!n) return s3[k-1];
	if (k<=34) return k==34?'"':s1[k-1];
	else k-=34;
	if (k<=f[n-1]) return solve(n-1,k);
	else k-=f[n-1];
	if (k<=32) return k==1||k==32?'"':s2[k-2];
	else k-=32;
	if (k<=f[n-1]) return solve(n-1,k);
	else k-=f[n-1];
	return k==1?'"':'?';
}

int main()
{
	f[0]=75;
	for (int i=1;i<=100000;i++) f[i]=min(inf,f[i-1]*2+68);
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int n;LL k;
		scanf("%d%I64d",&n,&k);
		putchar(solve(n,k));
	}
	return 0;
}