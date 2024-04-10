#include <bits/stdc++.h>
using namespace std;
void solve(){
	long long n;
	cin >> n;
	vector<long long> p(n);
	vector<pair<long long, long long>> v;
	long long ans=0LL;
	for(long long i=0;i<n;i++) p[i] = i;
	for(long long i=0;i<n-1;i++){
		if(i%2==0) v.emplace_back(0,n-1-i/2);
		else v.emplace_back(n-1,i/2+1);
	}
	for(auto x : v){
		long long tmp = p[x.first];
		p[x.first] = p[x.second];
		p[x.second] = tmp;
		ans += (x.first-x.second)*(x.first-x.second);
	}
	cout << ans << "\n";
	for(auto x : p) cout << x+1 << " ";
	cout << "\n";
	cout << n-1 << "\n";
	reverse(v.begin(),v.end());
	for(auto x : v) cout << x.second+1 << " " << x.first+1 << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for(int i=0;i<T;i++) solve();
}