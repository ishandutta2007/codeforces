#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
typedef long long ll;
struct pnt
{
	ll x,y;
	pnt(ll _x=0,ll _y=0){x=_x,y=_y;}
	void rd(){scanf("%lld%lld",&x,&y);}
	void rev(){x=-x,y=-y;}
	ll abs()cpnst{return x*x+y*y;}
};
pnt operator+(cpnst pnt x,cpnst pnt y){return pnt(x.x+y.x,x.y+y.y);}
pnt operator-(cpnst pnt x,cpnst pnt y){return pnt(x.x-y.x,x.y-y.y);}
ll operator*(cpnst pnt x,cpnst pnt y){return x.x*y.y-x.y*y.x;}
bool operator<(cpnst pnt x,cpnst pnt y)
{return x.x<y.x||(x.x==y.x&&x.y<y.y);}
bool inc(cpnst pnt x,cpnst pnt y)
{return x*y>0||(x*y==0&&x.abs()<y.abs());}
struct pii
{
	pnt p;
	int Id,cl;
}p[1111111];
#include<algorithm>
int n;
bool operator<(cpnst pii x,cpnst pii y){return x.p<y.p;}
bool incd(cpnst pii x,cpnst pii y){return inc(x.p,y.p);}
int mat[111111];
void solve(int L=1,int R=n<<1)
{
	if(L>R)return;
	if(L+1==R)
	{bool t=p[L].cl;mat[p[L+t].Id]=p[L+!t].Id;return;}
	//std::sort(p+L,p+R+1);
	register int i;
	for(i=L+1;i<=R;i++)
	if(p[i].p<p[L].p){pii t=p[i];p[i]=p[L],p[L]=t;}
	pnt gg=p[L].p;
	for(i=L;i<=R;i++)p[i].p=p[i].p-gg;
	std::sort(p+L,p+R+1,incd);
	int SS=1;
	for(i=1;i<=R-L;i++)
	{
		(p[L].cl^p[L+i].cl)?SS--:SS++;
		if(SS==0)
			if(p[L].cl^p[L+i].cl)
				if(i>=L+(R-L)/4)
				{
					int t=p[L].cl*i;
					mat[p[L+t].Id]=p[L+(!t)*i].Id;
					solve(L+1,L+i-1),solve(L+i+1,R);
					return;
				}
	}for(i=SS=1;;i++)
	{
		(p[L].cl^p[L+i].cl)?SS--:SS++;
		if(SS==0)
		{
			int t=p[L].cl*i;
			mat[p[L+t].Id]=p[L+(!t)*i].Id;
			solve(L+1,L+i-1),solve(L+i+1,R);
			return;
		}
	}
}
int main()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;i++)
		p[i].p.rd(),p[i].p.x=-p[i].p.x,p[i].Id=i,p[i].cl=0;
	for(i=1;i<=n;i++)
		p[i+n].p.rd(),p[i+n].p.x=-p[i+n].p.x,p[i+n].Id=i,p[i+n].cl=1;
	solve();
	for(i=1;i<=n;i++)printf("%d\n",mat[i]);
}
/*
Just go for it.
*/