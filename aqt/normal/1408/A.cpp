
// Problem : A. Circle Coloring
// Contest : Codeforces - Grakn Forces 2020
// URL : https://codeforces.com/contest/1408/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int a[105], b[105], c[105];
int ans[105];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i =0; i<N; i++){
			cin >> a[i];
		}
		for(int i = 0; i<N; i++){
			cin >> b[i];
		}
		for(int i = 0; i<N; i++){
			cin >> c[i];
		}
		ans[0] = a[0];
		for(int i = 1; i<N-1; i++){
			if(ans[i-1] == a[i]){
				ans[i] = b[i];
			}
			else{
				ans[i] = a[i];
			}
		}
		if(a[N-1] != ans[N-2] && a[N-1] != ans[0]){
			ans[N-1] = a[N-1];
		}
		else if(b[N-1] != ans[N-2] && b[N-1] != ans[0]){
			ans[N-1] = b[N-1];
		} 
		else{
			ans[N-1] = c[N-1];
		}
		for(int i = 0; i<N; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}