#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MAXN=200005;

int n;
char a[MAXN];
int las[MAXN][26];
bool query(int l,int r)
{
	if(l==r)return 1;
	if(a[l]!=a[r])return 1;
	int cnt=0;
	for(int i=0;i<26;++i)
		if(las[r][i]>=l)++cnt;
	return cnt>=3;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int Q,l,r;
	scanf("%s",a+1);n=strlen(a+1);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<26;++j)las[i][j]=las[i-1][j];
		las[i][a[i]-'a']=i;
	}
	readint(Q);
	while(Q--)
	{
		readint(l),readint(r);
		printf(query(l,r)?"Yes\n":"No\n");
	}
	return 0;
}