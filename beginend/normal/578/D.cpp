#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=100005;

int n,m;
char s[N];

int main()
{
	scanf("%d%d%s",&n,&m,s+1);
	LL ans=n*(m-1);
	for (int i=2;i<=n;i++) if (s[i]!=s[i-1]) ans+=n*(m-1);
	int k=1;
	for (int i=2;i<=n;i++)
		if (k>1&&s[i]!=s[i-1]&&s[i]==s[i-2]||k==1&&s[i]!=s[i-1]) k++;
		else ans-=(LL)k*(k-1)/2,k=1+(s[i]!=s[i-1]);
	ans-=(LL)k*(k-1)/2;
	printf("%I64d",ans);
	return 0;
}