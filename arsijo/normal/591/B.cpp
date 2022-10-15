#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-8;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	char ar[26];
	for(int i = 0; i < 26; i++)
		ar[i] = 'a' + i;

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	while(m--){
		char c1, c2;
		cin >> c1 >> c2;
		for(int i = 0; i < 26; i++){
			if(ar[i] == c1)
				ar[i] = c2;
			else if(ar[i] == c2)
				ar[i] = c1;
		}
	}

	for(int i = 0; i < (int) s.size(); i++)
		cout << ar[s[i] - 'a'];

}