#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
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
map<pair<int,int>,char>mp;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int obie=0, rowne=0;
	while(m--) {
		char t;
		cin >> t;
		if(t=='+') {
			int a, b;
			char c;
			cin >> a >> b >> c;
			mp[{a, b}]=c;
			if(mp[{b, a}]) {
				++obie;
				if(mp[{b, a}]==c) ++rowne;
			}
		} else if(t=='-') {
			int a, b;
			cin >> a >> b;
			if(mp[{b, a}]) {
				--obie;
				if(mp[{b, a}]==mp[{a, b}]) --rowne;
			}
			mp[{a, b}]=0;
		} else {
			int a;
			cin >> a;
			if(a%2==1) {
				cout << (obie?"YES":"NO") << '\n';
			} else {
				cout << (rowne?"YES":"NO") << '\n';
			}
		}
	}
}