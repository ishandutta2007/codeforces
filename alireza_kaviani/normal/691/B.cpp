#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , match[200];
string s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	match['A'] = 'A';
	match['b'] = 'd';
	match['d'] = 'b';
	match['H'] = 'H';
	match['I'] = 'I';
	match['M'] = 'M';
//	match['m'] = 'm';
//	match['n'] = 'n';
	match['O'] = 'O';
	match['o'] = 'o';
	match['p'] = 'q';
	match['q'] = 'p';
	match['T'] = 'T';
	match['U'] = 'U';
//	match['u'] = 'u';
	match['V'] = 'V';
	match['v'] = 'v';
	match['W'] = 'W';
	match['w'] = 'w';
	match['X'] = 'X';
	match['x'] = 'x';
	match['Y'] = 'Y';
	
	cin >> s; n = SZ(s);
	for(int i = 0 ; i < n ; i++){
		if(match[s[i]] != s[n - i - 1]){
			return cout << "NIE" << endl , 0;
		}
	}
	cout << "TAK" << endl;

    return 0;
}
/*

*/