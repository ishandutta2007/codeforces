#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;



string s;
int n, p, q;
void ok(int l, int r){
	cout << l/p + r/q << endl;
	for(int i = 0; i < l; i+= p){
		for(int j = i; j < i + p; j++)
			cout << s[j];
		cout << endl;
	}
	for(int i = l; i < n; i+= q){
		for(int j = i; j < i + q; j++)
			cout << s[j];
		cout << endl;
	}
	exit(0);
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> p >> q >> s;
    for(int i = 0; i <= n; i++){
    	if( i % p == 0 && (n - i) % q == 0) ok(i, n - i);
    }
    cout << -1 << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}