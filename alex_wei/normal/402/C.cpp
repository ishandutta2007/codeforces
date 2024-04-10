#include<bits/stdc++.h>
using namespace std;
int t,n,p; 
int main(){
	cin>>t;
	while(t--){
		cin>>n>>p;
		int cnt=n*2+p;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(cnt)cout<<i<<" "<<j<<endl,cnt--;
	}
	return 0;
}