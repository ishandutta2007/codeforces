#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,a[N];
ll b[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		ll mn=0,mn1=1e18;
		ll ans=0;
		for(int i=1;i<=n;++i){
			b[i]=b[i-1]+a[i];
			if(i!=n)ans=max(ans,b[i]-mn);
			else ans=max(ans,b[i]-mn1);
			mn=min(mn,b[i]);
			mn1=min(mn1,b[i]);
		}
		if(b[n]>ans)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}