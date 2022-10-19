#include<bits/stdc++.h>
#define Mx 1000000
using namespace std;
int vec_t=2,l,r,mid,Test_num,a=4,b=5,n,ans;int vec[42];
inline void init()
{
	vec[1]=1,vec[2]=2;
	while(b<=Mx)vec[++vec_t]=min(a,b),vec[++vec_t]=max(a,b),b+=a+1,a+=a+1,swap(a,b);
}
int main()
{
	for(init(),scanf("%d",&n),ans=0,l=1,r=vec_t;l<=r;)
	{
		mid=((l+r)>>1);
		if(vec[mid]==n)
		{
			ans=1;
			break;
		}
		if(vec[mid]>n)r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}