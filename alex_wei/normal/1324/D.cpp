#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,e[200005],ans,a[200005],b[200005],d[200005];
int c[200005];
void add(int x){
	while(x<=n){
		c[x]++;
		x+=x&-x;
	}
}
int query(int x){
	int ans=0;
	while(x){
		ans+=c[x];
		x-=x&-x;
	}
	return ans;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i],d[i]=b[i]-a[i],e[i]=b[i]-a[i];
	sort(e+1,e+n+1);
	for(int i=n-1;i;i--){
		int pos=lower_bound(e+1,e+n+1,d[i+1])-e;
		add(pos);
		int p2=lower_bound(e+1,e+n+1,a[i]-b[i])-e-1;
		ans+=query(p2);
	}
	cout<<ans<<endl;
    return 0;
}