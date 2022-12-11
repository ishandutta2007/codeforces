
// Problem : B. Running for Gold
// Contest : Codeforces - Codeforces Global Round 15
// URL : https://codeforces.com/contest/1552/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int arr[10][50005];
int bst[5];
int cnt[5];
set<int> st[50];
bool bad[10][50005];
bool ans[50005];

bool better(int i, int j){
	for(int m = 0; m < 32; m++){
		if(__builtin_popcount(m) == 3){
			bool good = 1;
			for(int t = 0; t < 5; t++){
				if(m>>t&1){
					if(arr[t][i] > arr[t][j]){
						good = 0;
					}
				}
			}
			if(good){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		priority_queue<pair<int, pair<int, int>>> pq;
		for(int k = 0; k < 32;k++){
			st[k].clear();
		}
		for(int i = 1; i <= N; i++){
			ans[i] = 1;
			for(int k = 0; k < 5; k++){
				cin >> arr[k][i];
				pq.push(make_pair(arr[k][i], make_pair(k, i)));
				bad[k][i] = 0;
			}
		}
		int bst = 1;
		for(int i = 2; i <= N; i++){
			if(better(i, bst)){
				bst = i;
			}
		}
		for(int i= 1; i <= N; i++){
			if(bst != i && better(i, bst)){
				bst = -1;
				break;
			}
		}
		cout << bst << "\n";
	}
}