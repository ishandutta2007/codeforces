#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+228;
string s[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	for(ll i = 0;i<n;i++){
		cin >> s[i];
	}
	for(ll i = n-2;i>=0;i--){
		for(ll j = 0;j<s[i].length();j++){
			if(j>=s[i+1].length()){
				s[i] = s[i].substr(0, s[i+1].length());
				break;
			}
			if(s[i][j] == s[i+1][j]){
				continue;
			}
			if(s[i][j] > s[i+1][j]){
				s[i] = s[i].substr(0, j);
				break;
			}else{
				break;
			}
		}
	}
	for(ll i = 0;i<n;i++) cout << s[i] << '\n';
}