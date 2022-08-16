#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e9;

ll a[200005],l[200005],r[200005];
vector <pair<ll,ll>> v;
string s;
vector <ll> ans;
ll t,n,ct,q,k,U,V;
set <ll> se;
pair <ll,ll> p;

int ch(ll med){
	ct = 0;
	ll sum = 0;
	for(int i = v.size()-1; i >= 0; i--){
		if(ct == n/2 +1){
			sum += v[i].first;
		}
		else if(v[i].second < med){
			sum += v[i].first;
		}
		else{
			sum += max(v[i].first,med);
			ct += 1;
		}
	}
	if(ct == n/2 + 1 && sum <= k){
		//cout<<ct<<" "<<sum<<endl;
		return 1;
	}
	return 0;
}

ll bs(){
	ll high = INF, low = 0;
	while(high >= low){
		ll mid = (high+low)/2;
		if(ch(mid) == 0){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	//cout<<low<<" "<<high<<endl;
	return low-1;
}
 

int main(){
	cin>>q;
	while(q--){
		cin>>n>>k;
		v.clear();
		for(int i = 0; i < n; i++){
			cin>>U>>V;
			p = make_pair(U,V);
			v.push_back(p);
		}
		sort(v.begin(),v.end());
		cout<<bs()<<endl;
	}
}