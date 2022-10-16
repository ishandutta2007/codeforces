#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int a[1111111];
int n;
double b[1111111];
typedef long long ll;
typedef long double db;
const db eps=1e-12;
struct pii
{db p;int l,r;
pii(db x=0,int ls=0,int rs=0){p=x,l=ls,r=rs;}
};
inline bool operator<(const pii x,const pii y)
{if(x.p-y.p<=-eps||x.p-y.p>=eps)return x.p>y.p;
return x.l<y.l;}
#include<queue> 
std::priority_queue<pii>s,d;
inline pii gettop()
{
	if(!d.size())return s.top();
	while(d.size())
	{
		pii v=s.top(),w=d.top();
		if(v.l==w.l&&v.r==w.r)s.pop(),d.pop();
		else return v;
	}return s.top();
}
int r[1111111];
ll ds[1111111];
int main()
{
	
	scanf("%d",&n);
	register int i,ii;
	for(i=1;i<=n;i++)
		scanf("%d",a+i),s.push(pii(a[i],i,i)),
		r[i]=i,ds[i]=ds[i-1]+a[i];
	int nw=1;
	for(i=1;i<=n;i++)
	{
		pii x=gettop();
		s.pop();
		if(x.l==nw)
		{
			for(ii=x.l;ii<=x.r;ii++)
			{
				double val=x.p;
				printf("%.12lf\n",val);
			}
			nw=x.r+1;
		}else
		{
			int ls=r[x.l-1],rs=x.l-1;
			int siz0=(rs-ls+1),siz1=(x.r-x.l+1),siz=
			siz0+siz1;
			db g=1;
			db vs=(ds[rs]-ds[ls-1])*g;
			vs/=siz0;
			r[x.r]=ls;
			d.push(pii(vs,ls,rs));
			s.push(pii((vs*siz0+x.p*siz1)/siz,ls,x.r));
		}
	}
}
/*
Every little step contributes in constructing what is called the great.
*/