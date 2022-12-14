#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef long long lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=1000010;
const int inf=1e9;
const int mod=998244353;
#define int ll
int n,x;
vector<int> a[N];
int cnt[N],inv[N];
map<int,int> m;
ll qpow(ll a,ll b,ll mod){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod; //slow
		a=a*a%mod; //slow
		b>>=1;
	}
	return ans;
}

ll getinv(ll n,ll mod){ //mod!!
	return qpow(n,mod-2,mod);
}
void get_inv(){//cnt[1..n]inv[1..n]
	static int pre[N]={1};
	repeat(i,1,n+1)
		pre[i]=1ll*pre[i-1]*cnt[i]%mod;
	int inv_pre=qpow(pre[n],mod-2,mod);
	repeat_back(i,1,n+1){
		inv[i]=1ll*pre[i-1]*inv_pre%mod;
		inv_pre=1ll*inv_pre*cnt[i]%mod;
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,1,n+1){
		cin>>cnt[i];
		repeat(j,0,cnt[i]){
			cin>>x;
			a[i].push_back(x);
			m[x]++;
		}
	}
	get_inv();
	int invn=getinv(n,mod);
	int invn2=invn*invn%mod;
	int ans=0;
	repeat(i,1,n+1){
		repeat(j,0,cnt[i]){
			ans=(ans+(invn2*inv[i]%mod)*m[a[i][j]])%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}