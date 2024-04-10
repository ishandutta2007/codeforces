
// Problem : D. Game with Powers
// Contest : Codeforces - Codeforces Round #188 (Div. 1)
// URL : https://codeforces.com/contest/317/problem/D
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

vector<int> g = { 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, };
int cnt[50];
set<int> st;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	//cnt[1] = 1;
	for(int i = 2; i<=sqrt(N); i++){
		if(!st.count(i)){
			long long temp = i;
			int c = 0;
			while(temp <= N){
				st.insert(temp);
				temp *= i;
				c++;
			}
			cnt[c]++;
		}
	}
	cnt[1] = N - st.size();
	int X = 0;
	for(int i = 1; i<=30; i++){
		X ^= (cnt[i]&1)*(g[i-1]);
	}
	if(X){
		cout << "Vasya";
	}
	else{
		cout << "Petya";
	}
}