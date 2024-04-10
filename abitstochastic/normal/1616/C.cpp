#include<bits/stdc++.h>
using namespace std;

int V[73];

int main(){
	int T , N;
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> V[i];
		int ans = N - 1;
		for(int i = 1 ; i <= N ; ++i)
			for(int j = i + 1 ; j <= N ; ++j){
				double F = 1.0 * (V[j] - V[i]) / (j - i) , X = V[i] - i * F; int cnt = 0;
				for(int k = 1 ; k <= N ; ++k){
					X += F;
					cnt += abs(X - V[k]) < 1e-9;
				}
				ans = min(ans , N - cnt);
			}
		cout << ans << endl;
	}
	return 0;
}