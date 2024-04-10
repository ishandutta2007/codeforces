#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 400005
struct cur{double x,y,r;}s[N];
double sx,sy,tx,ty;
int n,ct;
struct add{double x;int k;}q[N];
struct point{double x,y;}s1,s2,s3[N];
bool cmp(add a,add b){return a.x<b.x;}
point operator +(point x,point y){return (point){x.x+y.x,x.y+y.y};}
point operator -(point x,point y){return (point){x.x-y.x,x.y-y.y};}
point operator *(point x,double p){return (point){x.x*p,x.y*p};}
double len(point x){return sqrt(x.x*x.x+x.y*x.y);}
int main()
{
	scanf("%lf%lf%lf%lf%d",&s1.x,&s1.y,&s2.x,&s2.y,&n);
	for(int i=1;i<=n;i++)scanf("%lf%lf%lf",&s[i].x,&s[i].y,&s[i].r),s3[i]=(point){s[i].x,s[i].y};
	for(int i=1;i<=n;i++)
	{
		double lb=-1e12,rb=1e12;
		for(int fuck=1;fuck<=200;fuck++)
		{
			double mid=(lb+rb)/2;
			point md=(s1+s2)*0.5,st=(point){(s2-s1).y,-(s2-s1).x};
			st=st*(1/len(st));
			md=(s1+s2)*0.5+st*mid;
			if(len(md-(point){s[i].x,s[i].y})-s[i].r-len(s1-md)<=0)
			{
				if(len((s1+s2)*0.5+st*lb-s3[i])-s[i].r-len(s1-(s1+s2)*0.5-st*lb)<=0)lb=mid;
				else rb=mid;
			}
			else
			{
				if(len((s1+s2)*0.5+st*lb-s3[i])-s[i].r-len(s1-(s1+s2)*0.5-st*lb)>=0)lb=mid;
				else rb=mid;
			}
		}
		double lb2=-1e12,rb2=1e12;
		for(int fuck=1;fuck<=200;fuck++)
		{
			double mid=(lb2+rb2)/2;
			point md=(s1+s2)*0.5,st=(point){(s2-s1).y,-(s2-s1).x};
			st=st*(1/len(st));
			md=(s1+s2)*0.5+st*mid;
			if(len(md-(point){s[i].x,s[i].y})+s[i].r-len(s1-md)<=0)
			{
				if(len((s1+s2)*0.5+st*lb2-s3[i])+s[i].r-len(s1-(s1+s2)*0.5-st*lb2)<=0)lb2=mid;
				else rb2=mid;
			}
			else
			{
				if(len((s1+s2)*0.5+st*lb2-s3[i])+s[i].r-len(s1-(s1+s2)*0.5-st*lb2)>=0)lb2=mid;
				else rb2=mid;
			}
		}
		if(lb>lb2){double t=lb;lb=lb2;lb2=t;}
		q[++ct]=(add){lb,1};q[++ct]=(add){lb2,-1};
	}
	sort(q+1,q+ct+1,cmp);
	double ans=-1e12;int c=0;
	ans=q[1].x;
	q[ct+1].x=1e12;
	for(int i=1;i<=ct;i++)
	{
		c+=q[i].k;
		if(c==0)
		{
			if(abs(ans)>abs(q[i].x))ans=q[i].x;
			if(abs(ans)>abs(q[i+1].x))ans=q[i+1].x;
			if(q[i].x<0&&q[i+1].x>0)ans=0;
		}
	}
	printf("%.10lf\n",sqrt(ans*ans+len(s1-s2)*len(s1-s2)/4));
}