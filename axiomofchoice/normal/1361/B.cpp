#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define fi first
#define se second
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
typedef long long ll;
#define int ll
const int N=1000010; const int inf=~0u>>2; 
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
int a[N];
int T,n,p;
int ans,dif,nowpos;
void move_pos(int x){
	(ans*=qpow(p,nowpos-x))%=mod;
	if(dif){
		repeat(i,0,nowpos-x){
			dif=max(min(dif*p,N),-N);
			if(abs(dif)==N)break;
		}
	}
	nowpos=x;
}
void push(int x){//orz(x);
	move_pos(x);
	if(dif>0)ans--,dif--;
	else ans++,dif++;
}
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>p;
		repeat(i,0,n)
			cin>>a[i];
		if(p==1){cout<<n%2<<endl; continue;}
		sort(a,a+n,greater<int>());
		ans=dif=0; nowpos=N;
		repeat(i,0,n)
			push(a[i]);
		move_pos(0);
		cout<<(ans%mod+mod)%mod<<endl;
	}
	return 0;
}