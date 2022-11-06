//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int main()
{
	int n=read(),ans=1e9+7;
	for(int i=1;i*i<=n;i++)
		ans=min(ans,i+(n+i-1)/i);
	cout<<ans<<endl;
	return 0;
}