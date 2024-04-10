#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lowbit(ll x){return x&-x;}
ll n,s[200002],arr[200002],c[200002];
void add(ll pos,ll x){while(pos<=n)c[pos]+=x,pos+=lowbit(pos);}
ll sum(int x){ll ans=0;while(x){ans+=c[x],x-=lowbit(x);}return ans;}
ll ef(ll l,ll r,ll x)
{
	if(l==r)return l;
	ll m=l+r>>1;
	if(sum(m)<=x)return ef(m+1,r,x);
	return ef(l,m,x);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i],add(i+1,i);
	for(int i=n;i>0;i--){
//		for(int j=1;j<=n;j++)
//			cout<<sum(j)<<" ";
//		cout<<endl;
		ll pos=ef(1,n+1,s[i])-1;
		add(pos+1,-pos);
		arr[i]=pos;
	}
	for(int i=1;i<=n;i++)
		cout<<arr[i]<<" ";
    return 0;
}