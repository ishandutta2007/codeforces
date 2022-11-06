#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int ans[1009],a[1009][1009];
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
signed main() 
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	ans[1]=sqrt(a[1][3]*a[1][2]/a[2][3]);
	ans[2]=sqrt(a[2][1]*a[2][3]/a[1][3]);
	for(int i=3;i<=n;i++)ans[i]=sqrt(a[1][i]*a[2][i]/a[1][2]);
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
    return 0;
}