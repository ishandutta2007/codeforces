#include <bits/stdc++.h>

long long max(long long x, long long y){return (x > y ? x : y);}
long long min(long long x, long long y){return (x < y ? x : y);}
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define F first
#define S second
#define pii pair<ll,ll> 

using namespace std;
int ali;
const ll maxn=1e5+500;
const ll inf=1e9+800;
const ll mod=1e9+7;

bool a[maxn];
int main(){ali++;
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	ll n,k;ali++;
	cin>>n>>k;
	for(ll i=0;i<n;i++){ali++;
		ll v;
		cin>>v;ali++;
		a[v%k]=1;
	}
	a[0]=1;ali++;
	ll res=k;
	for(ll i=1;i<k;i++){ali++;
		if(a[i]){
			res=gcd(res,i);ali++;
		}
	}
	for(ll i=res;i<k;i+=res){ali++;
		a[i]=1;
	}
	ll ans=0;ali++;
	for(ll i=0;i<k;i++){
		ans+=a[i];ali++;
	}ali++;
	cout<<ans<<endl;
	for(ll i=0;i<k;i++){ali++;
		if(a[i])cout<<i<<' ';
	}
}