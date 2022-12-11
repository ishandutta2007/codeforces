
// Problem : A. Orac and LCM
// Contest : Codeforces - Codeforces Round #641 (Div. 1)
// URL : https://codeforces.com/contest/1349/problem/A
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int M = 200000;
vector<int> p;
pair<int, int> ans[200005];
int has[200005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 2; i<=M; i++){
		bool isp = 1;
		for(int n : p){
			if(1LL*n*n > i){
				break;
			}
			if(i%n == 0){
				isp = 0;
				break;
			}
		}
		if(isp){
			p.push_back(i);
		}
	}
	//sort(v.begin(), v.end(), greater<int>());
	fill(ans+1, ans+1+M, make_pair(INT_MAX, INT_MAX));
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		for(int q : p){
			if(1LL*q*q > n){
				break;
			}
			int cnt = 0;
			while(n%q == 0){
				cnt++;
				n /= q;
				//cout << i << " " << q << "\n";
			}
			has[q]++;
			if(ans[q].first >= cnt){
				ans[q].second = ans[q].first;
				ans[q].first = cnt;
			}
			else if(ans[q].second > cnt){
				ans[q].second = cnt;
			}
		}
		//cout << n << "\n";
		if(n > 1){
			has[n]++;
			if(ans[n].first >= 1){
				ans[n].second = ans[n].first;
				ans[n].first = 1;
			}
			else if(ans[n].second > 1){
				ans[n].second = 1;
			}
		}
	}
	long long out = 1;
	for(int i = 1; i<=M; i++){
		if(has[i] <= N-1){
			ans[i].second = ans[i].first;
			ans[i].first =0;
		}
		if(has[i] <= N-2){
			ans[i].first = ans[i].second = 0;
		}
		while(has[i] >= N-1 && ans[i].second != INT_MAX && ans[i].second--){
			out *= i;
		}
	}
	cout << out << "\n";
}