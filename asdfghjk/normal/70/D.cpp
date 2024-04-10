#include<cstdio>
#include<set>
using namespace std;
typedef long long ll;
struct node
{
	int x,y,xx;
}o,now;
int xx(int x,int y)
{
	if(y>0)
	{
		if(x>0)
			return 1;
		else
			return 2;
	}
	else
	{
		if(x>0)
			return 4;
		else
			return 3;
	}
}
ll mult(node a,node b)
{
	return 1ll*a.x*b.y-1ll*a.y*b.x;
}
bool operator <(node a,node b)
{
	if(a.xx!=b.xx)
		return a.xx<b.xx;
	ll mt=mult(a,b);
	if(mt)
		return mt>0;
	return a.x<b.x;
}
bool operator ==(node a,node b)
{
	return a.x==b.x&&a.y==b.y;
}
set<node> s;
set<node>::iterator dzx,phh,tk;
int n,i,j,k,l,x,y,z;
ll Abs(ll a)
{
	return a<0?-a:a;
}
int main()
{
	scanf("%d",&n);
	scanf("%d%d%d",&l,&i,&j);
	scanf("%d%d%d",&l,&k,&x);
	scanf("%d%d%d",&l,&y,&z);
	o.x=i+k+y,o.y=j+x+z;
	s.insert((node){i*3-o.x,j*3-o.y,xx(i*3-o.x,j*3-o.y)});
	s.insert((node){k*3-o.x,x*3-o.y,xx(k*3-o.x,x*3-o.y)});
	s.insert((node){y*3-o.x,z*3-o.y,xx(y*3-o.x,z*3-o.y)});
	for(l=4;l<=n;++l)
	{
		scanf("%d",&i);
		if(i==1)
		{
			scanf("%d%d",&x,&y);
			x=x*3-o.x,y=y*3-o.y;
			now=(node){x,y,xx(x,y)};
			if(now<*(s.begin()))
			{
				dzx=s.end();
				dzx--;
			}
			else
			{
				dzx=s.lower_bound(now);
				dzx--;
			}
			phh=s.end();
			phh--;
			if(*phh<now)
				phh=s.begin();
			else
				phh=s.lower_bound(now);
			if(Abs(mult(*dzx,*phh))==Abs(mult(now,*dzx))+Abs(mult(now,*phh))+Abs(mult((node){(dzx->x)-now.x,(dzx->y)-now.y},(node){(phh->x)-now.x,(phh->y)-now.y})))
				continue;
			while(1)
			{
				if(dzx==s.begin())
				{
					tk=s.end();
					tk--;
				}
				else
				{
					tk=dzx;
					tk--;
				}
				if(mult((node){(tk->x)-now.x,(tk->y)-now.y},(node){(dzx->x)-now.x,(dzx->y)-now.y})>0)
					break;
				s.erase(dzx);
				dzx=tk;
			}
			while(1)
			{
				tk=phh;
				tk++;
				if(tk==s.end())
					tk=s.begin();
				if(mult((node){(tk->x)-now.x,(tk->y)-now.y},(node){(phh->x)-now.x,(phh->y)-now.y})<0)
					break;
				s.erase(phh);
				phh=tk;
			}
			s.insert(now);
		}
		else
		{
			scanf("%d%d",&x,&y);
			x=x*3-o.x,y=y*3-o.y;
			now=(node){x,y,xx(x,y)};
			if(now<*(s.begin()))
			{
				dzx=s.end();
				dzx--;
			}
			else
			{
				dzx=s.lower_bound(now);
				dzx--;
			}
			phh=s.end();
			phh--;
			if(*phh<now)
				phh=s.begin();
			else
				phh=s.lower_bound(now);
			//printf("%d %d  %d %d  %d %d\n",x,y,dzx->x,dzx->y,phh->x,phh->y);
			if(Abs(mult(*dzx,*phh))==Abs(mult(now,*dzx))+Abs(mult(now,*phh))+Abs(mult((node){(dzx->x)-now.x,(dzx->y)-now.y},(node){(phh->x)-now.x,(phh->y)-now.y})))
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}