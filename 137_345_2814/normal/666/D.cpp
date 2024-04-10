#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,s[5][2],mn,as[5][2],T,s1[5][2],is[5],r[5][4],as2[5][2];
int doit1(int x,int y){return max(max(max(s1[1][1]-x,x-s1[1][1]),max(s1[2][1]-y,y-s1[2][1])),max(max(s1[3][1]-x,x-s1[3][1]),max(s1[4][1]-y,y-s1[4][1])));}
int doit2(int x,int y){return max(max(max(s1[1][0]-x,x-s1[1][0]),max(s1[2][0]-y,y-s1[2][0])),max(max(s1[3][0]-x,x-s1[3][0]),max(s1[4][0]-y,y-s1[4][0])));}
void solve(int d1,int d2,int d3,int d4,int v1,int v2,int v3,int v4)
{
	s1[v1][0]=s[1][0];s1[v1][1]=s[1][1];
	s1[v2][0]=s[2][0];s1[v2][1]=s[2][1];
	s1[v3][0]=s[3][0];s1[v3][1]=s[3][1];
	s1[v4][0]=s[4][0];s1[v4][1]=s[4][1];
	if(s1[1][0]==s1[2][0]&&s1[3][0]==s1[4][0])
	{
		memcpy(as2,s1,sizeof(as2));
		int t=s1[3][0]-s1[1][0];
		if(t<0)t=-t;
		int lb=-4e8,rb=4e8;
		while(lb<rb)
		{
			int mid=(lb+rb)>>1,mid1=mid+1;
			if(doit1(mid,mid+t)<doit1(mid1,mid1+t))rb=mid1;
			else lb=mid;
			if(doit1(mid,mid+t)==doit1(mid1,mid1+t)){lb=mid;rb=mid1;break;}
			if(doit1(mid-1,mid-1+t)==doit1(mid,mid+t)){lb=mid-1;rb=mid;break;}
			if(doit1(mid-1,mid-1+t)>doit1(mid,mid+t)&&doit1(mid,mid+t)<doit1(mid1,mid1+t)){lb=rb=mid;break;}
		}
		int tp=doit1(lb,lb+t);
		if(tp<mn)
		{
			mn=tp;
			s1[1][1]=s1[3][1]=lb;s1[2][1]=s1[4][1]=lb+t;
			as[1][0]=s1[v1][0];as[1][1]=s1[v1][1];
			as[2][0]=s1[v2][0];as[2][1]=s1[v2][1];
			as[3][0]=s1[v3][0];as[3][1]=s1[v3][1];
			as[4][0]=s1[v4][0];as[4][1]=s1[v4][1];
		}
		memcpy(s1,as2,sizeof(s1));
	}
	if(s1[1][1]==s1[2][1]&&s1[3][1]==s1[4][1])
	{
		memcpy(as2,s1,sizeof(as2));
		int t=s1[3][1]-s1[1][1];
		if(t<0)t=-t;
		int lb=-4e8,rb=4e8;
		while(lb<rb)
		{
			int mid=(lb+rb)>>1,mid1=mid+1;
			if(doit2(mid,mid+t)<doit2(mid1,mid1+t))rb=mid1;
			else lb=mid;
			if(doit2(mid,mid+t)==doit2(mid1,mid1+t)){lb=mid,rb=mid1;break;}
			if(doit2(mid-1,mid-1+t)==doit2(mid,mid+t)){lb=mid-1,rb=mid;break;}
			if(doit2(mid-1,mid-1+t)>doit2(mid,mid+t)&&doit2(mid,mid+t)<doit2(mid1,mid1+t)){lb=rb=mid;break;}
		}
		int tp=doit2(lb,lb+t);
		if(tp<mn)
		{
			mn=tp;
			s1[1][0]=s1[3][0]=lb;s1[2][0]=s1[4][0]=lb+t;
			as[1][0]=s1[v1][0];as[1][1]=s1[v1][1];
			as[2][0]=s1[v2][0];as[2][1]=s1[v2][1];
			as[3][0]=s1[v3][0];as[3][1]=s1[v3][1];
			as[4][0]=s1[v4][0];as[4][1]=s1[v4][1];
		}
		memcpy(s1,as2,sizeof(s1));
	}
	int ct=0;is[1]=is[2]=is[3]=is[4]=-1e9;
	int r1=(d1&1)?(d1==1?1:-1):0,r2=(d2&1)?(d2==1?1:-1):0;
	if(!r1&&!r2&&s1[1][1]!=s1[2][1])return;
	if(r1&&r2)
	{
		r[++ct][0]=1;r[ct][1]=2;
		if(r1+r2)r[ct][2]=1,r[ct][3]=(s1[2][1]-s1[1][1])*r1;
		else r[ct][2]=2,r[ct][3]=r1*(s1[2][1]-s1[1][1]);
	}
	else
	if(r1){is[1]=(s1[2][1]-s1[1][1])/r1;if(is[1]<0)return;}
	else if(r2){is[2]=(s1[1][1]-s1[2][1])/r2;if(is[2]<0)return;}
	r1=(d3&1)?(d3==1?1:-1):0,r2=(d4&1)?(d4==1?1:-1):0;
	if(!r1&&!r2&&s1[3][1]!=s1[4][1])return;
	if(r1&&r2)
	{
		r[++ct][0]=3;r[ct][1]=4;
		if(r1+r2)r[ct][2]=1,r[ct][3]=(s1[4][1]-s1[3][1])*r1;
		else r[ct][2]=2,r[ct][3]=r1*(s1[4][1]-s1[3][1]);
	}
	else
	if(r1){is[3]=(s1[4][1]-s1[3][1])/r1;if(is[3]<0)return;}
	else if(r2){is[4]=(s1[3][1]-s1[4][1])/r2;if(is[4]<0)return;}
	r1=(~d2&1)?(d2==2?1:-1):0,r2=(~d3&1)?(d3==2?1:-1):0;
	if(!r1&&!r2&&s1[2][0]!=s1[3][0])return;
	if(r1&&r2)
	{
		r[++ct][0]=2;r[ct][1]=3;
		if(r1+r2)r[ct][2]=1,r[ct][3]=(s1[3][0]-s1[2][0])*r1;
		else r[ct][2]=2,r[ct][3]=r1*(s1[3][0]-s1[2][0]);
	}
	else
	if(r1){is[2]=(s1[3][0]-s1[2][0])/r1;if(is[2]<0)return;}
	else if(r2){is[3]=(s1[2][0]-s1[3][0])/r2;if(is[3]<0)return;}
	r1=(~d4&1)?(d4==2?1:-1):0,r2=(~d1&1)?(d1==2?1:-1):0;
	if(!r1&&!r2&&s1[4][0]!=s1[1][0])return;
	if(r1&&r2)
	{
		r[++ct][0]=4;r[ct][1]=1;
		if(r1+r2)r[ct][2]=1,r[ct][3]=(s1[1][0]-s1[4][0])*r1;
		else r[ct][2]=2,r[ct][3]=r1*(s1[1][0]-s1[4][0]);
	}
	else
	if(r1){is[4]=(s1[1][0]-s1[4][0])/r1;if(is[4]<0)return;}
	else if(r2){is[1]=(s1[4][0]-s1[1][0])/r2;if(is[1]<0)return;}
	if(ct==0)
	{
		if(~d1&1)s1[1][0]+=is[1]*((d1&2)?1:-1);else s1[1][1]+=is[1]*((d1&2)?-1:1);
		if(~d2&1)s1[2][0]+=is[2]*((d2&2)?1:-1);else s1[2][1]+=is[2]*((d2&2)?-1:1);
		if(~d3&1)s1[3][0]+=is[3]*((d3&2)?1:-1);else s1[3][1]+=is[3]*((d3&2)?-1:1);
		if(~d4&1)s1[4][0]+=is[4]*((d4&2)?1:-1);else s1[4][1]+=is[4]*((d4&2)?-1:1);
		if(s1[2][0]-s1[1][0]==s1[3][1]-s1[2][1])
		{
			int tp=max(max(is[1],is[2]),max(is[3],is[4]));
			if(tp<mn)
			{
				mn=tp;
				as[1][0]=s1[v1][0];as[1][1]=s1[v1][1];
				as[2][0]=s1[v2][0];as[2][1]=s1[v2][1];
				as[3][0]=s1[v3][0];as[3][1]=s1[v3][1];
				as[4][0]=s1[v4][0];as[4][1]=s1[v4][1];
			}
		}
		return;
	}
	else if(ct==1)
	{
		if(is[1]>-5e8)if(~d1&1)s1[1][0]+=is[1]*((d1&2)?1:-1);else s1[1][1]+=is[1]*((d1&2)?-1:1);
		if(is[2]>-5e8)if(~d2&1)s1[2][0]+=is[2]*((d2&2)?1:-1);else s1[2][1]+=is[2]*((d2&2)?-1:1);
		if(is[3]>-5e8)if(~d3&1)s1[3][0]+=is[3]*((d3&2)?1:-1);else s1[3][1]+=is[3]*((d3&2)?-1:1);
		if(is[4]>-5e8)if(~d4&1)s1[4][0]+=is[4]*((d4&2)?1:-1);else s1[4][1]+=is[4]*((d4&2)?-1:1);
		if(r[1][0]==1)
		{
			int asy=-s1[2][0]+s1[1][0]+s1[3][1]-s1[2][1];
			int r1=(d1&1)?(d1==1?1:-1):0;asy/=r1;
			if(asy<0)return;
			is[1]=asy;
			if(r[1][2]==1)asy-=r[1][3];
			else asy=r[1][3]-asy;
			if(asy<0)return;
			is[2]=asy;
			if(~d1&1)s1[1][0]+=is[1]*((d1&2)?1:-1);else s1[1][1]+=is[1]*((d1&2)?-1:1);
			if(~d2&1)s1[2][0]+=is[2]*((d2&2)?1:-1);else s1[2][1]+=is[2]*((d2&2)?-1:1);
		}
		else if(r[1][0]==3)
		{
			int asy=s1[2][0]-s1[1][0]+s1[2][1]-s1[3][1];
			int r1=(d3&1)?(d3==1?1:-1):0;asy/=r1;
			if(asy<0)return;
			is[3]=asy;
			if(r[1][2]==1)asy-=r[1][3];
			else asy=r[1][3]-asy;
			if(asy<0)return;
			is[4]=asy;
			if(~d3&1)s1[3][0]+=is[3]*((d3&2)?1:-1);else s1[3][1]+=is[3]*((d3&2)?-1:1);
			if(~d4&1)s1[4][0]+=is[4]*((d4&2)?1:-1);else s1[4][1]+=is[4]*((d4&2)?-1:1);
		}
		else if(r[1][0]==2)
		{
			int asy=s1[3][1]-s1[2][1]+s1[1][0]-s1[2][0];
			int r1=(~d2&1)?(d2==2?1:-1):0;asy/=r1;
			if(asy<0)return;
			is[2]=asy;
			if(r[1][2]==1)asy-=r[1][3];
			else asy=r[1][3]-asy;
			if(asy<0)return;
			is[3]=asy;
			if(~d2&1)s1[2][0]+=is[2]*((d2&2)?1:-1);else s1[2][1]+=is[2]*((d2&2)?-1:1);
			if(~d3&1)s1[3][0]+=is[3]*((d3&2)?1:-1);else s1[3][1]+=is[3]*((d3&2)?-1:1);
		}
		else
		{
			int asy=-s1[3][1]+s1[2][1]+s1[2][0]-s1[1][0];
			int r1=(~d1&1)?(d1==2?1:-1):0;asy/=r1;
			if(asy<0)return;
			is[1]=asy;
			if(r[1][2]==1)asy+=r[1][3];
			else asy=r[1][3]-asy;
			if(asy<0)return;
			is[4]=asy;
			if(~d1&1)s1[1][0]+=is[1]*((d1&2)?1:-1);else s1[1][1]+=is[1]*((d1&2)?-1:1);
			if(~d4&1)s1[4][0]+=is[4]*((d4&2)?1:-1);else s1[4][1]+=is[4]*((d4&2)?-1:1);
		}
		if(s1[2][0]-s1[1][0]==s1[3][1]-s1[2][1])
		{
			int tp=max(max(is[1],is[2]),max(is[3],is[4]));
			if(tp<mn)
			{
				mn=tp;
				as[1][0]=s1[v1][0];as[1][1]=s1[v1][1];
				as[2][0]=s1[v2][0];as[2][1]=s1[v2][1];
				as[3][0]=s1[v3][0];as[3][1]=s1[v3][1];
				as[4][0]=s1[v4][0];as[4][1]=s1[v4][1];
			}
		}
		return;
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		mn=1e9;
		scanf("%d%d%d%d%d%d%d%d",&s[1][0],&s[1][1],&s[2][0],&s[2][1],&s[3][0],&s[3][1],&s[4][0],&s[4][1]);
		for(int v1=1;v1<=4;v1++)
		for(int v2=1;v2<=4;v2++)
		for(int v3=1;v3<=4;v3++)
		for(int v4=1;v4<=4;v4++)
		if(v1!=v2&&v1!=v3&&v1!=v4&&v2!=v3&&v2!=v4&&v3!=v4)
		for(int d1=1;d1<=4;d1++)
		for(int d2=1;d2<=4;d2++)
		for(int d3=1;d3<=4;d3++)
		for(int d4=1;d4<=4;d4++)
		solve(d1,d2,d3,d4,v1,v2,v3,v4);
		if(mn>5e8)printf("-1\n");
		else printf("%d\n%d %d\n%d %d\n%d %d\n%d %d\n",mn,as[1][0],as[1][1],as[2][0],as[2][1],as[3][0],as[3][1],as[4][0],as[4][1]);
	}
}