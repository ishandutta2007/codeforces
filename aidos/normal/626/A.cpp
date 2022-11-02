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

int n;
string a;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    cin >>a;
    int ans = 0;
    for(int i = 0; i < n; i++){
    	int cur1 = 0;
    	int cur2 = 0;
    	for(int j = i; j < n; j++){
    		if(a[j] == 'R') cur1++;
    		if(a[j] == 'L') cur1--;
    		if(a[j] == 'U') cur2++;
    		if(a[j] == 'D') cur2--;
    		ans += (cur1 == 0 && cur2 == 0);
    	}
    }
    cout << ans << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}