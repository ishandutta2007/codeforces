#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int qmin(int a, int b){
	return (a < b) ? a : b;
}

int T;
int n;
int a[200200];
map<int, int> cnt;
vector<int> v;
int presum[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n) cin >> a[i];
		cnt.clear();
		v.clear();
		rep(i, n) cnt[a[i]]++;
		for(map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
			v.push_back(it->second);
		}
		sort(v.begin(), v.end());
		presum[0] = 0;
		rep(i, (int)v.size()) presum[i+1] = presum[i] + v[i];
		int nowsum = 0;
		int ans = presum[(int)v.size() - 1];
		for(int i = (int)v.size() - 2; i >= 0; i--){
			nowsum += ((int)v.size() - i - 1) * (v[i + 1] - v[i]);
			ans = qmin(ans, nowsum + presum[i]);
		}
		cout << ans << endl;
	}
	return 0;
}