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
    int a, b, c;
    cin >> a >> b >> c;
    if(a < 0) {a *= -1, b *= -1, c *= -1;}
	printf("%.12lf\n", (-b + sqrt(b * b - 4 * a * c))/(2.0 * a));

	printf("%.12lf\n", (-b - sqrt(b * b - 4 * a * c))/(2.0 * a));


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}