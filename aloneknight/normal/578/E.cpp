#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui long long
#define ull unsigned long long
#define db long double
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline int rd()
{
	int x=0;char c=gc();while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10+c-48,c=gc();return x;
}
const int N=100005;
int n,tp,ans,pre[N],nxt[N];char s[N];
queue<int>q[2];
struct st{int l,r;}stk[N];
inline void add(int u,int v){nxt[u]=v;pre[v]=u;}
inline bool bal()
{
	if(tp<2)return 0;
	st a=stk[tp],b=stk[tp-1];
	if(s[a.r]!=s[b.l]){add(a.r,b.l);stk[--tp]=(st){a.l,b.r};return 1;}
	if(s[a.l]!=s[b.r]){add(b.r,a.l);stk[--tp]=(st){b.l,a.r};return 1;}
	if(s[a.l]!=s[b.l])
	{
		if(a.r>b.r)swap(a,b);int p=pre[b.r];
		add(a.r,b.r);add(b.r,b.l);nxt[p]=0;stk[--tp]=(st){a.l,p};
		return 1;
	}
	return 0;
}
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	rep(i,1,n)
	{
		int c=s[i]=='L';
		if(!q[c].empty())add(q[c].front(),i),q[c].pop();
		q[c^1].push(i);
	}
	rep(i,1,n)if(!pre[i])
	{
		ans++;int p=i;
		while(nxt[p])p=nxt[p];
		stk[++tp]=(st){i,p};
		while(bal());
	}
	printf("%d\n",ans-1);
	for(int x=stk[1].l;x;x=nxt[x])printf("%d ",x);
	return 0;
}