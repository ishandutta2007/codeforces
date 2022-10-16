#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,ans;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
				int z=i;
				for(int k=1;k<j;k++)z=z*10+i;
				ans+=n>=z;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
    return 0;
}