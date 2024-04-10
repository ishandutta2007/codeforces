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
const int MAXN=100005;

int n;
char s[MAXN];
ll cur[26];
ll ans[26][26];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<26;++j)
			ans[j][s[i]-'a']+=cur[j];
		cur[s[i]-'a']++;
	}
	ll res=0;
	for(int i=0;i<26;++i)
	{
		for(int j=0;j<26;++j)
			chkmax(res,ans[i][j]);
		chkmax(res,cur[i]);
	}
	cout<<res<<endl;
	return 0;
}