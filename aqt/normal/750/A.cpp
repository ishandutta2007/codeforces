
// Problem : A. New Year and Hurry
// Contest : Codeforces - Good Bye 2016
// URL : https://codeforces.com/contest/750/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	int ans = 0;
	for(int i = 1; i<=N; i++){
		if(i*5+M <= 240){
			M += i*5;
			ans = i;
		}
	}
	cout << ans;
}