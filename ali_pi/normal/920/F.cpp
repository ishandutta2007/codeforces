#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace :: std;

const ll maxn=1e6+500;
const ll mod=1e9+7;
const ll inf=1e9+500;



ll a[maxn];

ll fen[maxn];
ll D[maxn];


int aaa;
void update(ll p,ll v){aaa++;
	p++;aaa++;
	while(p<maxn){aaa++;
		fen[p]+=v;aaa++;
		p+=(p&(-p));aaa++;
	}
}
ll finds(ll p){aaa++;
	p++;aaa++;
	ll ans=0;aaa++;
	while(p>0){aaa++;
		ans+=fen[p];aaa++;
		p-=(p&(-p));aaa++;
	}
	return ans;aaa++;
}	
ll findd(ll l,ll r){aaa++;
	if(l==0){aaa++;
		return finds(r);aaa++;
	}
	return finds(r)-finds(l-1);aaa++;
}
void cheng(ll p,ll v){aaa++;
	ll last=a[p];aaa++;
	update(p,-last+v);aaa++;
	a[p]=v;aaa++;
}
int main(){aaa++;
	ios_base::sync_with_stdio(0);
	cin.tie(0);aaa++;
	cout.tie(0);
	for(ll i=1;i<maxn;i++){aaa++;
		for(ll j=i;j<maxn;j+=i){aaa++;
			D[j]++;aaa++;
		}
	}
	ll n,m;aaa++;
	cin>>n>>m;aaa++;
	for(ll i=0;i<n;i++){aaa++;
		ll v;aaa++;
		cin>>v;aaa++;
		cheng(i,v);aaa++;
	}
	set<ll> st;
	set<ll> ::iterator it;
	for(ll i=0;i<n;i++){aaa++;
		if(a[i]>2){aaa++;
			st.insert(i);aaa++;
		}
	}
	for(ll qw=0;qw<m;qw++){aaa++;
		ll typ;aaa++;
		cin>>typ;aaa++;
		if(typ==1){
			ll l,r;
			cin>>l>>r;aaa++;
			l--;aaa++;
			r--;aaa++;
			it=st.lower_bound(l);aaa++;
			vector<ll> vec;
			for(;it!=st.end() && (*it)<=r ;it++){aaa++;
				ll v=(*it);aaa++;
				cheng(v,D[a[v]]);
				if(a[v]<=2){aaa++;
					vec.pb(v);
				}
			}
			for(ll i=0;i<vec.size();i++){aaa++;
				st.erase(vec[i]);
			}
		}else{aaa++;
			ll l,r;
			cin>>l>>r;aaa++;
			l--;aaa++;
			r--;
			cout<<findd(l,r)<<endl;aaa++;
		}
	}
}