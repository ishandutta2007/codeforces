
// Problem : E. Two Arrays
// Contest : Codeforces - Educational Codeforces Round 89 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1366/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[200005], brr[200005];
int lpt[200005], rpt[200005];
const long long MOD = 998244353;
pair<int, int> srt[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		srt[i] = {arr[i], i};
	}
	for(int i = 1; i<=M; i++){
		cin >> brr[i];
	}
	brr[M+1] = INT_MAX;
	arr[N+1] = INT_MAX;
	srt[N+1] = {INT_MAX, N+1};
	long long ans = (*min_element(arr+1, arr+1+N) == brr[1]);
	N++;
	sort(srt+1, srt+1+N);
	int idx = 0, mx = 0;
	lpt[1] = rpt[1] = 1;
	for(int i = 2; i<=M+1; i++){
		while(idx < N && srt[idx+1].first < brr[i]){
			mx = max(mx, srt[idx+1].second);
			idx++;
		}
		lpt[i] = mx+1;
		while(idx < N && srt[idx+1].first == brr[i]){
			mx = max(mx, srt[idx+1].second);
			idx++;
		}
		rpt[i] = mx;
	}
	for(int i = 1; i<=M; i++){
		//cout << lpt[i] << " " << rpt[i] << "\n";
		ans *= max(0, rpt[i] - lpt[i] + 1);
		ans %= MOD;
	}
	cout << ans;
}