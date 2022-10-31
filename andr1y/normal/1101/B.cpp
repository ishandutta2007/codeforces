#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL
#define M 1000000007
#define N 500500
#define INF 101111111111111LL
using namespace std;
using python = void;

ll dp[N][5];
signed main(){
	FAST;
	string s;
	getline(cin, s);
	ll n = s.length();
	ll p1 = 0;
	for(;p1<n;p1++){
		if(s[p1] == '[') break;
	}
	for(;p1<n;p1++){
		if(s[p1] == ':') break;
	}
	if(p1 == n) {cout << "-1\n";return 0;}
	ll p2 = n-1;
	for(;p2>p1;p2--)
		if(s[p2] == ']') break;
	for(;p2>p1;p2--)
		if(s[p2] == ':') break;
	if(p2 <= p1) {cout << "-1\n";return 0;}
	ll r = 0;
	while(p1<p2){
		if(s[p1] == '|') r++;
		p1++;
	}
	cout << r+4 << endl;
}