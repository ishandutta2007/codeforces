
// Problem : F. Kuroni and the Punishment
// Contest : Codeforces - Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!)
// URL : https://codeforces.com/contest/1305/problem/F
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int T = 10;
mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());
long long arr[200005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	vector<int> cand;
	while(T--){
		int n = uniform_int_distribution<int>(1, N)(g1);
		cand.push_back(n);
	}
	vector<long long> pr;
	for(int n : cand){
		for(long long i = max(arr[n]-1, 1LL); i<=arr[n]+1; i++){
			long long t = i;
			for(long long f = 2; f<=sqrt(t); f++){
				if(t%f == 0){
					pr.push_back(f);
					do{
						t /= f;
					}
					while(t%f == 0);
				}
			}
			if(t > 1){
				pr.push_back(t);
			}
		}
	}
	sort(pr.begin(), pr.end());
	pr.erase(unique(pr.begin(), pr.end()), pr.end());
	long long ans = N;
	for(long long p : pr){
		long long tot = 0;
		for(int n = 1; n<=N; n++){
			if(arr[n] < p){
				tot += p - arr[n]%p;
			}
			else{
				tot += min(arr[n]%p, p-arr[n]%p);
			}
			if(tot > ans){
				break;
			}
		}
		ans = min(tot, ans);
	}
	cout << ans;
}