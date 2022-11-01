#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define mp(x,y) make_pair(x,y)
using namespace std;

typedef long long LL;
typedef pair<int,int> pi;

const int N=2000005;
const int MOD=51123987;

int n,len[N],sz,fail[N],dep[N],last,f[N];
char s[N];
vector<pi> ch[N];

int newnode()
{
	sz++;dep[sz]=len[sz]=0;
	return sz;
}

int find(int x,int c)
{
	for (int i=0;i<ch[x].size();i++)
		if (ch[x][i].first==c) return ch[x][i].second;
	return 0;
}

void extend(int n,int c)
{
	int p=last;
	while (s[n-len[p]-1]!=s[n]) p=fail[p];
	if (!find(p,c))
	{
		int now=newnode(),k=fail[p];len[now]=len[p]+2;
		while (s[n-len[k]-1]!=s[n]) k=fail[k];
		fail[now]=find(k,c);dep[now]=dep[fail[now]]+1;ch[p].push_back(mp(c,now));
	}
	last=find(p,c);
}

int main()
{
	scanf("%d%s",&n,s+1);
	sz=1;fail[0]=1;len[1]=-1;
	for (int i=1;i<=n;i++) extend(i,s[i]-'a'),f[i]=(dep[last]+f[i-1])%MOD;
	reverse(s+1,s+n+1);
	for (int i=0;i<=sz;i++) ch[i].clear();
	sz=-1;newnode();newnode();fail[0]=1;len[1]=-1;last=0;
	int ans=(LL)f[n]*(f[n]-1)/2%MOD;
	for (int i=1;i<=n;i++) extend(i,s[i]-'a'),(ans-=(LL)dep[last]*f[n-i]%MOD)%=MOD;
	printf("%d",(ans+MOD)%MOD);
	return 0;
}