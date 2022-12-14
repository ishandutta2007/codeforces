#include<bits/stdc++.h>
using namespace std;
long long n,x,flag,anotherflag,ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n;
	flag=anotherflag=ans=0;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x<0)ans+=-1-x,flag^=1;
		else if(x>0)ans+=x-1;
		else ans+=1,anotherflag=1;
	}
	if(!anotherflag && flag)ans+=2;
	cout<<ans<<endl;
	return 0;
}