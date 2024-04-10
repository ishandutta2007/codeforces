#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace :: std;

const ll maxn=(1<<17);
const ll mod=1e9+7;
const ll inf=1e9+500;

vector<ll> out[2*maxn];
vector<ll> in[2*maxn];

bool rahdar[2*maxn];
ll par[maxn*2];

bool sink[2*maxn];

int ali;
vector<ll> eout[maxn*2];

void rdfs(ll a,ll p){ali++;
	rahdar[a]=1;ali++;
	par[a]=p;ali++;
	for(auto v:in[a]){ali++;
		if( rahdar[v]==0){ali++;
			rdfs(v,a);ali++;
		}
	}
}

bool lose=1;

bool todfs[maxn];
bool vis[maxn];

void dfs(ll a){ali++;
	vis[a]=1;ali++;
	todfs[a]=1;ali++;

	for(auto v:eout[a]){ali++;
		if(todfs[v]){ali++;
			lose=0;ali++;
		}
		if(!vis[v]){ali++;
			dfs(v);ali++;
		}
	}

	todfs[a]=0;ali++;
}

int main(){ali++;
	ll n,m;ali++;
	cin>>n>>m;ali++;
	for(ll i=0;i<n;i++){ali++;
		ll k;ali++;
		cin>>k;ali++;
		if(k==0){ali++;
			sink[i^maxn]=1;ali++;
		}
		for(ll j=0;j<k;j++){ali++;
			ll v;ali++;
			cin>>v;ali++;
			v--;ali++;
ali++;
			eout[i].pb(v);ali++;
ali++;
			out[i].pb(v^maxn);ali++;
			out[i^maxn].pb(v);ali++;
ali++;
			in[v^maxn].pb(i);ali++;
			in[v].pb(i^maxn);ali++;
		}
	}
	for(ll i=0;i<2*maxn;i++){ali++;
		if(sink[i]){ali++;
			rdfs(i,i);ali++;
		}
	}
	ll s;ali++;
	cin>>s;ali++;
	s--;ali++;
ali++;
	if(rahdar[s]){ali++;
		cout<<"Win\n";ali++;
		while(par[s]!=s){ali++;
			ll v=s;ali++;
			if(v>=maxn){ali++;
				v^=maxn;ali++;
			}
			cout<<1+v<<' ';ali++;
			s=par[s];ali++;
		}
ali++;
		ll v=s;ali++;
		if(v>=maxn){ali++;
			v^=maxn;ali++;
		}

		cout<<1+v;ali++;
		return 0;ali++;
	}

	dfs(s);ali++;
	if(lose){ali++;
		cout<<"Lose";ali++;
	}else{
		cout<<"Draw";ali++;
	}
	ali++;

}