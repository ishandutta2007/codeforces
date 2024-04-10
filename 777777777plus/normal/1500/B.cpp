#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 1e6+5;

int n,m;
ll k;
int a[N],b[N],p[N];

ll mod[N],r[N];

ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){
		x=1,y=0;
		return a;
	}
    ll gcd=exgcd(b,a%b,x,y);
	ll tmp=x;
    x=y;
	y=tmp-a/b*y;
    return gcd;
}

ll EXCRT(){
    ll lcm=mod[1],last_r=r[1];
    ll lcm_a,x,y,k;
    for(int i=2;i<=2;++i){
        lcm_a=((r[i]-last_r)%mod[i]+mod[i]);
		k=lcm;
        ll gcd=exgcd(lcm,mod[i],x,y);
        x=(x*lcm_a/gcd%(mod[i]/gcd)+(mod[i]/gcd))%(mod[i]/gcd);
        lcm=lcm*mod[i]/gcd;
		last_r=(last_r+k*x)%lcm;
    }
    return (last_r%lcm+lcm)%lcm;
}

vector<ll> v;

int main(){
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),p[a[i]]=i;
	for(int i=1;i<=m;++i){
		scanf("%d",&b[i]);
		int j=p[b[i]];
		if(!j)continue;
		mod[1]=n;r[1]=j-1;
		mod[2]=m;r[2]=i-1;
		ll res=EXCRT();
		if(res%mod[1]==r[1]&&res%mod[2]==r[2])v.push_back(res);
	}
	sort(v.begin(),v.end());
	ll lcm=1ll*n*m/__gcd(n,m);
	ll ans;
	ll l=1,r=1e18;
	while(l!=r){
		ll mid=l+r>>1;
		ll res=mid/lcm*v.size();
		for(int i=0;i<v.size();++i)
		if(v[i]<mid%lcm)++res;
		if(mid-res>=k)r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}