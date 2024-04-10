#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> s;
		char val = '9';
		if((int)s.size() == 2){
			cout << s[1] << endl;
		} else {
			rep(i, (int)s.size())
				val = min(val, s[i]);
			cout << val << endl;
		}
	}
	return 0;
}