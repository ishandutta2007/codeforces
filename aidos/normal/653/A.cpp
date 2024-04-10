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
int a[5111];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0,x; i < n; i++){
    	cin >> x;
    	a[x] = 1;
    }
    for(int j = 0; j < 2000; j++){
    	int sum = 0;
    	for(int i = 0; i < 3; i++)
    		sum += a[i + j];
		if(sum == 3){
			cout << "YES\n";
			return 0;
		}
    }
    cout << "NO\n";



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}