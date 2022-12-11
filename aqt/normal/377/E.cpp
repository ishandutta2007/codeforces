
// Problem : E. Cookie Clicker
// Contest : Codeforces Round #222 (Div. 1)
// URL : https://codeforces.com/contest/377/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct line{
	mutable long long m, b, p;
	bool operator < (const line &o) const{
		return m < o.m;
	}
	bool operator < (long long x) const {
		return p < x;
	}
};

struct LineContainer : multiset<line, less<>>{
	const long long inf = LLONG_MAX/2;
	long long div(long long a, long long b){
		return a/b - ((a^b) < 0 && a%b);
	}
	bool isect(iterator x, iterator y){
		if(y == end()){
			x->p = inf;
			return 0;
		}
		if(x->m == y->m){
			x->p = x->b > y->b ? inf : -inf;
		}
		else{
			x->p = div(y->b - x->b, x->m - y->m);
		}
		return x->p >= y->p;
	}
	void add(long long m, long long b){
		auto z = insert({m, b, 0}), y = z++, x = y;
		while(isect(y, z)){
			z = erase(z);
		}
		if(x != begin() && isect(--x, y)){
			isect(x, y = erase(y));
		}
		while((y = x) != begin() && (--x)->p >= y->p){
			isect(x, erase(y));
		}
	}
	long long query(long long x){
		assert(!empty());
		auto l = *lower_bound(x);
		//cout << "this slope: " << l.m << "\n";
		return l.m*x + l.b;
	}
};

int N;
long long S;
pair<long long, long long> arr[200005];
long long dp[200005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	for(int i = 1; i<=N; i++){
		cin >> arr[i].second >> arr[i].first;
	}
	//arr[N+1].first = S;
	sort(arr+1, arr+1+N);
	LineContainer lc;
	lc.add(arr[1].second, 0);
	long long mx = arr[1].second;
	for(int i = 2; i<=N; i++){
		if(arr[i].second < mx){
			continue;
		}
		long long l = 0, r = 1000000000, idx = r+1, val = 0; //might be wrong on r bounds
		while(l <= r){
			long long mid = l+r>>1;
			//cout << lc.query(mid) << endl;
			if(lc.query(mid) >= arr[i].first){
				idx = mid;
				r = mid - 1;		
				val = lc.query(mid);		
			}
			else{
				l = mid + 1;
			}
		}
		//cout << "query: 4 " << lc.query(4) << endl;
		dp[i] = idx;
		//cout << dp[i] << "\n";
		//cout << lc.query(idx) << "\n";
		//cout << " " << arr[i].second << " " << dp[i] << " " << -arr[i].second * dp[i] + val - arr[i].first << endl;
		//cout << val << " " << arr[i].first << "\n";
		mx = max(arr[i].second, mx);
		if(arr[i].second){
			lc.add(arr[i].second, -arr[i].second*dp[i] + val - arr[i].first);
		}
	}
	long long ans = LLONG_MAX/2;
	for(auto ln : lc){
		//cout << (S-ln.b+ln.m-1)/ln.m << " " << ln.m << " " << ln.b << "\n";
		ans = min(ans, (S-ln.b+ln.m-1)/ln.m);
	}
	cout << ans << "\n";
}