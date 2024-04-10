#include<bits/stdc++.h>
using namespace std;
int p1,p2,p3,t1,t2,ans,l[102],r[102],n;
int main()
{
	cin>>n>>p1>>p2>>p3>>t1>>t2;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		ans+=(r[i]-l[i])*p1;
		if(i==1)continue;
		int k=l[i]-r[i-1];
		if(k>=t1){
			ans+=t1*p1;
			k-=t1;
			if(k>=t2)ans+=t2*p2+p3*(k-t2);
			else ans+=k*p2;
		}
		else ans+=k*p1;
	}
	cout<<ans;
	return 0;
}