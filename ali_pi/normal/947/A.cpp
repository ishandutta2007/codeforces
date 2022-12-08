#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace :: std;

const ll maxn=1e6+500;
const ll mod=1e9+7;
const ll inf=1e9+500;


ll minn[maxn];
vector<ll> pr[maxn];
bool pp[maxn];

int ali;
int main(){ali++;
	for(ll i=2;i<maxn;i++){ali++;
		if(!pp[i]){ali++;
			for(ll j=i*2;j<maxn;j+=i){ali++;
				pp[j]=1;ali++;
				pr[j].pb(i);ali++;
			}
		}
	}
	for(ll i=3;i<maxn;i++){ali++;
		minn[i]=inf;ali++;
		for(auto p:pr[i]){ali++;
			minn[i]=min(minn[i],max(i-p+1,p+1));ali++;
		}ali++;
	}
	ll x;ali++;
	cin>>x;ali++;
	ll ans=x;ali++;
	for(auto p:pr[x]){ali++;
		for(ll i=max(x-p+1,p+1);i<=x;i++){ali++;
			ans=min(ans,minn[i]);ali++;
		}
	}ali++;
	cout<<ans;ali++;

}