#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll fen[maxn];
ll fensum[maxn];
ll coresavail[maxn];
std::vector<std::vector<ll>> event[maxn];

ll query(ll pos){
	ll res = 0;
	while(pos > 0){
		res += fen[pos];
		pos -= pos & -pos;
	}
	return res;
}	
ll querysum(ll pos){
	ll res = 0;
	while(pos > 0){
		res += fensum[pos];
		pos -= pos & -pos;
	}
	return res;
}	
void update(ll pos, ll val){	
	while(pos < maxn){
		fen[pos] += val;
		pos += pos & -pos;
	}
}
void updatesum(ll pos, ll val){
	ll temp = pos;
	
	while(pos < maxn){
		fensum[pos] += val * temp;
		pos += pos & -pos;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	
	ll n, k, m;
	std::cin >> n >> k >> m;
	
	for(ll i = 0; i < m; i++){
		ll l, r, c, p;
		std::cin >> l >> r >> c >> p;
		
		event[l].push_back({c, p});
		event[r + 1].push_back({-c, p});
	}
	
	ll res = 0;
	ll prevres = 0;
	ll sumcores = 0;
	for(ll i = 1; i <= n; i++){
		if(event[i].empty()){
			res += prevres;
			continue;
		}
		
		for(auto& j : event[i]){
			coresavail[j[1]] += j[0];
			sumcores += j[0];
			//std::cerr << j[1] << ' ' << j[0] << '\n';
			update(j[1], j[0]);
			updatesum(j[1], j[0]);
		}
		
		if(sumcores <= k){
			prevres = querysum(1000001);
			res += prevres;
			continue;
		}
		
		ll l = 1, r = 1000001;
		ll best = r + 1;
		
		while(l <= r){
			ll mid = (l + r) / 2;
			
			if(query(mid) >= k){
				best = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			} 
		}
		
		prevres = querysum(best - 1) + (k - query(best - 1)) * best;
		
		res += prevres;
	}
	
	std::cout << res << '\n';
}