
// Problem : F. Nullify The Matrix
// Contest : Codeforces - Codeforces Round #685 (Div. 2)
// URL : https://codeforces.com/contest/1451/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int dia[505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		fill(dia, dia+N+M+1, 0);
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				int n;
				cin >> n;
				dia[i+j] ^= n;
			}
		}
		bool allzero = 1;
		for(int s = 0; s<=N+M; s++){
			allzero &= !dia[s];
		}
		if(allzero){
			cout << "Jeel" << "\n";
		}
		else{
			cout << "Ashish" << "\n";
		}
	}
}