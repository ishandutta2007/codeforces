#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int gt(int x){
	cout<<"? "<<x<<endl;
	cin>>x;
	return x;
}
int main()
{
	int n,l,r,h,x,y;
	cin>>n;
	l=1,r=n;
	while(l<r){
		h=l+r>>1;
		x=gt(h);
		y=gt(h+1);
		if(x<y)
			r=h;
		else
			l=h+1;
	}
	cout<<"! "<<l<<endl;
	return 0;
}