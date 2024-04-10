
// Problem : F. Enchanted Matrix
// Contest : Codeforces - Codeforces Round #705 (Div. 2)
// URL : https://codeforces.com/contest/1493/problem/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
bool query(int h, int w, int a, int b, int p, int q){
	cout << "? " << h << " " << w << " " << a << " " << b << " " << p << " " << q << endl;
	int ret;
	cin >> ret;
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int oN = N, oM = M;
	{
		vector<int> f;
		int T = N;
		for(int i = 2; i<=N; i++){
			while(T%i == 0){
				f.push_back(i);
				T /= i;
			}
		}
		for(int v : f){
			bool good = 1;
			int p = N / v;
			for(int k = 0; (1<<k) * p < N; k++){
				if(2 * (1<<k) * p <= N){
					if(!query((1<<k) * p, M, 1, 1, 1 + (1<<k) * p, 1)){
						good = 0;
					}
				}
				else{
					if(!query(N-(1<<k) * p, M, 1, 1, 1 + (1<<k) * p, 1)){
						good = 0;
					}
				}
			}
			if(good){
				N /= v;
			}
		}
	}
	{
		vector<int> f;
		int T = M;
		for(int i = 2; i<=M; i++){
			while(T%i == 0){
				f.push_back(i);
				T /= i;
			}
		}
		for(int v : f){
			bool good = 1;
			int p = M / v;
			for(int k = 0; (1<<k) * p < M; k++){
				if(2 * (1<<k) * p <= M){
					if(!query(N, (1<<k) * p, 1, 1, 1, 1 + (1<<k) * p)){
						good = 0;
					}
				}
				else{
					if(!query(N, M-(1<<k) * p, 1, 1, 1, 1 + (1<<k) * p)){
						good = 0;
					}
				}
			}
			if(good){
				M /= v;
			}
		}
	}
	N = oN / N;
	M = oM / M;
	int ans = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(N % i == 0 && M % j == 0){
				ans++;
			}
		}
	}
	cout << "! " << ans << endl;
}