
// Problem : A. Boboniu Chats with Du
// Contest : Codeforces - Codeforces Round #664 (Div. 1)
// URL : https://codeforces.com/contest/1394/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long N, D, M;
vector<long long> v, w;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> D >> M;
	for(int i = 1; i<=N; i++){
		long long n;
		cin >> n;
		if(n > M){
			v.push_back(n);
		}
		else{
			w.push_back(n);
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	sort(w.begin(), w.end());
	int idx = 0;
	long long ans = 0;
	long long tot = 0;
	for(int i =0 ; i<w.size(); i++){
		tot += w[i];
	}
	ans = tot;
	for(int i = 1; i<=v.size(); i++){
		long long k = 1LL*(i-1)*(D+1)+1;
		tot += v[i-1];
		if(k > N){
			break;
		}
		while((int) (w.size())-idx+k > N){
			tot -= w[idx];
			idx++;
		}
		ans = max(ans, tot);
	}
	cout << ans;
}