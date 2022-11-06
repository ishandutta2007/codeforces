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
int n,sx,sy,ans,x,y,u,dow,lef,righ;
int main()
{
	n=read(),sx=read(),sy=read();
	for(int i=1;i<=n;i++)
	{
		x=read(),y=read();
		if(x<sx)lef++;
		if(x>sx)righ++;
		if(y<sy)dow++;
		if(y>sy)u++;
	}
	ans=max(max(lef,righ),max(dow,u));
	cout<<ans<<endl;
	if(ans==lef&&sx>=1)cout<<sx-1<<" "<<sy<<endl;
	else if(ans==righ&&sx<=1e9)cout<<sx+1<<" "<<sy<<endl;
	else if(ans==u&&sy>=1)cout<<sx<<" "<<sy+1<<endl;
	else cout<<sx<<" "<<sy-1<<endl;
	return 0;
}