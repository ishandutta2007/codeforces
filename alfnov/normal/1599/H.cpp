#include<bits/stdc++.h>
#define bn 1000000000
using namespace std;
int main()
{
	int apb,cpd,bmc,xw,ZB,YB;
	cout<<"? "<<1<<" "<<1<<endl;
	cin>>xw;
	ZB=xw;
	apb=1+1+xw;
	cout<<"? "<<bn<<" "<<1<<endl;
	cin>>xw;
	YB=xw;
	bmc=1-bn+xw;
	cout<<"? "<<bn<<" "<<bn<<endl;
	cin>>xw;
	cpd=bn+bn-xw;
	int L=1,R=bn,ans=-1;
	while(L<=R)
	{
		int mid=L+R>>1;
		cout<<"? "<<mid<<" "<<1<<endl;
		cin>>xw;
		if(ZB-xw==mid-1)L=mid+1;
		else if(YB-xw==bn-mid)R=mid-1;
		else
		{
			ans=xw+1;
			break;
		}
	}
	if(ans==-1)
	{
		cout<<"? "<<R<<" "<<1<<endl;
		cin>>xw;
		ans=xw+1;
	}
	int a,b,c,d;
	b=ans,a=apb-b,c=b-bmc,d=cpd-c;
	cout<<"! "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	return 0;
}