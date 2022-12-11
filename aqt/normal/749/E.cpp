
// Problem : E. Inversions After Shuffle
// Contest : Codeforces - Codeforces Round #388 (Div. 2)
// URL : https://codeforces.com/contest/749/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005];
long long bitv[100005];
long long bitc[100005];

void upd(int t, int n, int v){
	while(n <= N){
		if(t){
			bitv[n] += v;
		}
		else{
			bitc[n] += v;
		}
		n += n&-n;
	}
}

long long query(int t, int n){
	long long ret = 0;
	while(n){
		if(t){
			ret += bitv[n];
		}
		else{
			ret += bitc[n];
		}
		n -= n&-n;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long double tot = 0;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];		
	}
	long double k = 2.0/N/(N+1);
	for(int i = 1; i<=N; i++){
		tot += query(1, arr[i]) * (N-i+1) / 2.0;
		tot += 1LL*N*(N+1)/2*(query(0, N) - query(0, arr[i])) - (query(1, N) - query(1, arr[i])) * (N-i+1) / 2.0;
		upd(0, arr[i], 1);
		upd(1, arr[i], i);
	}
	cout << setprecision(10) << tot*k << "\n";
}