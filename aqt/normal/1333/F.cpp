
// Problem : F. Kate and imperfection
// Contest : Codeforces Round #632 (Div. 2)
// URL : https://codeforces.com/contest/1333/problem/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		int f = 1;
		for(int j = 2; j<=sqrt(i); j++){
			if(i%j == 0){
				f = i/j;
				break;
			}
		}
		v.push_back(f);
	}
	sort(v.begin(), v.end());
	for(int i = 2; i<=N; i++){
		cout << v[i-1] << " ";
	}
}