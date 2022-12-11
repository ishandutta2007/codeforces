
// Problem : G. Common Divisor Graph
// Contest : Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1553/problem/G
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
const int M = 1000002;
int arr[300005];
int ans[300005];
int dsu[2 * M + 5];
set<pair<int, int>> st;
int sieve[M + 5];

int getrt(int n){
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	iota(dsu+1, dsu + 2 * M + 1, 1);
	for(int i = 2; i <= M; i++){
		if(!sieve[i]){
			for(int j = i; j <= M; j += i){
				sieve[j] = i;
			}
		}
	}
	for(int i = 1; i <= N; i++){
		cin >> arr[i];	
		int k = arr[i];
		while(k > 1){
			if(getrt(arr[i]) != getrt(sieve[k] + M)){
				dsu[getrt(arr[i])] = getrt(sieve[k] + M);
			}
			k /= sieve[k];
		}
	}
	for(int i = 1; i <= N; i++){
		vector<int> fct;
		int tmp = arr[i];
		while(tmp > 1){
			fct.emplace_back(getrt(sieve[tmp] + M));
			//cout << getrt(sieve[tmp] + M) << "\n";
			tmp /= sieve[tmp];
		}
		tmp = arr[i] + 1;
		while(tmp > 1){
			fct.emplace_back(getrt(sieve[tmp] + M));
			tmp /= sieve[tmp];
		}
		sort(fct.begin(), fct.end());
		fct.erase(unique(fct.begin(), fct.end()), fct.end());
		for(int a = 0; a < fct.size(); a++){
			for(int b = a+1; b < fct.size(); b++){
				//cout << a << " " << b << "\n";
				st.insert(make_pair(fct[a], fct[b]));
			}
		}
	}
	while(Q--){
		int a, b;
		cin >> a >> b;
		a = arr[a];
		b = arr[b];
		a = getrt(a);
		b = getrt(b);
		if(a == b){
			cout << 0 << "\n";
			continue;
		}
		if(a > b){
			swap(a, b);
		}
		if(st.count(make_pair(a, b))){
			cout << 1 << "\n";
		}
		else{
			cout << 2 << "\n";
		}
	}
}