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
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-10;
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

	string s[8];
	for(int i = 0; i < 8; i++)
		cin >> s[i];

	int a = INT_MAX, b = INT_MAX;

	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(s[i][j] == 'W'){
				bool ok = true;
				for(int z = i - 1; z >= 0; z--)
					if(s[z][j] != '.')
						ok = false;
				if(ok)
					a = min(a, i);
			}else if(s[i][j] == 'B'){
				bool ok = true;
				for(int z = i + 1; z < 8; z++)
					if(s[z][j] != '.')
						ok = false;
				if(ok)
					b = min(8 - i - 1, b);
			}
		}
	}

	cout << (a <= b ? "A" : "B");

}