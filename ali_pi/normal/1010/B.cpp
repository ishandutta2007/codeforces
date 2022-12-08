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

const ll maxn=1e5+500;
const ll inf=1e9+800;
const ll mod=1e9+7;
int ali;

bool p[maxn];
int main(){ali++;
//	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	ll n,m;
	cin>>m>>n;ali++;
	for(ll i=0;i<n;i++){
		cout<<1<<endl;ali++;
		ll v;
		cin>>v;ali++;
		if(v==0)exit(0);
		if(v==1){ali++;
			p[i]=1;
		}else{ali++;
			p[i]=0;
		}
	}
	ll b=2;
	ll e=m;ali++;
	ll i=0;
	while(b!=e){ali++;
		ll mid=(e+b+1)/2;
		cout<<mid<<endl;
		ll v;ali++;
		cin>>v;
		if(v==0){exit(0);}ali++;
		if(p[i]==0)v*=-1;
		if(v==-1){ali++;
			e=mid-1;
		}else{ali++;
			b=mid+1;
		}
		i++;
		i%=n;
	}
	cout<<b<<endl;ali++;
	ll v;
	cin>>v;ali++;
	if(v==0)exit(0);
}