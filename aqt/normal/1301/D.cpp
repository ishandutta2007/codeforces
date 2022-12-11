
// Problem : D. Time to Run
// Contest : Codeforces Round #619 (Div. 2)
// URL : https://codeforces.com/contest/1301/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	if(4*N*M-2*N-2*M < K){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	int crnt = 0;
	vector<pair<int, string>> v;
	if(M == 1){
		if(N-1+crnt <= K){
			v.push_back({N-1, "D"});
			crnt += N-1;
		}
		if(crnt != K){
			v.push_back({K-crnt, "U"});
			crnt = K;
		}
		assert(v.size() <= 3000);
		cout << v.size() << "\n";
		for(auto p : v){
			cout << p.first << " " << p.second << "\n";
		}
		return 0;
	}
	for(int i = 1; i<=N && crnt != K; i++){
		if((M-1) + crnt <= K){
			crnt += M-1;
			v.push_back({M-1, "R"});
		}
		else{
			v.push_back({K-crnt, "R"});
			crnt = K;
		}
		if(crnt == K || i == N){
			break;
		}
		if(3*(M-1) + crnt <= K){
			crnt += 3*(M-1);
			v.push_back({M-1, "DUL"});
		}
		else{
			int temp = K-crnt;
			if(temp/3 != 0){
				v.push_back({temp/3, "DUL"});
			}
			if(temp%3 == 1){
				v.push_back({1, "D"});
			}
			else if(temp%3 == 2){
				v.push_back({1, "DU"});
			}
			crnt = K;
		}
		if(crnt == K){
			break;
		}
		crnt++;
		v.push_back({1, "D"});
	}
	if(crnt+M-1 <= K){
		crnt += M-1;
		v.push_back({M-1, "L"});
	}
	else if(crnt != K){
		v.push_back({K-crnt, "L"});
		crnt = K;
	}
	if(crnt != K){
		v.push_back({K-crnt, "U"});
	}
	assert(v.size() <= 3000);
	cout << v.size() << "\n";
	for(auto p : v){
		cout << p.first << " " << p.second << "\n";
	}
}