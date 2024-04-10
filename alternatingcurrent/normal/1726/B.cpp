#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, m;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		if(m < n){
			cout << "No\n";
			continue;
		}
		if(n & 1){
			cout << "Yes\n";
			rep(i, n - 1)
				cout << "1 ";
			cout << m - n + 1 << "\n";
		} else {
			if(m & 1)
				cout << "No\n";
			else {
				cout << "Yes\n";
				rep(i, n - 2)
					cout << "1 ";
				cout << (m - n + 2) / 2 << " " << (m - n + 2) / 2 << "\n";
			}
		}
	}
	return 0;
}