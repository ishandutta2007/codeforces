
// Problem : C. Levels and Regions
// Contest : Codeforces - Codeforces Round #351 (VK Cup 2016 Round 3, Div. 1 Edition)
// URL : https://codeforces.com/contest/674/problem/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
long double pre[200005], har[200005], val[200005];
int arr[200005];
long double dp[55][200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		val[i] = arr[i] + val[i-1];
		har[i] = 1.0/arr[i];
	}
	for(int i = 1; i<=N; i++){
		pre[i] = pre[i-1] + val[i]/arr[i];
		har[i] += har[i-1];
	}
	for(int i = 1; i<=N; i++){
		dp[1][i] = pre[i];
		//cout << dp[1][i] << "\n";
	}
	for(int k = 2; k<=K; k++){
		deque<pair<long double, long double>> dq;
		dq.push_back(make_pair(-val[k-1], dp[k-1][k-1]+val[k-1]*har[k-1]-pre[k-1]));
		for(int n = k; n<=N; n++){
			while(dq.size() >= 2){
				if(dq[0].second+pre[n]+dq[0].first*har[n] >= dq[1].second+pre[n]+dq[1].first*har[n]){
					//cout << n << "\n";
					//cout << dq[0].second+pre[n]+dq[0].first*har[n] << " " << dq[1].second+pre[n]+dq[1].first*har[n] << "\n";
					dq.pop_front();
				}
				else{
					break;
				}
			}
			dp[k][n] = dq.front().second + pre[n] + dq.front().first * har[n];
			pair<long double, long double> l = make_pair(-val[n], dp[k-1][n]+val[n]*har[n]-pre[n]);
			while(dq.size() >= 2){
				auto p = dq.back();
				dq.pop_back();
				if((dq.back().second-p.second)/(p.first-dq.back().first)<(dq.back().second-l.second)/(l.first-dq.back().first)){
					dq.push_back(p);
					break;
				}
			}
			dq.push_back(l);
		}
	}
	cout << setprecision(10) << dp[K][N] << "\n";
}