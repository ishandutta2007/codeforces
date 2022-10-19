#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if(n % 7 == 0){
			cout << n << endl;
		} else {
			if(n / 7 * 7 / 10 == n / 10)
				cout << n / 7 * 7 << endl;
			else
				cout << (n / 7 + 1) * 7 << endl;
		}
	}
	return 0;
}