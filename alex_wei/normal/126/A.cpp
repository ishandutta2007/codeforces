#include<bits/stdc++.h>
using namespace std;
double ans,yy1,y2,a1,a2,t0,t1,t2,x1,x2;
int main()
{
	cin>>t1>>t2>>x1>>x2>>t0,yy1=x1,y2=x2,ans=1e18;
	while(yy1+y2>=0){
		double temp=((t1*yy1)+(t2*y2))/(yy1+y2);
		if(temp<t0)yy1--;
		else{
			if(temp<ans)
				ans=temp,a1=yy1,a2=y2;
			y2--;
		}
	}
	int mul=min(x1/a1,x2/a2);
	cout<<(int)(a1*mul)<<" "<<(int)(a2*mul);
	return 0; 
}