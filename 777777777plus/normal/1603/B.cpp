#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int T;
ll x,y;

int main(){
	cin>>T;
	while(T--){
		cin>>x>>y;
		ll ans;
		if(x>y)ans=x+y;
		else if(y<3*x)ans=(x+y)/2;
		else if(y%x==0)ans=x;
		else{
			ll t=(x+y)/2;
			ll l=0,r=1e9;
			while(l!=r){
				ll mid=l+r+1>>1;
				if(mid*x+t<y)l=mid;
				else r=mid-1;
			}
			t+=l*x;
			ans=t;
		}
		cout<<ans<<endl;
	}
}