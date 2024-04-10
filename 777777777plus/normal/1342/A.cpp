#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
ll x,y,a,b;

int main(){
	cin>>T;
	while(T--){
		cin>>x>>y;
		cin>>a>>b;
		ll ans=min(abs(x)*b+abs(x-y)*a,abs(y)*b+abs(x-y)*a);
		ans=min(ans,abs(x)*a+abs(y)*a);
		cout<<ans<<endl;
	}
}