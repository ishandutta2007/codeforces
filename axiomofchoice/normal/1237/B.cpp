#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define lowbit(x) (x&(-x))
int a[100010],b[100010],c[100010],x,ans,n;
struct BIT{
	ll t[500010];//
	void init(){
		mst(t,0);
	}
	void add(ll x,ll k){//xk
		//x++;
		while(x<=n){
			t[x]+=k;
			x+=lowbit(x);
		}
	}
	ll sum(ll x){//[1,x]//[0,x]
		//x++;
		ll ans=0;
		while(x!=0){
			ans+=t[x];
			x-=lowbit(x);
		}
		return ans;
	}
}bit;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,1,n+1){
		cin>>x; a[i]=x;
	}
	repeat(i,1,n+1){
		cin>>x; b[x]=i;
	}
	repeat(i,1,n+1)c[b[a[i]]]=i;
	//repeat(i,1,n+1)cout<<c[i]<<' ';cout<<endl;
	repeat_back(i,1,n+1){
		//cout<<bit.sum(c[i])<<' ';
		bit.sum(c[i])>0?ans++:0;
		bit.add(c[i],1);
	}
	cout<<ans<<endl;
	return 0;
}