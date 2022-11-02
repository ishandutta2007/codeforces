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



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    string s;
    cin >> s;
    string t ="";
    t += s[0];
    t += s[2];
    t += s[4];
    t += s[3];
    t += s[1];
    int c = 0;
    for(int i = 0; i < 5; i++)
    	c = c * 10 + t[i] - '0';
	int ans = 1;
	int mod = (1e5);
	for(int i = 0; i < 5; i++){
		ans = ans * 1ll * c % mod;
	}
	printf("%05d\n", ans);
    



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}