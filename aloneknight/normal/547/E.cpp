#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
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
#define ls T[x].l,l,m
#define rs T[x].r,m+1,r
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define C(x,y) memset(x,y,sizeof(x))
const int N=400005;
int n,m,tt,rt[N];char s[N];
struct st{int l,r,s;}T[N*25];
void upd(int&x,int l,int r,int p)
{
	if(!x)x=++tt;T[x].s++;if(l==r)return;
	int m=l+r>>1;p<=m?upd(ls,p):upd(rs,p);
}
int qry(int x,int l,int r,int tl,int tr)
{
	if(!x||(tl<=l&&r<=tr))return T[x].s;int m=l+r>>1;
	return (tl<=m?qry(ls,tl,tr):0)+(tr>m?qry(rs,tl,tr):0);
}
int merge(int x,int y)
{
	if(!x||!y)return x|y;int t=++tt;T[t].s=T[x].s+T[y].s;
	T[t].l=merge(T[x].l,T[y].l);T[t].r=merge(T[x].r,T[y].r);return t;
}
struct SAM
{
	int tt,lst,ch[N][26],lk[N],mx[N],id[N],c[N],q[N];
	void extend(int c)
	{
		int p=lst;
		if(ch[p][c])
		{
			int q=ch[p][c];
			if(mx[p]+1==mx[q]){lst=q;return;}
			int nq=++tt;mx[nq]=mx[p]+1;lk[nq]=lk[q];
			lk[q]=nq;memcpy(ch[nq],ch[q],sizeof(ch[q]));
			for(;ch[p][c]==q;p=lk[p])ch[p][c]=nq;lst=nq;return;
		}
		int np=lst=++tt;mx[np]=mx[p]+1;
		for(;!ch[p][c];p=lk[p])ch[p][c]=np;
		if(!p)lk[np]=1;
		else
		{
			int q=ch[p][c];
			if(mx[p]+1==mx[q])lk[np]=q;
			else
			{
				int nq=++tt;mx[nq]=mx[p]+1;lk[nq]=lk[q];
				lk[q]=lk[np]=nq;memcpy(ch[nq],ch[q],sizeof(ch[q]));
				for(;ch[p][c]==q;p=lk[p])ch[p][c]=nq;
			}
		}
	}
	void sort()
	{
		rep(i,1,tt)c[mx[i]]++;
		rep(i,1,tt)c[i]+=c[i-1];
		per(i,tt,1)q[c[mx[i]]--]=i;
		per(i,tt,2){int x=q[i];rt[lk[x]]=merge(rt[lk[x]],rt[x]);}
	}
}S;
int main()
{
	n=rd();m=rd();S.lst=S.tt=1;
	rep(i,1,n)
	{
		scanf("%s",s+1);int l=strlen(s+1);S.lst=1;
		rep(j,1,l)S.extend(s[j]-'a'),upd(rt[S.lst],1,n,i);
		S.id[i]=S.lst;
	}
	S.sort();
	while(m--)
	{
		int l=rd(),r=rd(),k=rd();
		printf("%d\n",qry(rt[S.id[k]],1,n,l,r));
	}
	return 0;
}