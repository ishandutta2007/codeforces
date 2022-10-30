#include<bits/stdc++.h>
using namespace std;
int n,i,yuyu,j,op,num,x[1000005],y[1000005];
long long k,d[1000005],s,ans;
struct str{
	int al,ar,bl,br;
}p[2000005],tmp[2000005];
int split(int l,int r,int i)
{
	int j;
	for(j=l;j<=r;++j)
		if((d[j]>>i)&1)
			return j;
	return j;
}
int main()
{
	cin>>n>>k;
	--k;
	for(i=2;i<=n;++i)
	{
		scanf("%d %lld",&yuyu,&d[i]);
		d[i]^=d[yuyu];
	}
	sort(d+1,d+1+n);
	p[1].al=p[1].bl=1;
	p[1].ar=p[1].br=n;
	num=1;
	for(i=62;i>=0;--i)
	{
		s=0;
		for(j=1;j<=num;++j)
		{
			int l=split(p[j].al,p[j].ar,i),r=split(p[j].bl,p[j].br,i);
			x[j]=l;y[j]=r;
			s+=1ll*(l-p[j].al)*(r-p[j].bl)+1ll*(p[j].ar-l+1)*(p[j].br-r+1);
		}
		if(s<=k)
		{
			k-=s;
			op=0;
			for(j=1;j<=num;++j)
			{
				if(x[j]!=p[j].al&&y[j]!=p[j].br+1)
					tmp[++op]=(str){p[j].al,x[j]-1,y[j],p[j].br};
				if(x[j]!=p[j].ar+1&&y[j]!=p[j].bl)
					tmp[++op]=(str){x[j],p[j].ar,p[j].bl,y[j]-1};
			}
			ans|=1ll<<i;
		}
		else
		{
			op=0;
			for(j=1;j<=num;++j)
			{
				if(x[j]!=p[j].al&&y[j]!=p[j].bl)
					tmp[++op]=(str){p[j].al,x[j]-1,p[j].bl,y[j]-1};
				if(x[j]!=p[j].ar+1&&y[j]!=p[j].br+1)
					tmp[++op]=(str){x[j],p[j].ar,y[j],p[j].br};
			}
		}
		num=op;
		for(j=1;j<=op;++j)
			p[j]=tmp[j];
	}
	cout<<ans;
}