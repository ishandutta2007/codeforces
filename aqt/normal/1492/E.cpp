
// Problem : E. Almost Fault-Tolerant Database
// Contest : Codeforces - Codeforces Round #704 (Div. 2)
// URL : https://codeforces.com/contest/1492/problem/E
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr[250005];

vector<int> diff(int i, int j, int bad = M){
	vector<int> ret;
	for(int k = 0; k < M; k++){
		if(arr[i][k] != arr[j][k] && k != bad){
			ret.emplace_back(k);
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			int a;
			cin >> a;
			arr[i].emplace_back(a);
		}
	}
	arr[0].resize(M);
	for(int i = 2; i <= N; i++){
		auto dif = diff(1, i);
		if(dif.size() > 4){
			cout << "No\n";
			return 0;
		}
		else if(dif.size() == 4){
			for(int msk = 0; msk < (1 << 4); msk++){
				for(int k = 0; k < M; k++){
					arr[0][k] = arr[1][k];
				}
				for(int t = 0; t < 4; t++){
					if(msk>>t&1){
						arr[0][dif[t]] = arr[i][dif[t]];
					}
				}
				bool good = 1;
				for(int j = 1; j <= N; j++){
					if(diff(0, j).size() > 2){
						good = 0;
					}
				}
				if(good){
					cout << "Yes\n";
					for(int n : arr[0]){
						cout << n << " ";
					}
					return 0;
				}
			}
			cout << "No\n";
			return 0;
		}
		else if(dif.size() == 3){
			for(int a = 0; a < 3; a++){
				for(int b = 0; b < 3; b++){
					for(int c = 0; c < 3; c++){
						if(a == b || b == c || a == c){
							continue;
						}
						int idxa = dif[a];
						int idxb = dif[b];
						int idxc = dif[c];
						for(int k = 0; k < M; k++){
							arr[0][k] = arr[1][k];
						}
						arr[0][idxb] = arr[i][idxb];
						int badidx = idxc;
						bool good = 1;
						for(int j = 1; j <= N; j++){
							auto ret = diff(0, j, badidx);
							if(ret.size() > 2){
								good = 0;
							}
							else if(ret.size() == 2 && badidx == idxc){
								arr[0][badidx] = arr[j][badidx];
								badidx = M;
							}
						}
						if(good){
							if(badidx == idxc){
								arr[0][idxc] = arr[1][idxc];
							}
							cout << "Yes\n";
							for(int n : arr[0]){
								cout << n << " ";
							}
							return 0;
						}
					}
				}
			}
			cout << "No\n";
			return 0;			
		}
	}
	cout << "Yes\n";
	for(int n : arr[1]){
		cout << n << " ";
	}
}