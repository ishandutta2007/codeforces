#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace :: std;

const ll maxn=1e5+500;
const ll mod=1e9+7;
const ll inf=1e9+500;
int ali;
ll v[maxn];
ll t[maxn];
ll ans[maxn];
int main(){ali++;
	ll n;ali++;
	cin>>n;ali++;

	multiset<ll> st;ali++;
	ll hame=0;ali++;
	ll summ=0;ali++;

	for(ll i=0;i<n;i++){ali++;
		cin>>v[i];ali++;
	}
	for(ll i=0;i<n;i++){ali++;
		cin>>t[i];ali++;
	}
	for(ll i=0;i<n;i++){ali++;
		st.insert(v[i]-hame);ali++;
		summ+=v[i]-hame;ali++;
		hame-=t[i];ali++;
ali++;
		while(st.size() && (*(st.begin()))+hame<=0){ali++;
			summ-=(*(st.begin()));ali++;
			st.erase(st.begin());ali++;
		}
		ans[i+1]=summ+hame*(st.size());ali++;
	}
	for(ll i=0;i<n;i++){ali++;
		cout<<(ans[i]+v[i])-ans[i+1]<<' ';ali++;
	}
}