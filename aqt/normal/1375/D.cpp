
// Problem : D. Replace by MEX
// Contest : Codeforces - Codeforces Global Round 9
// URL : https://codeforces.com/contest/1375/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
int arr[1005];
int fre[1005];
int org[1005];

bool chk(){
	for(int i = 1; i<N; i++){
		if(arr[i] > arr[i+1]){
			return 0;
		}
	}
	return 1;
}

int getmex(){
	for(int j = 0; j<=N; j++){
		if(!fre[j]){
			return j;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		fill(fre, fre+1+N, 0);
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
			fre[arr[i]]++;
			org[i] = arr[i];
		}
		vector<int> ans;
		while(!chk()){
			int n = getmex();
			bool filled = 1;
			for(int i = 1; i<=n; i++){
				if(arr[i] != i-1){
					filled = 0;
					break;
				}
			}
			int idx = n;
			if(filled){
				idx++;
			}
			ans.push_back(idx);
			fre[arr[idx]]--;
			arr[idx] = n;
			fre[arr[idx]]++;
		}
		/*
		for(int i = 1; i<=N; i++){
			int t = getmex();
			if(t == N){
				break;
			}
			if(arr[i] != t){
				ans.push_back(i);
				fre[arr[i]]--;
				arr[i] = t;
				fre[arr[i]]++;
			}
		}
		*/
		/*
		bool dec = 0;
		if(getmex() == N){
			dec = 1;
		}
		*/
		/*
		cout << "here" << endl;
		for(int i = 1; i<=N; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
		*/
		/*
		while(!chk()){
			int n = getmex();
			//cout << n << endl;
			/*
			int idx = min(N, n+1-dec);
			fre[arr[idx]]--;
			arr[idx] = n;
			fre[n]++;
			ans.push_back(idx);
			bool filled = 1;
			for(int i = 1; i<=n; i++){
				if(arr[i] != i-1){
					filled = 0;
					break;
				}
			}
			int idx = n;
			if(filled){
				idx++;
			}
			ans.push_back(idx);
			fre[arr[idx]]--;
			arr[idx] = n;
			fre[arr[idx]]++;
		}
		*/
		/*
		if(ans.size() > 2*N){
			for(int i = 1; i<=N; i++){
				cout << org[i] << "\n";
			}
			return 0;
		}
		*/
		assert(ans.size() <= 2*N);
		cout << ans.size() << "\n";
		for(int n : ans){
			cout << n << " ";
		}
		cout << "\n";
		/*
		for(int n = 1; n<=N; n++){
			cout << arr[n] << " ";
		}
		cout << "\n";
		*/
		
	}
}