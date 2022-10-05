#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e6+12,inf=1e9,LOG=18,mod=1e9+7,N=8*9*5*7*11*13;
ll n,x;
bool prime(ll x){
	for(int i=2;i*i<=n;i++)
		if(x%i==0)
			return 0;
	return 1;
}
ll binpow(ll x,ll p){
	if(p==0)
		return 1;
	ll c=binpow(x,p/2);
	if(p%2==0)       
		return c*c%n;
	return c*c%n*x%n;
}
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
 	#endif
	cin>>n;
	if(n==1)
		return cout<<"YES"<<endl<<1<<endl,0;
	if(n==4)
		return cout<<"YES"<<endl<<1<<endl<<3<<endl<<2<<endl<<4<<endl,0;
	if( !prime(n) )
		return cout<<"NO",0;
	cout<<"YES"<<endl;
	cout<<1<<endl;
	// x*c=n  c=n/x
	// 2*6=3
    for(int i=2;i<n;i++)
		cout<<i*binpow(i-1,n-2)%n<<endl;
	cout<<n<<endl;
}