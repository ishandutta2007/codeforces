#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
map<int,int>mp;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k, l=0;
	cin >> n >> k;
	queue<int>q;
	rep(i, n) {
		int a;
		cin >> a;
		if(mp[a]) continue;
		if(l==k) {
			int p=q.front(); q.pop();
			mp[p]=0;
			--l;
		}
		q.push(a);
		mp[a]=1;
		++l;
	}
	vector<int>ans;
	while(!q.empty()) {
		ans.pb(q.front());
		q.pop();
	}
	reverse(all(ans));
	cout << ans.size() << '\n';
	for(auto i : ans) cout << i << " ";
	cout << '\n';
}