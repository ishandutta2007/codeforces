
// Problem : D. Rating Compression
// Contest : Codeforces - Codeforces Global Round 12
// URL : https://codeforces.com/contest/1450/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
int arr[300005];
int perm[300005];

bool isperm(int n){
	sort(perm+1, perm+1+n);
	for(int i= 1; i<=n;i ++){
		if(i != perm[i]){
			return 0;
		}
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
		}
		int l = 2, r = N, ans = N+1;
		while(l <= r){
			int mid = l+r>>1;
			deque<int> dq;
			for(int i = 1; i<mid; i++){
				while(dq.size() && arr[dq.back()] >= arr[i]){
					dq.pop_back();
				}
				dq.push_back(i);
			}
			for(int i= mid; i<=N; i++){
				while(dq.size() && arr[dq.back()] >= arr[i]){
					dq.pop_back();
				}
				dq.push_back(i);
				if(dq.front() == i - mid){
					dq.pop_front();
				}
				perm[i-mid+1] = arr[dq.front()];
			}
			/*
			for(int i = 1; i<=N-mid+1; i++){
				cout << perm[i] << " ";
			}
			cout << "\n";
			cout << "res: " << isperm(N-mid+1) << "\n";
			*/
			if(isperm(N-mid+1)){
				ans = mid;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		for(int i = 1; i<=N; i++){
			perm[i] = arr[i];
		}
		cout << isperm(N);
		for(int i = 2; i<=N; i++){
			cout << (i >= ans);
		}
		cout << "\n";
	}
}