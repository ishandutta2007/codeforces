#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,a,b,c; 
int main()
{
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a>>b>>c;
		int ans=0;
		for(int j=0;j<100;j++)
			for(int k=0;k<100;k++){
				int ca=j,cb=j*2+k,cc=k*2;
				if(a>=ca&&b>=cb&&c>=cc)
					ans=max(ans,j*3+k*3);
			}
		cout<<ans<<endl;
	}
    return 0;
}