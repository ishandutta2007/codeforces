
// Problem : E. Balanced Binary Search Trees
// Contest : Codeforces - Codeforces Global Round 5
// URL : https://codeforces.com/contest/1237/problem/E
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x = 0;
	cin >> N;
	while(x <= N){
		if(x == N || x+1 == N){
			cout << 1 << "\n";
			return 0;
		}
		if(x%2 == 0){
			x += 1 + x;
		}
		else{
			x += 2 + x;
		}
	}
	cout << 0 << "\n";
}