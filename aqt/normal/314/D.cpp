
// Problem : D. Sereja and Straight Lines
// Contest : Codeforces - Codeforces Round #187 (Div. 1)
// URL : https://codeforces.com/contest/314/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
pair<long long, long long> arr[100005];
long long premx[100005], premn[100005], sufmx[100005], sufmn[100005];

bool pos(long long K){
	for(int l = 1, r = 1; r <= N; r++){
		while(arr[r].first - arr[l].first > K){
			l++;
		}
		long long mx = max(premx[l-1], sufmx[r+1]);
		long long mn = min(premn[l-1], sufmn[r+1]);
		if(mx - mn <= K){
			return 1;
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		int x, y;
		cin >> x >> y;
		arr[i].first = x+y;
		arr[i].second = x-y;
	}
	sort(arr+1, arr+1+N);
	sufmx[N+1] = premx[0] = LLONG_MIN/16;
	sufmn[N+1] = premn[0] = LLONG_MAX/16;
	for(int i = 1; i<=N; i++){
		premx[i] = max(premx[i-1], arr[i].second);
		premn[i] = min(premn[i-1], arr[i].second);
	}
	for(int i = N; i; i--){
		sufmx[i] = max(sufmx[i+1], arr[i].second);
		sufmn[i] = min(sufmn[i+1], arr[i].second);
	}
	long long l = 0, r = 10000000000LL, ans = 0LL;
	while(l <= r){
		long long mid = l+r>>1;
		if(pos(mid)){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout << ans/2;
	if(ans%2){
		cout << ".5";
	}
	else{
		cout << ".0";
	}
}