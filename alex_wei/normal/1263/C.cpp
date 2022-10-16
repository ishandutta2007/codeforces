#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,ans,c[1000005],ap[1000005];
int main()
{
	cin>>t;
	while(t--){
		memset(ap,0,sizeof(ap));
		cin>>n;
		ans=0;
		for(int i=0;i<=sqrt(n);i++)
			c[++ans]=i;
		for(int i=sqrt(n);i>0;i--){
			int cal=n/i;
			if(cal!=c[ans])
				c[++ans]=cal;
		}
		cout<<ans<<endl;
		for(int i=1;i<=ans;i++)
			cout<<c[i]<<" ";
		cout<<endl;
	}
    return 0;
}