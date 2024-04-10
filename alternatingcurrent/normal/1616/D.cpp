#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int n;
ll x;
ll a[50050];
ll sum[50050];
ll to[50050];
ll dp[50050];
deque<int> dq;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
//		cout << "------" << T << "------" << endl;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		cin >> x;
		for(int i = 1; i <= n; i++)
			a[i] -= x;
		to[1] = 1;
		for(int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + a[i];
		dq.clear();
		dq.push_back(0);
		for(int i = 2; i <= n; i++){
			to[i] = to[i - 1];
			while(to[i] < i){
				while(dq.front() < to[i] - 1)
					dq.pop_front();
				if(sum[i] - sum[dq.front()] >= 0)
					break;
				to[i]++;
			}
			while(!dq.empty() && sum[dq.back()] < sum[i - 1])
				dq.pop_back();
			dq.push_back(i - 1);
		}
//		for(int i = 1; i <= n; i++)
//			cout << to[i] << " ";
//		cout << endl;
		dq.clear();
		for(int i = 0; i <= n; i++)
			dp[i] = 0x3f3f3f3f;
		dp[0] = 0, dp[1] = 1;
		dq.push_back(0);
		for(int i = 1; i <= n; i++){
//			cout << dp[i] << " ";
			while(dq.front() < to[i] - 1)
				dq.pop_front();
			dp[i + 1] = min(dp[i] + 1, dp[dq.front()] + (i != n));
			while(!dq.empty() && dp[dq.back()] > dp[i])
				dq.pop_back();
			dq.push_back(i);
		}
		cout << max(n - dp[n + 1], n - 1 - dp[n]) << endl;
	}
	return 0;
}