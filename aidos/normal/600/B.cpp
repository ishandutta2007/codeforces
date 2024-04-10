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


int n, m;
int a[200200];
int b[200200];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    	cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < m; i++)
		cin >> b[i];
	for(int i = 0; i < m; i++){
		int pos= upper_bound(a, a+ n, b[i]) - a;
		cout << pos << " ";
	}




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}