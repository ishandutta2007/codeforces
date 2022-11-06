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
int n,a[100009],mn,mx,x,y,z,ans,xx,yy,zz,ansx,ansy,ansz;
int main()
{
	n=read();mn=200001;
	for(int i=1;i<=n;i++)a[i]=read()+100000,mn=min(mn,a[i]),mx=max(mx,a[i]);
	if(mx-mn<=1)
	{
		cout<<n<<endl;
		for(int i=1;i<=n;i++)printf("%d ",a[i]-100000);
		return 0;
	}
	else if(mx-mn==2)
	{
		ans=1e9+7;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==mn)x++;
			else if(a[i]==mx)z++;
			else y++;
		}
		for(int i=1;i<=y/2;i++)
		{
			yy=y-i*2,xx=x+i,zz=z+i;
			if(ans>min(xx,x)+min(yy,y)+min(zz,z))ansx=xx,ansy=yy,ansz=zz,ans=min(xx,x)+min(yy,y)+min(zz,z);
		}
		for(int i=1;i<=min(x,z);i++)
		{
			xx=x-i,zz=z-i,yy=y+i*2;
			if(ans>min(xx,x)+min(yy,y)+min(zz,z))ansx=xx,ansy=yy,ansz=zz,ans=min(xx,x)+min(yy,y)+min(zz,z);
		}
		cout<<ans<<endl;
		for(int i=1;i<=ansx;i++)printf("%d ",mn-100000);
		for(int i=1;i<=ansy;i++)printf("%d ",mn-100000+1);
		for(int i=1;i<=ansz;i++)printf("%d ",mn-100000+2);
		return 0;
	}
	cout<<"zhouakngyang ak IOI"<<endl;
	return 0;
}