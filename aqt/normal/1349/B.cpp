#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		bool isK = 0, isbig = 0;
		vector<int> v;
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			v.push_back(n);
			if(n == K){
				isK = 1;
			}
		}
		if(N == 1){
			if(v[0] == K){
				cout << "yes\n";
			}
			else{
				cout << "no\n";
			}
			continue;
		}
		for(int i = 1; i<N-1; i++){
			int cnt = 0;
			cnt += v[i-1] >= K;
			cnt += v[i] >= K;
			cnt += v[i+1] >= K;
			if(cnt >= 2){
				isbig = 1;
			}
		}
		for(int i = 1; i<N; i++){
			int cnt = 0;
			cnt += v[i-1] >= K;
			cnt += v[i] >= K;
			if(cnt == 2){
				isbig = 1;
			}
		}
		cout << ((isbig && isK) ? "yes" : "no") << "\n";
	}
}