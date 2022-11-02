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

ll d[200200];
ll e[200200];
int l, r;

ll en = 0;
int n, b;
ll x, y;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> b;
    for(int i = 0; i < n; i++){
    	scanf("%I64d %I64d", &x, &y);
    	while(l < r && x >= d[l]) l++;
    	//for(int j = l; j < r; j++)
    	//	cout << d[j] << " ";
		//cout << endl;
    	if(r - l > b) {
    		e[i] = -1;
    		continue;
    	}
    	en = max(x, en) + y;
    	e[i] = en; 
    	d[r] = en;
    	r++;
    }
    for(int i = 0; i < n; i++){
    	if(i) printf(" ");
    	printf("%I64d", e[i]);
    }



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}