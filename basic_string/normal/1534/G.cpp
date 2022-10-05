#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
pair<int,int>a[800009];
priority_queue<int>ql,qr;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,i,d=0,l,r,x;
	long long ans=0;
	for(cin>>n,i=1;i<=n;++i)cin>>a[i].se>>a[i].fi,a[i].fi+=a[i].se;
	sort(a+1,a+n+1),ql.push(a[1].se),qr.push(-a[1].se);
	for(i=2;i<=n;++i){
		d+=a[i].fi-a[i-1].fi,l=ql.top(),r=d-qr.top(),x=a[i].se;
		if(x<l)ql.pop(),qr.push(d-l),ql.push(x),ql.push(x),ans+=l-x;
		else if(x>r)qr.pop(),ql.push(r),qr.push(d-x),qr.push(d-x),ans+=x-r;
		else ql.push(x),qr.push(d-x);
	}
	cout<<ans;
	return 0;
}