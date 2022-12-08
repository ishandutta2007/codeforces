#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e3+5;

ll a,b,c,d,e,f,ans;

int main(){
	cin>>a>>b>>c>>d>>e>>f;
	for(ll i=0;i<=min(a,d);++i){
		a-=i;d-=i;
		ans=max(ans,i*e+min(b,min(c,d))*f);
		a+=i;d+=i;
	}
	cout<<ans<<endl;
}