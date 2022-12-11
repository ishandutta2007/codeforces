
// Problem : E2. Asterism (Hard Version)
// Contest : Codeforces - Codeforces Round #654 (Div. 2)
// URL : https://codeforces.com/contest/1371/problem/E2
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, P, M;
int arr[100005];
int pre[100005];
int bad[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> P;
	M = N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		M = max(M, arr[i]);
	}
	for(int i = 1; i<=N; i++){
		pre[max(1, N-M+arr[i])]++;
	}
	partial_sum(pre, pre+1+N, pre);
	for(int i = 1; i<=N; i++){
		bad[((i-pre[i])%P+P)%P]++;
	}
	vector<int> ans;
	for(int i = 1; i<=N; i++){
		if(!bad[i%P]){
			ans.push_back(i+M-N);
		}
		bad[((i-pre[i])%P+P)%P]--;
		bad[(i+N-pre[N])%P]++;
		//cout << (pre[i]+i)%P << " " << (pre[N]+i+N)%P << "\n";
		/*
		for(int p = 0; p<P; p++){
			cout << bad[p];
		}
		cout << "\n";
		*/
	}
	cout << ans.size() << "\n";
	for(int n : ans){
		cout << n << " ";
	}
}