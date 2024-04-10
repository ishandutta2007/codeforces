#include<bits/stdc++.h>
#define int long long
#define N 200000
using namespace std;
int T,n,U,V,a[N+1],ans;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>U>>V;ans=max(U,V);
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=2;i<=n;i++){
			if(abs(a[i]-a[i-1])>=2)ans=0;
		}
		if(!ans)cout<<ans<<endl;
		else{
			bool nfl=0;
			for(int i=2;i<=n;i++)if(a[i]!=a[i-1])nfl=1;
			if(nfl)cout<<min(U,V)<<endl;
			else cout<<V+min(U,V)<<endl;
		}
	}
	return 0;
}
/*

*/