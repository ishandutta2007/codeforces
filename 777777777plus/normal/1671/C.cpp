#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int n,x,a[200005];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>x;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+n+1);
		ll sum=0;
		for(int i=1;i<=n;++i)sum+=a[i];
		ll ans=0;
		ll lastday=-1;
		for(int i=n;i>=1;--i){
			ll maxday=(x-sum)/i;
			if(x>=sum&&maxday>lastday){
				ans+=(maxday-lastday)*i;
				lastday=maxday;
			}
			sum-=a[i]; 
		}
		cout<<ans<<endl;
	}
}