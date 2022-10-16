#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n;
struct node{
	int a,t;
	bool operator < (const node &v) const {
		return a<v.a||a==v.a&&t>v.t;
	}
}c[N];
ll ans;
struct key{
	ll val,pos;
	bool operator < (const key &v) const {
		return val<v.val;
	}
};
priority_queue <key> p;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>c[i].a;
	for(int i=1;i<=n;i++)cin>>c[i].t;
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		for(ll j=c[i-1].a;j<c[i].a;j++){
			if(p.empty())break;
			key z=p.top();
			ans+=(j-z.pos)*z.val;
			p.pop();
		}
		p.push({c[i].t,c[i].a});
	}
	ll pos=c[n].a;
	while(p.size()){
		key z=p.top(); p.pop();
		ans+=(pos-z.pos)*z.val;
		pos++;
	}
	cout<<ans<<endl;
	return 0;
}