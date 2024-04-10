#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n, m;
int a[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, m)
			cin >> a[i];
		sort(a, a + m);
		vector<int> cnt;
		rep(i, m){
			ll len = (a[(i + 1) % m] - a[i] - 1 + n) % n;
			if(len > 0)
				cnt.push_back(len);
		}
		sort(cnt.begin(), cnt.end());
		reverse(cnt.begin(), cnt.end());
		int ans = 0;
		rep(i, (int)cnt.size()){
			int cost = (i + i) + (i + i + 1);
//			cout << cnt[i] << " " << cost << endl;
			if(cnt[i] == cost)
				ans++;
			else
				ans += max(0, cnt[i] - cost);
		}
		cout << n - ans << endl;
	}
	return 0;
}