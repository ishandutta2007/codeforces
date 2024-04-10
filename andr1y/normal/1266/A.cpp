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
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll zeros = 0, ps = 0, sm=0;
		string s;
		cin >> s;
		for(ll i =0;i<s.length();i++){
			if(s[i] == '0') zeros++;
			if((s[i]-'0')%2 == 0) ps++;
			sm += s[i]-'0';
		}
		if(sm%3 != 0 || zeros == 0 || ps -1 <= 0) cout << "cyan" << endl;
		else cout << "red" << endl;
	}
}