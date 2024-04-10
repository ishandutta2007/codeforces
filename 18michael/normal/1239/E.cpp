#include<bits/stdc++.h>
using namespace std;
int n,n1,sum=0;
bitset<1200002> bs[25];
vector<int> vec1,vec2;
struct aaa
{
	int x,y;
}a[52];
inline bool cmp(aaa a,aaa b)
{
	return a.x<b.x? 1:0;
}
int main()
{
	scanf("%d",&n),n1=n-1,n<<=1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i].x),a[i].y=i,sum+=a[i].x;
	sort(a+1,a+n+1,cmp),bs[0][0]=1,sum=(sum-a[1].x-a[2].x)/2;
	for(int i=3;i<=n;++i)for(int j=n1;j;--j)bs[j]|=(bs[j-1]<<a[i].x);
	for(int i=sum;~i;--i)
		if(bs[n1][i])
		{
			for(int j=3;j<=n;++j)
			{
				if(n1 && a[j].x<=i && bs[n1-1][i-a[j].x])vec1.push_back(a[j].x),--n1,i-=a[j].x;
				else vec2.push_back(a[j].x);
			}
			break;
		}
	printf("%d",a[1].x);for(int i=0;i<vec1.size();++i)printf(" %d",vec1[i]);
	puts("");for(int i=vec2.size()-1;~i;--i)printf("%d ",vec2[i]);
	return 0&printf("%d",a[2].x);
}