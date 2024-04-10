#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll n,d,ans,pos=1,sum;
struct fri{
	ll m,s;
	bool operator < (const fri &v) const {
		return m<v.m;
	}
}e[N];
int main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)scanf("%lld%lld",&e[i].m,&e[i].s);
	sort(e+1,e+n+1);
	for(int i=1;i<=n;i++){
		sum+=e[i].s;
		while(pos<i&&e[i].m-e[pos].m>=d)sum-=e[pos++].s;
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
    return 0;
}