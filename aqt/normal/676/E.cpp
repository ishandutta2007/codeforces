
// Problem : E. The Last Fight Between Human and AI
// Contest : Codeforces - Codeforces Round #354 (Div. 2)
// URL : https://codeforces.com/contest/676/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
const long long MOD = 1934995723;
vector<int> val;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	int cnt = 0;
	N++;
	for(int i = 1; i<=N; i++){
		string s;
		cin >> s;
		if(s == "?"){
			val.push_back(INT_MIN);
			cnt++;
		}
		else{
			bool neg = 0;
			if(s[0] == '-'){
				neg = 1;
				s.erase(s.begin(), s.begin()+1);
			}
			int n = 0;
			for(char c : s){
				n *= 10;
				n += c-'0';
			}
			val.push_back(neg ? -n : n);
		}
	}
	if(K == 0){
		if(val[0] == INT_MIN){
			cout << ((N-cnt)%2 ? "Yes\n" : "No\n");
		}
		else if(val[0] == 0){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	else{
		if(!cnt){
			reverse(val.begin(), val.end());
			long long v = 0;
			for(long long n : val){
				v *= K;
				v += n;
				v %= MOD;
			}
			if(!v){
				cout << "Yes\n";
			}
			else{
				cout << "No\n";
			}
		}
		else if(N%2 == 0){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
}