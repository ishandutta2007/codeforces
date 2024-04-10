#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,r,avg,s,ans;
struct exam{
	ll a,b;
	bool operator < (const exam &v) const {
		return b<v.b;
	}
}e[100005];
int main(){
	cin>>n>>r>>avg;
	for(int i=1;i<=n;i++)
		cin>>e[i].a>>e[i].b,s+=e[i].a;
	sort(e+1,e+n+1);
	if(avg*n<=s)puts("0"),exit(0);
	for(int i=1;i<=n;i++){
		ll w=min(avg*n-s,r-e[i].a);
		ans+=w*e[i].b,s+=w;
	}
	cout<<ans<<endl;
    return 0;
}