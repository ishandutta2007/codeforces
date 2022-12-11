
// Problem : B. Bear and Tower of Cubes
// Contest : Codeforces - Codeforces Round #356 (Div. 1)
// URL : https://codeforces.com/contest/679/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long N;
int arr[1005];

long long f(long long K){
	long long l = 1, r = 100000, ret = 0;
	while (l <= r){
		long long mid = l + r >> 1;
		if(mid * mid * mid <= K){
			ret = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return ret;
}

pair<long long, long long> solve(long long n){
	if(!n){
		return make_pair(0, 0);
	}
	long long c = f(n);
	auto tmp = solve(n - c * c * c);
	pair<long long, long long> ret = make_pair(tmp.first + 1, tmp.second + c * c * c);
	if(c > 1){
		long long l = (c-1)*(c-1)*(c-1);
		tmp = solve(c * c * c - 1 - l);
		tmp.second += l;
		tmp.first++;
		ret = max(ret, tmp);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	/*
	for(int i = 1; i <= N; i++){
		long long lst = pow(i, 1.0/3);
		lst = lst * lst * lst;
		arr[i] = arr[i - lst] + 1;
		cout << i << " " << arr[i] << "\n";
	}
	*/
	/*
	if(N <= 1000){
		long long bst = 0, val = 0;
		for(long long k = max(1LL, N - 2000000); k <= N; k++){
			if(solve(k) >= val){
				val = solve(k);
				bst = k;
			}
		}
		cout << val << " " << bst;
	}
	*/
	auto ret = solve(N);
	cout << ret.first << " " << ret.second << "\n";
}