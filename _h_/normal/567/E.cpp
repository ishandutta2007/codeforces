#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <map> 
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const ll inf = 1e15;
int main(){
	int n,m,s,t;
	cin >> n >> m >> s >> t;
	vector<vector<pii> > ut(n+1), in(n+1);
	vi as(m), bs(m), ls(m);
	rep(i,0,m){
		int a,b,l;
		cin >> a >> b >> l;
		as[i] = a;
		bs[i] = b;
		ls[i] = l;
		ut[a].pb(pii(b,l));
		in[b].pb(pii(a,l));
	}
	vector<ll> ds(n+1,inf), dt(n+1,inf);
	priority_queue<pli> ko;
	ko.push(pli(0,s));
	while(!ko.empty()){
		ll d = -ko.top().first;
		int a = ko.top().second;
		ko.pop();
		if(ds[a] != inf)
			continue;
		ds[a] = d;
		for(auto par : ut[a]){
			if(ds[par.first] == inf)
				ko.push(pli(-d-par.second,par.first));
		}
	}
	ko.push(pli(0,t));
	while(!ko.empty()){
		ll d = -ko.top().first;
		int a = ko.top().second;
		ko.pop();
		if(dt[a] != inf)
			continue;
		dt[a] = d;
		for(auto par : in[a]){
			if(dt[par.first] == inf)
				ko.push(pli(-d-par.second,par.first));
		}
	}

	vector<bool> vis(n+1);
	vi bra, edgenum(n+1,-1), toponum(n+1,-2);
	ko.push(pli(dt[s],s));
	while(!ko.empty()){
		int a = ko.top().second;
		ko.pop();
		if(vis[a])
			continue;
		vis[a] = 1;
		toponum[a] = bra.size();
		bra.pb(a);
		for(auto par : ut[a]){
			if(!vis[par.first] && ds[par.first] + dt[par.first] == ds[t])
				ko.push(pli(dt[par.first],par.first));
		} 
	}
	rep(i,0,m){
		if(toponum[as[i]]+1 == toponum[bs[i]] && ds[as[i]] + ls[i] + dt[bs[i]] == ds[t]){
			if(edgenum[as[i]] == -1)
				edgenum[as[i]] = i;
			else
				edgenum[as[i]] = -2;
		}
	}
	int framm = -1;
	vector<bool> jaa(m);
	rep(i,0,bra.size()-1){
		bool j = 1;
		if(framm >= i+1)
			j = 0;
		for(auto par : ut[bra[i]])
			if(ds[bra[i]] + par.second + dt[par.first] == ds[t])
				framm = max(framm,toponum[par.first]);
		if(framm > i+1)
			j = 0;
		if(edgenum[bra[i]] >= 0)
			jaa[edgenum[bra[i]]] = j;
	}
	rep(i,0,m){
		if(jaa[i]){
			cout << "YES" << endl;
			continue;
		}
		int a = as[i], b = bs[i], l = ls[i];
		ll c = ds[t] - 1 - ds[a] - dt[b];
		if(c < 1){
			cout << "NO" << endl;
			continue;
		}
		else
			cout << "CAN " << l - c << endl;
	}
}