#include <bits/stdc++.h>
using namespace std;
string yay(string a, string b){
	int n = a.length();
	string c = "";
	for(int i=0;i<n;i++){
		if(a[i] == b[i]) c += '0';
		else c += '1';
	}
	return c;
}
void solve(){
	int n;
	cin >> n;
	vector<string> v1(n), v2(n), v3(n);
	for(int i=0;i<n;i++) cin >> v1[i];
	for(int i=0;i<n;i++) cin >> v2[i];
	for(int i=0;i<n;i++) v3[i] = yay(v1[i],v2[i]);
	string p1(n,'0'), p2(n,'1');
	for(int i=1;i<n;i++){
		string tmp = yay(v3[0], v3[i]);
		if(tmp != p1 && tmp != p2){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for(int i=0;i<T;i++) solve();
}