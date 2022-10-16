#include<bits/stdc++.h>
using namespace std;
int p,q,l,r,a,b,c,d,ans,x[2005],y[2005],z[2005];
int main()
{
	cin>>p>>q>>l>>r;
	for(int i=1;i<=p;i++){
		cin>>a>>b;
		for(int j=a;j<=b;j++)
			x[j]=1;
	}
	for(int i=1;i<=q;i++){
		cin>>c>>d;
		for(int j=c;j<=d;j++)
			y[j]=1;
	}
	for(int i=l;i<=r;i++){
		int pd=0;
		memset(z,0,sizeof(z));
		for(int j=0;j<1001;j++)
			z[j+i]=y[j];
		for(int j=0;j<2001;j++)
			pd=pd|(z[j]&x[j]);
		ans+=pd;
	}
	cout<<ans;
	return 0;
}