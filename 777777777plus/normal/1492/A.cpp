#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int T;
ll p,a,b,c;
 
int main(){
	cin>>T;
	while(T--){
		cin>>p>>a>>b>>c;
		ll ans=2e18;
		ans=min(ans,a-p%a);
		ans=min(ans,b-p%b);
		ans=min(ans,c-p%c);
		if(p%a==0||p%b==0||p%c==0)ans=0;
		cout<<ans<<endl;
	}
}