#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
ll a[200010];
ll n;
int main(){
	//ios_base::sync_with_stdio(false);
	cin>>n;
	rep(i,0,n){
		cin>>a[i];
		a[i]=a[i]<0;
	}
	ll ans1,ans2,now1,now2;
	ans1=ans2=now1=now2=0;
	rep(i,0,n){
		if(a[i])swap(now1,now2);
		if(a[i])now1++;
		else now2++;
		ans1+=now1;
		ans2+=now2;
	}
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}