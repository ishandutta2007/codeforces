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
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n;
    char c[111111];
    for(int i = 0; i < 100010; i++)
    	c[i] = ' ';
	cin >> n;
	int x;
	for(int i = 0; i<n; i++){
		string S;
		cin >> S;
		x = S.size();
		for(int j = 0; j < x; j++){
			if(S[j] != '?'){
				if(c[j] == '?') continue;
				if(c[j] == ' ')  c[j] = S[j];
				else if(c[j] != S[j]) c[j] = '?';
			}
		}
	}
	for(int i  =0; i < x; i++){
		if(c[i] == ' ' ) cout << 'a';
		else cout << c[i];
	}
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}