#include<bits/stdc++.h>

typedef long long LL;

LL n,k,a[105];

LL get(LL pos,LL now,LL rk)
{
	LL l=pos*(k*k+1)+1+rk*k;
	if (l+k>now) return (l*2+k-1)*k/2+(l<=now?l+k-now:k);
	else return (l*2+k-1)*k/2;
}

LL find(LL id)
{
	int top=0;
	while (id) a[++top]=id%k,id/=k;
	LL pos=0,now=k*(k+1)/2;
	while (top) now=get(pos,now,a[top]),pos=pos*k+a[top],top--;
	return now;
}

LL query1(LL n)
{
	LL l=0,r=(n-1)/(k*k+1),pos;
	while (l<=r)
	{
		LL mid=(l+r)/2,lef=mid*(k*k+1)+1,rig=(mid+1)*(k*k+1);
		if ((lef*2+k-1)<=n*2/k&&(rig*2-k+1)>=n*2/k) {pos=mid;break;}
		else if ((rig*2-k+1)<=(n-1)*2/k) l=mid+1;
		else r=mid-1;
	}
	LL num=find(pos);
	l=0,r=k-1;
	while (l<=r)
	{
		LL mid=(l+r)/2,w=get(pos,num,mid);
		if (w==n) return k*k*pos+(mid+1)*k+mid+k*pos+1;
		else if (w<n) l=mid+1;
		else r=mid-1;
	}
}

LL query2(LL n,LL num)
{
	LL x=(n-1)/(k*k+1),s1=x*k+(n-1)%(k*k+1)/k,s2=x+(num<n);
	if (num<=n&&(n-1)%(k*k+1)%k==0) s1--;
	return n+s1-s2;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%lld%lld",&n,&k);
		LL x=find((n-1)/(k*k+1));
		if (x==n) printf("%lld\n",query1(n));
		else printf("%lld\n",query2(n,x));
	}
	return 0;
}