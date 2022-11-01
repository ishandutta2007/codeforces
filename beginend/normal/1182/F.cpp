#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

typedef long long LL;

const int N=100005;
const LL inf=2e9;

LL a,b,p,q;
struct data{int x;LL val;}f[N];

bool cmp(data a,data b) {return a.val<b.val||a.val==b.val&&a.x<b.x;}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&p,&q);
		int L=sqrt(b-a+1);
		LL ans=inf;int ansx;
		for (int i=0;i<L;i++) f[i+1].val=2*p*(a+i)%(q*2),f[i+1].x=a+i;
		std::sort(f+1,f+L+1,cmp);
		for (int i=2;i<=L;i++)
			if (f[i].val==f[i-1].val) f[i].x=f[i-1].x;
		f[L+1]=f[1];f[L+1].val+=q*2;
		f[0]=f[L];
		LL k=0;
		for (int i=0;(i+1)*L<=b-a+1;i++)
		{
			LL tar=(q*3-k)%(q*2);int lef=1,rig=L;
			while (lef<=rig)
			{
				int mid=(lef+rig)/2;
				if (f[mid].val<=tar) lef=mid+1;
				else rig=mid-1;
			}
			LL w=std::min((f[lef-1].val+q*2-tar)%(q*2),(tar-f[lef-1].val+q*2)%(q*2));
			if (w<ans||w==ans&&f[lef-1].x+L*i<ansx) ans=w,ansx=f[lef-1].x+L*i;
			w=std::min((f[lef].val+q*2-tar)%(q*2),(tar-f[lef].val+q*2)%(q*2));
			if (w<ans||w==ans&&f[lef].x+L*i<ansx) ans=w,ansx=f[lef].x+L*i;
			k=(k+(LL)2*p*L)%(q*2);
		}
		for (int i=b-L+1;i<=b;i++)
		{
			LL w=std::min(((LL)2*p*i+q)%(q*2),(q*3-(LL)2*p*i%(q*2))%(q*2));
			if (w<ans) ans=w,ansx=i;
		}
		printf("%d\n",ansx);
	}
	return 0;
}