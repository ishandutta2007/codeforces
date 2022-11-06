//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,l1,r1,l2,r2;
signed main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		l1=read(),r1=read(),l2=read(),r2=read();
		cout<<l1<<" ";
		if(l2!=l1)cout<<l2<<endl;
		else cout<<r2<<endl;
	}
	return 0;
}