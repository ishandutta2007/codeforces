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

void out2(int x){
	if(x > 9) out2(x/10);
	putchar(x%10 + '0');
}
void out(int x){
	out2(x);
	putchar(' ');
}



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n;

    for(int i = 1; i  < n ; i++, i++)
    	out( i );
    if(n&1) out(n);
    for(int i = n - 1; i>0; i--)
    	if(i&1) out( i );
	
    for(int i = 2; i  < n ; i++, i++)
    	out( i );
    if(!(n & 1)) out(n);
    for(int i = n - 1; i>0; i--)
    	if(i % 2 < 1) out( i );
    out(n);




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}