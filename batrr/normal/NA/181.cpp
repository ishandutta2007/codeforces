#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, mod = (int)1e9 + 7;

int n, k, a[N], b[N], upd[N];
vector< pll > v[N];

void precalc(){
	set< pair< pll, ll> > st;
	for(int i = 1; i <= n; i++){
		ll l = a[i], r = b[i];
		if(l == r)
			continue;
		//cerr << l << " " << r << endl;
		while(st.lower_bound({{l + 1, -1}, -1}) != st.end() && st.lower_bound({{l + 1, -1}, -1}) -> f.s < r){
			
			pair< pll, ll > it = *st.lower_bound({{l + 1, -1}, -1});
			st.erase(it);
			//cerr << it.f.s << " " << it.f.f << endl;
			ll id = it.s;
			ll len = min(r, it.f.f) - max(l, it.f.s);
			
			if(it.f.s <= l)
			    st.insert({{l, it.f.s}, id});
			
			if(it.f.f >= r)
			    st.insert({{it.f.f, r}, id});
			 
			v[i].pb({id, -len});
			
		}
	
		st.insert({{r, l}, i});
		v[i].pb({i, r - l});			
	}                      	
}
pll calc(int k){
	ll cnt = 0, sum = 0;
	ll cur_sum = 0, tmp_sum = 0;
	
	for(int i = 0; i < N; i++)
		upd[i] = 0;

	for(int i = 1,j = 1; i <= n; i++){
		for(auto it: v[i]){
			ll id = it.f;
			ll len = it.s;
			if(id < j){
				cur_sum += id * len; 
			}else{
				cur_sum += (j - 1) * len;
				tmp_sum += len;
				upd[id] += len;
			}		
		}	
		//cerr << i << " " << j << " " << cur_sum << " " << tmp_sum << endl;
        while(tmp_sum > k && j <= i){
			cur_sum += tmp_sum;
			tmp_sum -= upd[j];
			j++;	
		}
		//cerr << i << " " << j << " " << cur_sum << " " << tmp_sum << endl;
        cnt += j - 1;
		sum += cur_sum;
	}
    //cerr << cnt << " " << sum << endl;
	return {cnt, sum};
}
int main(){    
	
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]); 
	
	precalc();
	/*
	for(int i = 1; i <= n; i++)
		for(auto it : v[i])
			cerr << i << " " << it.f << " " << it.s << endl;
	cerr << "CALC" << endl;
	calc(100);
	//return 0;
	*/
	int l = 0, r = 1e9;
	while(l <= r){
		int m = (l + r) / 2;
		if(calc(m).f >= k)
			l = m + 1;
		else
			r = m - 1;
	}
    ll ans = l * (k - calc(l - 1).f) + calc(l - 1).s;
	printf("%lld", ans);
	return 0;
}