#include <bits/stdc++.h>
using namespace std;
long long bino[1001][1001];
void init(){
	for(int i=0;i<1001;i++) bino[i][0] = bino[i][i] = 1;
	for(int i=1;i<1001;i++){
		for(int j=1;j<i;j++) bino[i][j] = (bino[i-1][j-1] + bino[i-1][j])%1000000007LL;
	}
}
void solve(){
	int n,k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	sort(v.begin(),v.end());
	int r = v[n-k];
	int cnt = upper_bound(v.begin(),v.end(),r) - lower_bound(v.begin(),v.end(),r);
	int pp = upper_bound(v.begin(),v.end(),r) - (v.begin() + (n-k));
	cout << bino[cnt][pp] << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int T;
	cin >> T;
	for(int i=0;i<T;i++) solve();
}