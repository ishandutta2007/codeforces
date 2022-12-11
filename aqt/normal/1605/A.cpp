
// Problem : A. A.M. Deviation
// Contest : Codeforces - Codeforces Round #754 (Div. 2)
// URL : https://codeforces.com/contest/1605/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>> T;
	while(T--){
		int a, b, c;
		cin >> a >> b >> c;
		int tot = a + b + c;
		int quo = tot/3;
		int rem = tot%3;
		a = b= c = quo;
		if(rem == 2){
			a++;
			b++;
		}
		else if(rem == 1){
			a++;
		}
		cout << abs(a + c - 2 * b) << "\n";
	}
}