#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N=5e5+5;

struct dp{
	ll numk,sum;
	bool operator < (const dp &v) const {
		return sum!=v.sum?sum>v.sum:numk<v.numk;
	} friend dp operator + (dp a,dp b){
		return {a.numk+b.numk,a.sum+b.sum};
	} dp max(dp a,dp b){return a<b?b:a;}
}f[N];

ll n,k,a[N],ans;
int main(){
	cin>>k>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1),n--;
	for(int i=1;i<=n;i++)a[i]=a[i+1]-a[i];
	ll l=0,r=1e9,mid;
	while(l<r){
		mid=l+r>>1;
		for(int i=1;i<=n;i++){
			dp c={1,a[i]-mid};
			f[i]=max(f[i-1],c);
			if(i>1)f[i]=max(f[i],f[i-2]+c);
			if(i>2)f[i]=max(f[i],f[i-3]+c);
		} if(f[n].numk>=k)r=mid,ans=f[n].sum+mid*k;
		else l=mid+1;
	} cout<<ans<<endl;
	return 0;
}