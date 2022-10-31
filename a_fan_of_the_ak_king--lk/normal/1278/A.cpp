#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=100005,M=998244353;
int n,m,s[66],s2[66],t;
char p[N],c[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",p);
		memset(s,0,sizeof(s));
		for(ri i=0;p[i];++i)
			s[p[i]-'a']++;
		scanf("%s",c);
		n=strlen(p),m=strlen(c);
		ri i;
		for(i=0;i+n<=m;++i)
		{
			memset(s2,0,sizeof(s2));
			for(ri j=i;j<i+n;++j)
				++s2[c[j]-'a'];
			ri j;
			for(j=0;j<26;++j)
				if(s2[j]!=s[j])
					break;
			if(j==26)
				break;
		}
		if(i+n>m)
			puts("NO");
		else
			puts("YES");
	}
}