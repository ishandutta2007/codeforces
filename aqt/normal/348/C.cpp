
// Problem : C. Subset Sums
// Contest : Codeforces - Codeforces Round #202 (Div. 1)
// URL : https://codeforces.com/contest/348/problem/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
const int B = 450;
long long arr[100005];
vector<int> v[100005];
long long sum[100005];
vector<int> hvy;
vector<long long> cnt[100005];
vector<int> brr[100005];
long long upd[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> Q;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int i =1 ; i<=M; i++){
		int k;
		cin >> k;
		if(k > B){
			hvy.push_back(i);
		}
		for(int j = 0; j<k; j++){
			int n;
			cin >> n;
			v[i].push_back(n);
			sum[i] += arr[n];
			if(k > B){
				brr[n].push_back(i);
			}
		}
	}
	int K = hvy.size();
	for(int i =1; i<=N; i++){
		cnt[i].resize(K);
		for(int n : v[i]){
			for(int i1 = 0, i2 = 0; i2<K && i1<brr[n].size(); i2++){
				if(brr[n][i1] == hvy[i2]){
					cnt[i][i2]++;
					i1++;
				}
			}
		}
	}
	while(Q--){
		char c;
		cin >> c;
		if(c == '?'){
			int n;
			cin >> n;
			long long s = 0;
			if(v[n].size() > B){
				s = sum[n];
			}
			else{
				for(int k : v[n]){
					s += arr[k];
				}
			}
			for(int k = 0; k<K; k++){
				s += cnt[n][k] * upd[hvy[k]];
			}
			cout << s << "\n";
		}
		else{
			int n;
			int x;
			cin >> n >> x;
			if(v[n].size() > B){
				upd[n] += x;
			}
			else{
				for(int k : v[n]){
					arr[k] += x;
				}
				for(int k = 0; k<K; k++){
					sum[hvy[k]] += cnt[n][k] * x;
				}
			}
		}
	}
}