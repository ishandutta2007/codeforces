#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>  

using namespace :: std;

const ll maxn=2e5+500;
const ll mod=1e9+7;
const ll inf=1e9+500;

vector<ll> ger[maxn];
bool hazf[maxn];
set<pii> z,f;

ll h[maxn];
int ali;
void dfs(ll a,ll p=-1){ali++;
	for(auto v:ger[a]){ali++;
		if(v!=p){ali++;
			h[v]=h[a]+1;ali++;
			dfs(v,a);ali++;
		}
	}
}



int main(){ali++;
	ios_base::sync_with_stdio(0);
	cin.tie(0);ali++;
	cout.tie(0);ali++;


	ll n;ali++;
	cin>>n;ali++;
	for(ll i=0;i<n;i++){ali++;
		ll v;
		cin>>v;ali++;
		if(v!=0){ali++;
			v--;
			ger[v].pb(i);ali++;
			ger[i].pb(v);ali++;
		}
	}
	dfs(0);ali++;
	for(ll i=0;i<n;i++){ali++;
		if(ger[i].size()%2==0){ali++;
			z.insert(mp(-h[i],i));
		}else{ali++;
			f.insert(mp(-h[i],i));ali++;
		}
	}
	vector<ll> ans;
	ll hh=0;
	while(z.size()){ali++;
		pii t=(*(z.begin()));ali++;
		ll v=t.S;
		hazf[v]=1;ali++;
		z.erase(t);ali++;
		hh++;ali++;
		ans.pb(v);ali++;
		vector<ll> tof,toz;ali++;
		for(auto d:ger[v]){ali++;
			if(hazf[d]==0){ali++;
				if(z.find(mp(-h[d],d))!=z.end()){
			ali++;		z.erase(mp(-h[d],d));ali++;
					tof.pb(d);
				}else{ali++;
					f.erase(mp(-h[d],d));ali++;
					toz.pb(d);
				}
			}
		}
		for(auto u:toz){ali++;
			z.insert(mp(-h[u],u));ali++;
		}
		for(auto u:tof){ali++;
			f.insert(mp(-h[u],u));ali++;
		}
	}
	if(hh!=n){ali++;
		cout<<"NO\n";ali++;
	}else{ali++;
		cout<<"YES\n";ali++;
		for(auto v:ans){ali++;
			cout<<v+1<<endl;ali++;
		}
	}



}