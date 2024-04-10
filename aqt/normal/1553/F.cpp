
// Problem : F. Pairwise Modulo
// Contest : Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1553/problem/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct FenwickTree{
	int N;
	vector<long long> bit;
	
	FenwickTree(int n){
		N = n;
		bit.resize(N + 5);
	}
	
	void upd(int n, int v){
		while(n <= N){
			bit[n] += v;
			n += (n & -n);
		}
	}
	
	long long query(int n){
		n = min(n, 300000);
		n = max(n, 0);
		long long ret = 0;
		while(n){
			ret += bit[n];
			n -= (n & -n);
		}
		return ret;
	}
};

FenwickTree cnt = FenwickTree(300000), sum = FenwickTree(300000), sub = FenwickTree(300000);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	long long ans = 0;
	for(int i = 1; i <= N; i++){
		int v;
		cin >> v;
		for(int j = v; j - v <= 300000; j += v){
			sub.upd(j, v);
			ans += sum.query(j - 1) - sum.query(j - v - 1) - (j - v) * (cnt.query(j - 1) - cnt.query(j - v - 1));
		}
		ans += 1LL * i * v - sub.query(v);
		cnt.upd(v, 1);
		sum.upd(v, v);
		cout << ans << " ";
	}
}