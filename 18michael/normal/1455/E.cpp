#include<bits/stdc++.h>
#define LL long long
#define inf 0x7fffffff
using namespace std;
int Test_num;LL ans;
LL px[4],py[4];
inline LL calc(int a,int b,int c,int d)
{
	LL x0,x1,x2,x3,l1,r1,y0,y1,y2,y3,l2,r2;
	x0=min(px[a],px[b]),x1=max(px[a],px[b]),x2=min(px[c],px[d]),x3=max(px[c],px[d]),l1=(max(x0,x2)<=min(x1,x3)? 0:max(x2-x1,x0-x3)),r1=max(x3-x0,x1-x2);
	y0=min(py[a],py[c]),y1=max(py[a],py[c]),y2=min(py[b],py[d]),y3=max(py[b],py[d]),l2=(max(y0,y2)<=min(y1,y3)? 0:max(y2-y1,y0-y3)),r2=max(y3-y0,y1-y2);
	return x1-x0+x3-x2+y1-y0+y3-y2+(max(l1,l2)<=min(r1,r2)? 0:2*min(abs(r1-l2),abs(r2-l1)));
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		ans=inf;
		for(int i=0;i<4;++i)scanf("%lld%lld",&px[i],&py[i]);
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j)
				if(j!=i)
					for(int k=0;k<4;++k)
						if(k!=i && k!=j)
							for(int l=0;l<4;++l)
								if(l!=i && l!=j && l!=k)
									ans=min(ans,calc(i,j,k,l));
		printf("%lld\n",ans);
	}
	return 0;
}