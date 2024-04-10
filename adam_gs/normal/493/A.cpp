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
	string H, A;
	cin >> H >> A;
	map<pair<int,int>,int>mp;
	int n;
	cin >> n;
	while(n--) {
		int t, m;
		char c, k;
		cin >> t >> c >> m >> k;
		if(mp[{c, m}]>=2) continue;
		++mp[{c, m}];
		if(k=='r') ++mp[{c, m}];
		if(mp[{c, m}]>=2) {
			cout << (c=='h'?H:A) << " " << m << " " << t << '\n';
		}
	}
}