#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#include<queue>
//#define P 998244353
using namespace std;
int n,p,q,r,a[100001],nx,ny,ans=999999999999999999;
signed main(){
//	srand(time(0));
	cin>>n>>p>>q>>r;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) ny+=a[i]-a[1];
	ans=ny*q;
	for(int i=2;i<=n;i++){
		if(nx<ny&&nx+(i-1)*(a[i]-a[i-1])>ny-(n-i+1)*(a[i]-a[i-1])&&p+q>r){
			int nk=(ny-nx)/n;
			for(int j=max(a[i-1],a[i-1]+nk-(n+2)/2);j<=min(a[i],a[i-1]+nk+(n+2)/2);j++){
				int px=nx+(j-a[i-1])*(i-1),py=ny-(j-a[i-1])*(n-i+1);
				if(px>py) ans=min(ans,py*r+(px-py)*p);
				else ans=min(ans,px*r+(py-px)*q);
			}
		}
		nx+=(i-1)*(a[i]-a[i-1]);
		ny-=(n-i+1)*(a[i]-a[i-1]);
		if(p+q<=r) ans=min(ans,nx*p+ny*q);
		else if(nx>ny) ans=min(ans,ny*r+(nx-ny)*p);
		else ans=min(ans,nx*r+(ny-nx)*q);
	}
	printf("%lld\n",ans);
	return 0;
}
/*

*/