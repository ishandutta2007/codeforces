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

int n, a[200200];
int p;
int l[200200];
int r[200200];
int d[200200];

int cnt(int l, int r){
	int cnt1 = (r)/p;
	int cnt2 = (l - 1)/p;
	return cnt1 - cnt2;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> p;  
	for(int i = 0; i < n; i++)
		cin >> l[i] >> r[i];	
	
	for(int i = 0; i < n; i++)
		d[i] = cnt( l[i], r[i]);
	long double ans = 0.0;
	for(int i = 0; i < n; i++){
		int j = (i + 1) % n;
		ans += d[i] * 4000.0 /(r[i] - l[i] + 1.0);
	}

	for(int i = 0; i < n; i++){
		int j = (i + 1) % n;
		long double c = d[i] * 2000.0 /(r[i] - l[i] + 1.0); 
		c *= d[j];
		 c/= (r[j] - l[j] + 1.0);
		 ans -= c;
	}
	printf("%.16f", (double)ans);

	



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}