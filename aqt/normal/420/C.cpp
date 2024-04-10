
// Problem : C. Bug in Code
// Contest : Codeforces - Coder-Strike 2014 - Finals (online edition, Div. 1)
// URL : https://codeforces.com/contest/420/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, P;
int cnt[300005], bit[300005];
map<pair<int, int>, int> mp;

void upd(int n){
	n++;
	while(n <= N+1){
		bit[n]++;
		n += n&-n;
	}
}

int query(int n){
	int ret = 0;
	n++;
	while(n){
		ret += bit[n];
		n -= n&-n;
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> P;
	for(int i = 1; i<=N; i++){
		int a, b;
		cin >> a >> b;
		if(a > b){
			swap(a, b);
		}
		cnt[a]++, cnt[b]++;
		mp[{a, b}]++;
	}
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		if(cnt[i] >= P){
			ans += query(N);
		}
		else{
			ans += query(N) - query(P-cnt[i]-1);
		}
		upd(cnt[i]);
	}
	for(auto p : mp){
		int x = p.first.first, y = p.first.second;
		if(cnt[x] + cnt[y] >= P && cnt[x] + cnt[y] - p.second < P){
			ans--;
		}
	}
	cout << ans << "\n";
}