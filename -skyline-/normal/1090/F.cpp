#include<bits/stdc++.h>
#define ll      long long
#define pb      push_back
#define mp      make_pair
#define orz     1000000007
using namespace std;
ll n,a[1005];
ll ask(ll a,ll b,ll c){
	ll ret;
	cout<<"? "<<a<<' '<<b<<' '<<c<<endl;
	cin>>ret;
	return ret;
}
ll get(ll a,ll b,ll c,ll d){
	ll A=ask(b,c,d),B=ask(a,c,d),C=ask(a,b,d),D=ask(a,b,c);
	return min(min(A,B),min(C,D))+max(max(A,B),max(C,D));
}
int main(){
	cin>>n;
	ll A=get(2,3,4,5),B=get(1,3,4,5),C=get(1,2,4,5),D=get(1,2,3,5),E=get(1,2,3,4),o=(A+B+C+D+E)/4;
	a[1]=o-A,a[2]=o-B,a[3]=o-C,a[4]=o-D,a[5]=o-E;
	for(ll i=6;i<=n;++i)a[i]=get(1,2,3,i)-a[1]-a[2]-a[3];
	cout<<'!';
	for(ll i=1;i<=n;++i)cout<<' '<<a[i];
	cout<<endl;
	return 0;
}