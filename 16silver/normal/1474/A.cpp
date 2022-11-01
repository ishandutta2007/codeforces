#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string t;
	int cur = '0';
	for(char c : s){
		if(c+1 == cur){
			t += '0';
			cur = c;
		}
		else{
			t += '1';
			cur = c+1;
		}
	}
	cout << t << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for(int i=0;i<T;i++) solve();
}