#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,x,y,ans; 
int main()
{
	cin>>n>>m>>x>>y>>k;
	for(int i=1;i<=k;i++){
		ll a,b;
		cin>>a>>b;
		ll j=min(!a?(ll)1e9:((a<0?1:n)-x)/a,!b?(ll)1e9:((b<0?1:m)-y)/b);
		ans+=j,x+=j*a,y+=j*b;
	}
	cout<<ans;
    return 0;
}