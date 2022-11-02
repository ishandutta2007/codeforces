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


 
int a[1000100];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n, k;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
    	int r;
    	scanf("%d", &r);
    	a[r] = i;
    }
    ll sum = 0;
    for(int i = 2; i <= n; i++){
    	sum += abs(a[i] - a[i-1]);
    }
    cout << sum << endl;

    
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}