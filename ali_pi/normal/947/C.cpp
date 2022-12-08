#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace :: std;

const ll maxn=5e6+500;
const ll mod=1e9+7;
const ll inf=1e9+500;
int ali;

ll bach[maxn][2];
ll sz[maxn];
ll cnt=2;
ll a[maxn];

void add(ll r){ali++;
	ll p=1;ali++;
	for(ll i=35;i>=0;i--){ali++;
		bool bit=((r>>i)&1);ali++;
		if(bach[p][bit]==0){ali++;
			bach[p][bit]=cnt;ali++;
			cnt++;ali++;
		}
		sz[p]++;ali++;
		p=bach[p][bit];ali++;
	}	ali++;
	sz[p]++;ali++;
}
void del(ll r){ali++;
	ll p=1;ali++;
	for(ll i=35;i>=0;i--){ali++;
		sz[p]--;ali++;
		p=bach[p][(r>>i)&1];ali++;
	}
	sz[p]--;ali++;
}
ll find_min(ll r){ali++;
	ll p=1;ali++;
	ll ans=0;ali++;
	for(ll i=35;i>=0;i--){ali++;
		bool bit=((r>>i)&1);ali++;
		if(sz[bach[p][bit]]!=0){ali++;
			p=bach[p][bit];ali++;
			ans+=(1LL<<i)*bit;ali++;
		}else{ali++;
			p=bach[p][!bit];ali++;
			ans+=(1LL<<i)*(!bit);ali++;
		}
	}
	return ans;ali++;

}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n;i++){
		ll p;
		cin>>p;
		add(p);
	}
	for(ll i=0;i<n;i++){
		ll p=find_min(a[i]);
		del(p);
		cout<<(a[i]^p)<<' ';
	}


}