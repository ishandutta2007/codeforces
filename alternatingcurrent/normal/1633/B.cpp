#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int a = 0, b = 0;
		rep(i, (int)s.size()){
			a += (s[i] == '0');
			b += (s[i] == '1');
		}
		if(a == b)
			cout << a - 1 << endl;
		else
			cout << min(a, b) << endl;
	}
	return 0;
}