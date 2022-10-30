#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
const int maxn = 100005;

int fail[maxn];

char s[maxn],t[maxn];
int f[maxn],n,m;
void kmp()
{
	for (int i=1;i<=m;i++)
	{
		int pos=fail[i-1];
		while (pos&&t[pos+1]!=t[i]) pos=fail[pos];
		if (t[pos+1]==t[i]&&i>1) fail[i]=pos+1;
	}
}
void upd(int &x,int y){x<y?x=y:0;}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("anthem.in","r",stdin);
		freopen("anthem.out","w",stdout);
	#endif
	scanf("%s %s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	kmp();
	
	memset(f,-1,sizeof(int)*(m+1));f[0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=m;j>=1;j--)
			upd(f[fail[j]],f[j]);
		if (s[i]=='?') {
			for (int k=m;k>=1;k--) f[k]=f[k-1];
		}
		else {
			for (int k=m;k>=1;k--) f[k]=(s[i]==t[k])?f[k-1]:-1;
		}
		f[m]!=-1?f[m]++:0;
	}
	int ans=0;
	for (int i=0;i<=m;i++) upd(ans,f[i]);
	printf("%d",ans);
	return 0;
}