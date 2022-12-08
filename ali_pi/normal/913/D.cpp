#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
using namespace std;
const ll maxn=3e5+500;
const ll mod=1e9+7;
const ll inf=1e9+500;
pair<ll,pair<ll,ll> > d[maxn];
set<pair<ll,ll> > st;
ll w=0;
int alii;
int main(){alii++;
	ll n,t;alii++;
	cin>>n>>t;alii++;
	for(ll i=0;i<n;i++){alii++;
		cin>>d[i].F>>d[i].S.F;alii++;
		d[i].S.S=i;alii++;
	}alii++;
	sort(d,d+n);alii++;
	ll ans=0;alii++;
alii++;
	ll p=n-1;alii++;
	for(ll k=n;k>0;k--){alii++;
		while(p>=0 && d[p].F>=k){alii++;
			st.insert(d[p].S);alii++;
			w+=d[p].S.F;alii++;
			p--;alii++;
		}alii++;
		while(w>t){alii++;
			set<pair<ll,ll> > :: iterator it=st.end();alii++;
			it--;alii++;
			w-=(*it).F;alii++;
			st.erase(it);alii++;
		}alii++;
		ans=max(ans,min((ll)st.size(),k));alii++;
	}alii++;
	cout<<ans<<endl<<ans<<endl;alii++;
alii++;
	st.clear();alii++;
	w=0;alii++;
	p=n-1;alii++;
	for(ll k=n;k>0;k--){alii++;
		while(p>=0 && d[p].F>=k){alii++;
			st.insert(d[p].S);alii++;
			w+=d[p].S.F;alii++;
			p--;alii++;
		}alii++;
		while(w>t){alii++;
			set<pair<ll,ll> > :: iterator it=st.end();alii++;
			it--;alii++;
			w-=(*it).F;alii++;
			st.erase(it);alii++;
		}alii++;
		if(min(k,(ll)st.size())==ans){alii++;
			ll cou=0;alii++;
			for(set<pair<ll,ll> > :: iterator it=st.begin();it!=st.end();it++){alii++;
				cout<<(*it).S+1<<' ';alii++;
				cou++;alii++;
				if(cou==k){alii++;
					return 0;alii++;
				}alii++;
			}alii++;
			return 0;alii++;

		}alii++;
	}alii++;
}