#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T, n;
string s[2];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> s[0] >> s[1];
		bool yes = 1;
		rep(i, n){
			bool ok = 0;
			if(s[0][i] == '0' || s[1][i] == '0'){
				ok = 1;
			}
			if(!ok){
				yes = 0;
				break;
			}
		}
		cout << (yes ? "YES" : "NO") << endl;
	} 
	return 0;
}