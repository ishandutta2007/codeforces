
// Problem : B. Hills And Valleys
// Contest : Codeforces - Codeforces Round #695 (Div. 2)
// URL : https://codeforces.com/contest/1467/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
long long arr[300005];
int typ[300005];
vector<vector<int>> lst;

void gen(int n, vector<int> v){
	if(!n){
		lst.push_back(v);
		return;
	}
	for(int k = 1; k<=7; k++){
		v.push_back(k);
		gen(n-1, v);
		v.pop_back();
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
			arr[i] *= 2;
		}
		
		/*
		int N = 6;
		gen(N, {});
		for(auto v : lst){
			
			
			for(int i = 1; i<=N; i++){
				arr[i] = v[i-1];
			}
			*/
			fill(typ, typ+1+N, 0);
			int ans = 0;
			for(int i = 2; i<N; i++){
				if(arr[i-1] < arr[i] && arr[i+1] < arr[i]){
					typ[i] = 1;
				}
				else if(arr[i-1] > arr[i] && arr[i+1] > arr[i]){
					typ[i] = -1;
				}
				ans += !!typ[i];
			}
			/*
			int bfans = ans;
			for(int n = 1; n<=N; n++){
				int old = arr[n];
				for(int k = 0; k<=8; k++){
					int tmp = 0;
					arr[n] = k;
					for(int i = 2; i<N; i++){
						if(arr[i-1] < arr[i] && arr[i+1] < arr[i]){
							tmp++;
						}
						else if(arr[i-1] > arr[i] && arr[i+1] > arr[i]){
							tmp++;
						}
					}
					bfans = min(bfans, tmp);
				}
				arr[n] = old;
			}
			*/
			if(N <= 2){
				cout << 0 << "\n";
				continue;
			}
			int tot = ans;
			for(int i = 1; i<=N; i++){
				/*
				if(i == 1){
					if(typ[i+1]){
						ans = min(ans, tot-1);
					}
				}
				else if(i == N){
					if(typ[i-1]){
						ans = min(ans, tot-1);
					}
				}
				else{
					if(typ[i-1] && typ[i+1]){
						if(typ[i-1] == typ[i+1]){
							ans = min(ans, tot-2-!!typ[i]);
						}
						else{
							ans = min(ans, tot-1-!!typ[i]);
						}
					}
					else if(typ[i-1] || typ[i+1]){
						ans = min(ans, tot-!!typ[i]-1);
					}
					ans = min(ans, tot-!!typ[i]);
				}
				*/
				vector<int> val;
				if(i != 1){
					val.push_back(arr[i-1]);
				}
				if(i != N){
					val.push_back(arr[i+1]);
				}
				if(val.size() == 2){
					val.push_back((val[0]+val[1])/2);
				}
				val.push_back(0);
				val.push_back(2000000001LL);
				long long old = arr[i];
				for(auto v : val){
					int tmp = 0;
					arr[i] = v;
					for(int j = max(2, i-1); j<=min(N-1, i+1); j++){
						if(arr[j-1] < arr[j] && arr[j+1] < arr[j]){
							tmp++;
						}
						else if(arr[j-1] > arr[j] && arr[j+1] > arr[j]){
							tmp++;
						}
						tmp -= !!typ[j];
					}
					ans = min(ans, tot+tmp);
				}
				arr[i] = old;
			}
			/*
			if(bfans != ans){
				for(int n = 1; n<=N; n++){
					cout << arr[n] << " ";
				}
				cout << "\n";
				cout << ans << " " << bfans << "\n";
				return 0;
			}
			*/
			cout << ans << "\n";
		//}
	}
}