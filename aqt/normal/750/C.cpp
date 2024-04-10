
// Problem : C. New Year and Rating
// Contest : Codeforces - Good Bye 2016
// URL : https://codeforces.com/contest/750/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	long long l = LLONG_MIN, r = LLONG_MAX;
	long long tot = 0;
	for(int i = 1; i<=N; i++){
		long long d, c;
		cin >> d >> c;
		if(c == 1){
			l = max(l, 0-tot);
		}
		else{
			r = min(r, -1-tot);
		}
		tot += d;		
	}
	if(l > r){
		cout << "Impossible\n";
	}
	else if(r == LLONG_MAX){
		cout << "Infinity\n";
	}
	else{
		cout << r+1900+tot << "\n";
	}
}