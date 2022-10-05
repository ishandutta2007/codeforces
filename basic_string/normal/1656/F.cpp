#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
using ll=long long;
int a[N];
ll K,B;
ll cal(int x){
	return K*x+B;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,i,j,k,n;
	ll s,ans;
	for(cin>>T;T--;){
		cin>>n,s=0;
		for(i=1;i<=n;++i)cin>>a[i],s+=a[i];
		sort(a+1,a+n+1);
		if(s+a[1]*(n-2ll)>0){cout<<"INF\n";continue;}
		if(s+a[n]*(n-2ll)<0){cout<<"INF\n";continue;}
		K=B=0;
		for(i=1;i<n;++i)K+=a[i]+a[n],B+=a[i]*1ll*a[n];
		ans=-1e18;
		if(n==2)ans=cal(0);
		for(i=n-1;i>1;--i){
			K-=a[i]+a[n],B-=a[i]*1ll*a[n];
			K+=a[i]+a[1],B+=a[i]*1ll*a[1];
			ans=max(ans,cal(-a[i]));
		}
		cout<<ans<<'\n';
	}
}/*
t=-inf->mx
t=inf->mn
a*mx+t(a+mx)=a*mn+t(a+mn)
a*(mx-mn)=t*(mn-mx)
t=-a
a*mx+t(a+mx)
a*mn+t(a+mn)*/
/*
1 2 3 -4
1 -4
2 -4
3 -4
-6t-24
3 -4
3 1
3 2
8t-3
-6t-24=8t-3
-14t=21
t=-1.5
3 -1
3 -2
-9
2
1
-9+3t
-2 3
-2 -1
-4-2t=-9+3t
9-4=5t
t=1*/