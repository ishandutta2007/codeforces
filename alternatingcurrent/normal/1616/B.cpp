#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> s;
		int pos = 0;
		bool has = 0;
		while(pos + 1 < n && (s[pos + 1] < s[pos] || (has && s[pos + 1] == s[pos]))){
			if(s[pos + 1] < s[pos])
				has = 1;
			pos++;
		}
		for(int i = 0; i <= pos; i++)
			cout << s[i];
		for(int i = pos; i >= 0; i--)
			cout << s[i];
		cout << endl;
	}
	return 0;
}