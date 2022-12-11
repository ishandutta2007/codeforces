
// Problem : C. Product 1 Modulo N
// Contest : Codeforces - Codeforces Round #716 (Div. 2)
// URL : https://codeforces.com/contest/1514/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	long long prod = 1;
	set<int> st;
	for(int i = 1; i <= N; i++){
		int n = i;
		if(__gcd(n, N) == 1){
			prod *= n;
			prod %= N;
			st.insert(n);
		}
	}
	if(prod !=1){
		st.erase(prod);
	}
	cout << st.size() << "\n";
	for(int n : st){
		cout << n << " ";
	}
}