#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;


int T;
ll n;

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		ll r=n%3;
		n=(n-1)/3+1;
		ll w=0;
		for(ll i=0,n1=n;i<=30;++i)
		if(n1>(1ll<<2*i)){
			w+=(1ll<<2*i+1);
			n1-=(1ll<<2*i);
		}
		n+=w;
		ll x=0;
		for(int i=30;~i;--i)
		if(n&(1ll<<2*i)){
			ll cnt=(n^(1ll<<2*i));
			x=(1ll<<2*i+1);
			for(int j=0;j<=60;++j){
				ll w=(1ll<<2+(j/2)*2);
				if(j%2==0){
					if(cnt%w>=(w>>1)){
						x|=1ll<<j;
					}
				}
				else{
					if(cnt%w>=(w>>2)&&cnt%w<(w>>1)+(w>>2)){
						x|=1ll<<j;
					}
				}
			}
			break;
		}
		if(r==1)cout<<n<<endl;
		else if(r==2)cout<<x<<endl;
		else cout<<(n^x)<<endl;
	}
}