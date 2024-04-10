#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[200100];
map<ll,ll,greater<ll> >mp;
void chmx(ll&x,ll y){if(x<y)x=y;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),a[n+1]=1;
	mp[a[1]-1]=0;
	for(int i=1;i<=n;i++)for(auto it=mp.begin();it!=mp.end();it=mp.erase(it)){
		if(it->first<a[i+1])break;
		chmx(mp[it->first%a[i+1]],it->second+it->first*i-it->first%a[i+1]*i);
		chmx(mp[a[i+1]-1],it->second+((it->first+1)/a[i+1]-1)*a[i+1]*i);
	}
	printf("%lld\n",mp[0]);
	return 0;
}