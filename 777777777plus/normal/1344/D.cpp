#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
 
int n;
ll k;
ll a[N],b[N];

ll getcnt(ll ans,bool flag){
	static bool tag[N];
	ll ret=0;
	for(int i=1;i<=n;++i){
		ll l=0,r=a[i];
		while(l!=r){
			ll mid=l+r+1>>1;
			if(a[i]-3*mid*mid>=ans)l=mid;
			else r=mid-1;
		}
		if(a[i]-3*l*l==ans)tag[i]=1;
		else tag[i]=0;
		b[i]=l;
		ret+=l;
	}
	if(!flag)return ret;
	for(int i=1;i<=n;++i)
	if(tag[i]&&ret>k){
		b[i]--;
		ret--;
	}
	for(int i=1;i<=n;++i)printf("%lld ",b[i]);
	printf("\n");
	return 0;
}
 
int main(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	ll l=-3e18,r=1e9;
	while(l!=r){
		ll mid=l+r+1>>1;
		if(getcnt(mid,0)>=k)l=mid;
		else r=mid-1;
	}
	getcnt(l,1);
}