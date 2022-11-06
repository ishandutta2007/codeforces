#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui long long
#define ull unsigned long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
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
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=200005;
int n,m,tp,c[26],ps[N],stk[N];char s[N],t[N];vector<pii>ans;
struct tr{int s,o;}T[N*4];
inline void up(int x){T[x].s=T[x<<1].s+T[x<<1|1].s;}
inline void cov(int x,int l,int r){T[x].s=r-l+1;T[x].o=1;}
void dn(int x,int l,int r){if(!T[x].o)return;int m=l+r>>1;cov(ls);cov(rs);T[x].o=0;}
void build(int x,int l,int r)
{
	T[x].s=T[x].o=0;if(l==r)return;
	int m=l+r>>1;build(ls);build(rs);
}
void upd(int x,int l,int r,int tl,int tr)
{
	if(tl<=l&&r<=tr){cov(x,l,r);return;}int m=l+r>>1;dn(x,l,r);
	if(tl<=m)upd(ls,tl,tr);if(tr>m)upd(rs,tl,tr);up(x);
}
int qry(int x,int l,int r,int tl,int tr)
{
	if(tl<=l&&r<=tr)return T[x].s;int m=l+r>>1;dn(x,l,r);
	return (tl<=m?qry(ls,tl,tr):0)+(tr>m?qry(rs,tl,tr):0);
}
inline bool chk()
{
	int s=0,mx=0;
	rep0(i,0,26)s+=c[i],mx=max(mx,c[i]);
	return mx*2<=s;
}
void sol()
{
	scanf("%s",s+1);n=strlen(s+1);tp=0;ans.clear();memset(c,0,sizeof(c));
	m=0;rep(i,2,n)if(s[i]==s[i-1]){t[++m]=s[i];ps[m]=i;c[s[i]-'a']++;}
	int p=0;rep0(i,0,26)if(c[i]>c[p])p=i;
	if(c[p]*2>m)
	{
		rep(i,1,m)
		{
			if(t[i]=='a'+p)
			{
				if(!tp||t[stk[tp]]=='a'+p)stk[++tp]=i;
				else{ans.pb(mp(ps[stk[tp]],ps[i]-1));tp--;}
			}
			else
			{
				if(tp&&t[stk[tp]]=='a'+p){ans.pb(mp(ps[stk[tp]],ps[i]-1));tp--;}
				else stk[++tp]=i;
			}
		}
	}
	else
	{
		if(m&1)c[t[m]-'a']--,m--;
		rep(i,1,m)
		{
			if(!tp||t[i]==t[stk[tp]])stk[++tp]=i;
			else
			{
				c[t[i]-'a']--;c[t[stk[tp]]-'a']--;int o=chk();
				if(!o){c[t[i]-'a']++;c[t[stk[tp]]-'a']++;stk[++tp]=i;}
				else{ans.pb(mp(ps[stk[tp]],ps[i]-1));tp--;}
			}
		}
	}
	build(1,1,n);
	fore(i,ans)
	{
		int x=ans[i].X,y=ans[i].Y;
		ans[i]=mp(x-qry(1,1,n,1,x),y-qry(1,1,n,1,y));
		upd(1,1,n,x,y);
	}
	m=0;rep(i,1,n)if(!qry(1,1,n,i,i))t[++m]=s[i];
	p=1;rep(i,2,m)if(t[i]==t[i-1]){ans.pb(mp(1,i-p));p=i;}
	ans.pb(mp(1,m-p+1));printf("%d\n",(int)ans.size());
	fore(i,ans)printf("%d %d\n",ans[i].X,ans[i].Y);
}
int main(){int T=rd();while(T--)sol();return 0;}