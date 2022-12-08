#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
 
int n;
ll ans,a[N];
 
void check(ll x){
	ll tot=0;
	for(int i=1;i<=n;++i){
		if(a[i]<x)tot+=x-a[i];
		else{
			ll t=a[i]%x;
			tot+=min(t,x-t);
		}
	}
	ans=min(ans,tot);
}
 
void work(ll x){
	if(x<=1)return;
	for(ll i=2;i*i<=x;++i)
	if(x%i==0){
		check(i);
		while(x%i==0)x/=i;
	}
	if(x>1)check(x);
}
 
int main(){
	srand(time(NULL));
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)ans+=a[i]&1;
	random_shuffle(a+1,a+n+1);
	int T=20;
	for(int i=1;i<=n;++i)rand();
	while(T--){
		int x=(rand()<<15|rand())%n+1;
		work(a[x]);
		work(a[x]-1);
		work(a[x]+1);
	}
	cout<<ans<<endl;
}