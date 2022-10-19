#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) {
		int n;
		cin >> n;
		map<char,int>mp;
		rep(i, n) {
			string s;
			cin >> s;
			for(auto j : s) ++mp[j];
		}
		bool ans=true;
		for(char i='a'; i<='z'; ++i) {
			if(mp[i]%n!=0) ans=false;
		}
		cout << (ans?"YES":"NO") << '\n';
	}
}