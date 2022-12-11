
// Problem : A. Cow and Haybales
// Contest : Codeforces Round #621 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1307/problem/A
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int T;
int arr[105];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int N, D;
		cin >> N >> D;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
		}
		int idx = 1;
		int ans = 0;
		while(D > 0){
			//cout << T << " " << D << endl;
			while(idx <= N && arr[idx] == 0){
				idx++;
			}
			if(idx == N+1){
				break;
			}
			if(D < idx-1){
				break;
			}
			else{
				arr[idx]--;
				D -= idx-1;
				ans++;
			}
		}
		cout << ans << "\n";
	}
}