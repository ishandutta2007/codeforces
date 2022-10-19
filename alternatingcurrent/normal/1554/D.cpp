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
		if(n & 1){
			if(n >= 9){
				int num = (n - 7) / 2;
				rep(i, num)
					cout << 'a';
				cout << 'b';
				rep(i, num)
					cout << 'a';
				cout << "acbbcc" << endl;
			} else {
				rep(i, n)
					cout << (char)('a' + i);
				cout << endl;
			}
		} else {
			if(n >= 4){
				int num = (n - 2) / 2;
				rep(i, num)
					cout << 'a';
				cout << 'z';
				rep(i, num + 1)
					cout << 'a';
				cout << endl;
			} else {
				rep(i, n)
					cout << (char)('a' + i);
				cout << endl;
			}
		}
	}
	return 0;
}