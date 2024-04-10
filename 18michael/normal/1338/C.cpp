#include<cstdio>
#define Mx 30
#define LL long long
int Test_num,k;
LL n,l,r,l1,r1,ans;
LL pw[32];
inline int type(LL x)
{
	int l=0,r=30,mid;
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(pw[mid]>x)r=mid-1;
		else l=mid+1;
	}
	return r;
}
inline LL find(LL l,LL r,LL x,int opt)
{
	if(l+1==r)return l;
	LL mid=((l+r)>>1),l1=((l+mid)>>1),r1=((r+mid)>>1),len=l1-l,y=x+l-1,ans;
	if(opt==1)
	{
		if(y<l1)ans=find(l,l1,(x-1)%len+1,opt);
		else if(y<mid)ans=find(l1,mid,(x-1)%len+1,opt);
		else if(y<r1)ans=find(mid,r1,(x-1)%len+1,opt);
		else ans=find(r1,r,(x-1)%len+1,opt);
	}
	else if(opt==2)
	{
		if(y<l1)ans=find(l,l1,(x-1)%len+1,opt);
		else if(y<mid)ans=find(mid,r1,(x-1)%len+1,opt);
		else if(y<r1)ans=find(r1,r,(x-1)%len+1,opt);
		else ans=find(l1,mid,(x-1)%len+1,opt);
	}
	else
	{
		if(y<l1)ans=find(l,l1,(x-1)%len+1,opt);
		else if(y<mid)ans=find(r1,r,(x-1)%len+1,opt);
		else if(y<r1)ans=find(l1,mid,(x-1)%len+1,opt);
		else ans=find(mid,r1,(x-1)%len+1,opt);
	}
	return ans;
}
int main()
{
	scanf("%d",&Test_num),pw[0]=1;
	for(int i=1;i<=Mx;++i)pw[i]=(pw[i-1]<<2);
	while(Test_num--)
	{
		scanf("%lld",&n),k=type(n),l=pw[k],r=pw[k+1],l1=(l*2+r)/3,r1=(l+r*2)/3;
		if(n%3==1)ans=find(l,l1,(n-pw[k])/3+1,1);
		else if(n%3==2)ans=find(l1,r1,(n-pw[k])/3+1,2);
		else ans=find(r1,r,(n-pw[k])/3+1,3);
		printf("%lld\n",ans);
	}
	return 0;
}