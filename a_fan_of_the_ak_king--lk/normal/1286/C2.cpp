#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=100005,M=1000000007;
int n,p,i,j,k;
struct str{
	int a[26];
}tmp;
vector<str> a[105],b[105];
char ans[105],c[105];
int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	int ttmp=n;
	n=(n+1)/2;
	if(n==1)
	{
		printf("? 1 1\n");
		fflush(stdout);
		scanf("%s",c);
		ans[1]=c[0];
	}
	else
	{
	printf("? %d %d\n",1,n);
	fflush(stdout);
	for(i=1;i<=n*(n+1)/2;++i)
	{
		scanf("%s",c);
		if(n==1)
		{
			printf("! %s",c);
			fflush(stdout);
			return 0;
		}
		memset(tmp.a,0,sizeof(tmp));
		for(j=0;c[j];++j)
			tmp.a[c[j]-'a']++;
		a[j].push_back(tmp);
	}
	printf("? %d %d\n",1,n-1);
	fflush(stdout);
	for(i=1;i<=n*(n-1)/2;++i)
	{
		scanf("%s",c);
		memset(tmp.a,0,sizeof(tmp));
		for(j=0;c[j];++j)
			tmp.a[c[j]-'a']++;
		b[j].push_back(tmp);
	}
	for(i=1;i<=n;++i)
	{
		memset(tmp.a,0,sizeof(tmp));
		for(auto j:a[i])
			for(k=0;k<26;++k)
				tmp.a[k]+=j.a[k];
		for(auto j:b[i])
			for(k=0;k<26;++k)
				tmp.a[k]-=j.a[k];
		for(j=n;j>n-i+1;--j)
			--tmp.a[ans[j]-'a'];
		for(j=0;j<26;++j)
			if(tmp.a[j])
				break;
		ans[n-i+1]=j+'a';
	}
	}
	n=ttmp;
	if(n==1)
	{
		printf("! %s",ans+1);
		fflush(stdout);
		return 0;
	}
	printf("? %d %d\n",1,n);
	for(i=1;i<=n;++i)
		b[i].clear();
	fflush(stdout);
	for(i=1;i<=n*(n+1)/2;++i)
	{
		scanf("%s",c);
		memset(tmp.a,0,sizeof(tmp));
		for(j=0;c[j];++j)
			tmp.a[c[j]-'a']++;
		b[j].push_back(tmp);
	}
	for(i=2;i<=n-(n+1)/2;++i)
	{
		memset(tmp.a,0,sizeof(tmp.a));
		for(auto j:b[i])
			for(k=0;k<26;++k)
				tmp.a[k]+=j.a[k];
		for(j=1;j<=(n+1)/2;++j)
			tmp.a[ans[j]-'a']-=min(j,i);
		for(j=n;j>n-i+2;--j)
			tmp.a[ans[j]-'a']-=n-j+1;
		for(j=0;j<26;++j)
			if(tmp.a[j]%i!=0)
				break;
		ans[n-i+2]=j+'a';
	}
	tmp=b[n][0];
	for(i=1;i<=n;++i)
		if(i!=(n+1)/2+1)
			tmp.a[ans[i]-'a']--;
	for(j=0;j<26;++j)
		if(tmp.a[j]!=0)
			break;
	ans[(n+1)/2+1]=j+'a';
	printf("! %s",ans+1);
	fflush(stdout);
}