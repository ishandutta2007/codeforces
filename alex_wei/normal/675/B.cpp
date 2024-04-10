#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a,b,c,d,e,f,g,h,ans; 
int main()
{
	cin>>n>>a>>b>>c>>d;
	for(int i=1;i<=n;i++){
		e=i,f=b+i-c,g=a+i-d,h=a+b+i-c-d;
		if(f>0&&g>0&&h>0&&f<=n&&g<=n&&h<=n)
			ans+=n;
	}
	cout<<ans<<endl;
	return 0;
}