#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int a[100100], d[100100];
void solve(){
	cin >> n;
	
	rep(i, n)
		cin >> a[i];
	
	priority_queue< pair<int, int> > pq;
	rep(i, n-1)
		d[i] = a[i] - a[i+1], pq.emplace(d[i], i);
	
	vector<int> ans(n+1);
	for(int i = n; i > 1; --i){
		int p = pq.top().second; pq.pop();
		ans[i] = p+1;
		d[p] -= i;
	}
	ans[1] = 0;
	
	rep(i, n)
		cout << ans[i+1]+1 << " ";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}