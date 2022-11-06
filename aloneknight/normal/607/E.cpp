#include<bits/stdc++.h>
using namespace std;
#define db double
#define pb push_back
#define lb lower_bound
const int N=100005;
const db eps=1e-16,pi=acos(-1.0);
inline int rd()
{
	int x=0,w=1;char c=getchar();while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();while(isdigit(c))x=x*10+c-48,c=getchar();return x*w;
}
inline int sgn(db x){return x<-eps?-1:x>eps;}
inline bool cmp(db x,db y){return sgn(x-y)<0;}
inline bool eq(db x,db y){return !sgn(x-y);}
int n,m,tt,nn,cc,s[N],T[N],ql[N],qr[N];db ans,D[N],o[N];vector<int>Ql[N],Qr[N];
struct P{db x,y;}L[N],Q[N];
inline void upd(int x,int v){for(;x<=nn;x+=x&-x)T[x]+=v;}
inline int qry(int x){int r=0;for(;x;x-=x&-x)r+=T[x];return r;}
struct st
{
	int l,r,i;
	friend bool operator<(st a,st b){return a.r<b.r;}
}q[N],q2[N];
inline db inter(int i,int j){db x=(L[j].y-L[i].y)/(L[i].x-L[j].x),y=L[i].x*x+L[i].y;return sqrt(x*x+y*y);}
void sol(int l,int r)
{
	if(l==r)return;int m=l+r>>1;sol(l,m);sol(m+1,r);
	int p1=l,p2=m+1,t=l;
	while(p1<=m&&p2<=r)
	{
		if(q[p1].l<q[p2].l)
		{
			for(int i=p2;i<=r;i++)
			{
				if(q[i].l>=q[p1].r)break;
				if(q[p1].r<q[i].r)tt++,ans+=inter(q[p1].i,q[i].i);
			}
			q2[t++]=q[p1++];
		}
		else q2[t++]=q[p2++];
	}
	while(p1<=m)q2[t++]=q[p1++];
	while(p2<=r)q2[t++]=q[p2++];
	for(int i=l;i<=r;i++)q[i]=q2[i];
}
inline bool calc(db R,int op)
{
	tt=0;nn=0;cc=0;
	for(int i=1;i<=n;i++)
	{
		db a=L[i].x,b=L[i].y,A=a*a+1,B=a*b;
		D[i]=a*a*R*R+R*R-b*b;if(sgn(D[i])<0)continue;
		db d=sqrt(D[i]);db px=(-B-d)/A,py=a*px+b,qx=(-B+d)/A,qy=a*qx+b;
		o[++nn]=Q[i].x=atan2(py,px);o[++nn]=Q[i].y=atan2(qy,qx);
	}
	sort(o+1,o+nn+1,cmp);nn=unique(o+1,o+nn+1,eq)-o-1;
	if(!op)
	{
		for(int i=1;i<=nn;i++)T[i]=0,s[i]=0,Ql[i].clear(),Qr[i].clear();
		for(int i=1;i<=n;i++)if(sgn(D[i])>=0)
		{
			ql[i]=lb(o+1,o+nn+1,Q[i].x,cmp)-o;
			qr[i]=lb(o+1,o+nn+1,Q[i].y,cmp)-o;
			if(ql[i]>qr[i])swap(ql[i],qr[i]);
			Ql[ql[i]].pb(i);Qr[qr[i]].pb(i);
			s[ql[i]]++;if(ql[i]!=qr[i])s[qr[i]]++;
		}
		for(int i=1;i<=nn;i++)
		{
			for(int j=0;j<Ql[i].size();j++)upd(i,1);
			for(int j=0;j<Qr[i].size();j++)upd(ql[Qr[i][j]],-1),tt+=qry(i-1)-qry(ql[Qr[i][j]]);
			tt+=1ll*s[i]*(s[i]-1)/2;
		}
		return tt>=m;
	}
	for(int i=1;i<=n;i++)if(sgn(D[i])>=0)
	{
		q[++cc].l=lb(o+1,o+nn+1,Q[i].x,cmp)-o;
		q[cc].r=lb(o+1,o+nn+1,Q[i].y,cmp)-o;q[cc].i=i;
		if(q[cc].l>q[cc].r)swap(q[cc].l,q[cc].r);
	}
	sort(q+1,q+cc+1);sol(1,cc);
	printf("%.10lf\n",(double)(ans+1.0*(m-tt)*R));
}
int main()
{
	db x,y,a,b,l=0,r=3000000000,mid;n=rd();x=1.0*rd()/1000;y=1.0*rd()/1000;m=rd();
	for(int i=1;i<=n;i++){a=1.0*rd()/1000;b=1.0*rd()/1000;L[i]=(P){a,a*x+b-y};}
	for(int i=0;i<60;i++)if(calc(mid=(l+r)*0.5,0))r=mid;else l=mid;
	calc(l,1);return 0;
}