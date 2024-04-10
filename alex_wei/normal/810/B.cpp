#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll k,l;
	bool operator < (const node &v) const {
		return min(k*2,l)-min(k,l)>min(v.k*2,v.l)-min(v.k,v.l);
	}
}c[100005];
ll n,f,ans;
int main()
{
	cin>>n>>f;
	for(int i=1;i<=n;i++)
		cin>>c[i].k>>c[i].l;
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)
		ans+=min(c[i].l,i<=f?c[i].k*2:c[i].k);
	cout<<ans;
    return 0;
}