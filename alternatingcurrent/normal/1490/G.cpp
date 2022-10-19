#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
int qmin(int a, int b){
	return (a < b) ? a : b;
}
ll qmax(ll a, ll b){
	return (a > b) ? a : b;
}

int T;
int n, m;
ll a[200200];
ll sum[200200];
set<ll> sums;
map<ll, int> sum_num;
ll num_sum[200200];
ll sum_first[200200];
ll mxpos;
ll all_sum, max_sum;
ll x;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, n) cin >> a[i];
		sum[0] = 0;
		rep(i, n) sum[i + 1] = sum[i] + a[i];
		all_sum = sum[n];
		max_sum = 0xc0c0c0c0c0c0c0c0;
		rep(i, n) max_sum = qmax(max_sum, sum[i]);
		sums.clear();
		rep(i, n+1) sums.insert(sum[i]);
		int cnt = 0;
		sum_num.clear();
		for(set<ll>::iterator it = sums.begin(); it != sums.end(); it++){
			sum_num[*it] = cnt;
			num_sum[cnt] = *it;
			cnt++;
		}
		for(int i = n; i >= 0; i--) sum_first[sum_num[sum[i]]] = i;
		for(int i = cnt - 2; i >= 0; i--) sum_first[i] = qmin(sum_first[i], sum_first[i + 1]);
//		rep(i, n) cout << i << ": " << num_sum[i] << " "  << sum_first[i] << endl;
//		cout << "ans: ";
		while(m--){
			cin >> x;
//			cout << x << " vs " << max_sum << endl;
			if((all_sum <= 0) && (x > max_sum)){
				cout << "-1 ";
				continue;
			}
			ll round = (all_sum > 0) ? qmax((x - max_sum + all_sum - 1) / all_sum, 0) : 0;
			ll rem = x - round * all_sum;
			ll min_sum = *sums.lower_bound(rem);
			cout << ((round * n + sum_first[sum_num[min_sum]]) - 1) << " ";
		}
		cout << endl;
	}
	return 0;
}