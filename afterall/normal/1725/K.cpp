#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e6+100;

ll par[N];
ll h[N];
ll getpar(ll v){
	if (par[v]==v) return v;
	return par[v]=getpar(par[v]);
}
ll last[N];
int32_t main(){
	sync;
	ll n;
	cin >> n;
	ll cnt=n+1;
	set <pii> s;
	for (int i=1;i<=n;i++){
		cin >> h[i];
		par[i]=i;
		s.insert({h[i],i});
		last[i]=i;
	}
	ll q;
	cin >> q;
	while(q--){
		ll t;
		cin >> t;
		if (t==1){
			ll k,x;
			cin >> k >> x;
			//cout << k << " " << x << " cnt " << cnt << endl;
			last[k]=cnt;
		//	return 0;
			h[cnt]=x;
			par[cnt]=cnt;
			s.insert({x,cnt});
			cnt++;
		}
		else if (t==2){
			ll k;
			cin >> k;
			cout << h[getpar(last[k])] << endl;
		}
		else{
			ll l,r;
			cin >> l >> r;
			ll mid=(r+l)/2;
			ll p=-1;
			while(s.size() &&  s.lower_bound({l,-1})!=s.end() && s.lower_bound({l,-1})->F<=mid){
				if (p==-1){
					p=s.lower_bound({l,-1})->S;
					s.erase(s.lower_bound({l,-1}));
					h[p]=l-1;
				//	cout << p << " p " << l-1 << endl;
					s.insert({l-1,p});
				}
				else{
					par[s.lower_bound({l,-1})->S]=p;
					//cout << " par " << s.lower_bound({l,-1})->S << " " << p << endl;
					s.erase(s.lower_bound({l,-1}));
				}
			}
			l=mid;
			mid=r;
			p=-1;
			//cout << l << " l r " << r << " " << s.lower_bound({l,-1})->F << endl;
			while(s.size() && s.lower_bound({l,-1})!=s.end() && s.lower_bound({l,-1})->F<=mid){
				if (p==-1){
					p=s.lower_bound({l,-1})->S;
					s.erase(s.lower_bound({l,-1}));
					h[p]=mid+1;
				//	cout << p << " PP  " << mid+1 << endl;
					s.insert({mid+1,p});
				}
				else{
					//	cout << " PAR " << s.lower_bound({l,-1})->S << " " << p << endl;
					par[s.lower_bound({l,-1})->S]=p;
					s.erase(s.lower_bound({l,-1}));
				}
			}

		}
	}
}