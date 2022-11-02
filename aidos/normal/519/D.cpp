#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

map< ll, int > m[27];

ll x[27];
string S;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    for(int i = 0; i < 26; i++) cin >> x[i];
    cin >> S;

    ll cnt = 0;

    ll ans = 0;
    for(int i = 0; i < S.size(); i++){
    	if(m[S[i] - 'a'].count(cnt)){
    		ans += m[S[i] - 'a'][cnt];
    	}
    	cnt+= x[S[i] - 'a'];
    	m[S[i] - 'a'][cnt]++;
    }
    cout << ans << endl;




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}