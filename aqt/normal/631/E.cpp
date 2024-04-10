
// Problem : E. Product Sum
// Contest : Codeforces Round #344 (Div. 2)
// URL : https://codeforces.com/contest/631/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[200005];
long long pre[200005];
deque<pair<long long, long long>> dq;
pair<long long, int> srt[200005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long long crnt = 0;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		crnt += arr[i] * i;
		srt[i].first = arr[i];
		srt[i].second = i;
	}
	partial_sum(arr+1, arr+1+N, pre+1);
	sort(srt+1, srt+1+N);
	for(int i= 0; i<=N; i++){
		while(dq.size() >= 2){
			long long b12 = dq.back().second - dq[dq.size()-2].second;
			long long m13 = dq[dq.size()-2].first - i;
			long long b13 = pre[i] - dq[dq.size()-2].second;
			long long m12 = dq[dq.size()-2].first - dq.back().first;
			if(-b13*m12 <= -m13*b12){
				dq.pop_back();
			}
			else{
				break;
			}
		}
		dq.push_back({i, pre[i]});
	}
	long long ans = crnt;
	for(int i = 1; i<=N; i++){
		int idx = srt[i].second;
		while(dq.size() >= 2){
			if(dq.front().first*arr[idx]-dq.front().second <= dq[1].first*arr[idx]-dq[1].second){
				dq.pop_front();
			}
			else{
				break;
			}
		}
		long long v = crnt;
		v += dq.front().first*arr[idx]-dq.front().second;
		v += -arr[idx]*idx;
		v += pre[idx];
		//cout << idx << " " << v << "\n";
		//cout << " " << dq.front().first << " " << dq.front().second << "\n";
		ans = max(ans, v);
	}
	cout << ans << "\n";
}