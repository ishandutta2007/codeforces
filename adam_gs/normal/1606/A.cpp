#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int ab(string s) {
	int ans=0;
	rep(i, s.size()-1) if(s[i]=='a' && s[i+1]=='b') ++ans;
	return ans;
}
int ba(string s) {
	int ans=0;
	rep(i, s.size()-1) if(s[i]=='b' && s[i+1]=='a') ++ans;
	return ans;
}
void solve() {
	string s;
	cin >> s;
	if(ab(s)==ba(s)) {
		cout << s << '\n';
		return;
	}
	if(s[0]=='a') s[0]='b';
	if(s[0]=='b') s[0]='a';
	if(ab(s)==ba(s)) {
		cout << s << '\n';
		return;
	}
	if(s[0]=='a') s[0]='b';
	if(s[0]=='b') s[0]='a';
	if(s[s.size()-1]=='a') s[s.size()-1]='b';
	if(s[s.size()-1]=='b') s[s.size()-1]='a';
	cout << s << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}