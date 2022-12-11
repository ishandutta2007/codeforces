
// Problem : D. Multiple Testcases
// Contest : Codeforces - Educational Codeforces Round 86 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1342/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[200005];
int lim[200005];
int fre[200005];
vector<int> out[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	cin >> N >> K;
	for(int i =1 ; i<=N; i++){
		cin >> arr[i];
		fre[arr[i]]++;
	}
	sort(arr+1, arr+1+N);
	for(int i = K; i; i--){
		fre[i] += fre[i+1];
	}
	int A = 0;
	for(int i = 1; i<=K; i++){
		int n;
		cin >> n;
		A = max(A, (fre[i] + n - 1)/n);
	}
	for(int i = 1; i<=N; i++){
		out[(i-1)%A].push_back(arr[i]);
	}
	cout << A << "\n";
	for(int i = 0; i<A; i++){
		cout << out[i].size() << " ";
		for(int n : out[i]){
			cout << n << " ";
		}
		cout << "\n";
	}
}