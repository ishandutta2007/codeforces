#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,b,p,f,h,c; 
int main()
{
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>b>>p>>f>>h>>c;
		int ans=0;
		for(int j=0;j<=100;j++)
			for(int k=0;k<=100;k++)
				if(j*2+k*2<=b&&j<=p&&k<=f)
					ans=max(ans,j*h+k*c);
		cout<<ans<<endl;
	}
    return 0;
}