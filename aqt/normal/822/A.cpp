
// Problem : A. I'm bored with life
// Contest : Codeforces - Codeforces Round #422 (Div. 2)
// URL : https://codeforces.com/contest/822/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long A, B;
	cin >> A >> B;
	if(A > B){
		swap(A, B);
	}
	long long ans = 1;
	for(int i = 1; i<=A; i++){
		ans *= i;
	}
	cout << ans;
}