
// Problem : C. Game On Leaves
// Contest : Codeforces - Codeforces Round #646 (Div. 2)
// URL : https://codeforces.com/contest/1363/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, X;
		cin >> N >> X;
		vector<int> dgr(N+5);
		for(int i = 1; i<N; i++){
			int a, b;
			cin >> a >> b;
			dgr[a]++, dgr[b]++;
		}
		if(dgr[X] <= 1){
			cout << "Ayush\n";
		}
		else if(N%2 == 0){
			cout << "Ayush\n";
		}
		else{
			cout << "Ashish\n";
		}
	}
}