#include<bits/stdc++.h>
#define eps 1e-15
using namespace std;
int n,t,ans=0;
double a[12][12];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(t),a[1][1]=t;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			if(a[i][j]>=1)
				++ans,a[i][j]-=1,a[i+1][j]+=a[i][j]/2,a[i+1][j+1]+=a[i][j]/2;
	printf("%d",ans);
	return 0;
}