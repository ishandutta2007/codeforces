#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n,b[N];
ll cnt[N<<2];

int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>b[i];
		cnt[b[i]-i+n]+=b[i];
	}
	ll ans=*max_element(cnt,cnt+600000+5);
	cout<<ans<<endl;
}