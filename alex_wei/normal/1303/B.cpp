#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
ll n,g,b;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>g>>b;
		ll z=(n+1)/2,rep=z/g,an=z-rep*g,ans=rep*g+an+rep*b;
		if(an==0)ans-=b;
		cout<<max(ans,n)<<endl;
	}
	return 0;
}