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
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
void solve(){
	string t, s[20];
	cin >> t;
	vector < pii > v;
	for(int i = 1; i <= 12; i++){
		if(12 % i == 0){
			int x = i, u = 12/i;

			for(int j = 0; j < u; j++){
				s[j] = "";
				for(int k = j*i; k < i*(j+1); k++){
					s[j]+=t[k];
				}	
			}
			bool ans = 0;
			for(int j = 0; j < x; j++){
				bool ok = 0;
				if(s[0][j] == 'X') ok = 1;
				for(int k = 1; k < u; k++){
					if(s[k][j] != s[k-1][j]) ok = 0;
				}
				ans |= ok;
			}
			if(ans) v.pb(mp(u, x));
		}

	}
	sort(v.begin(), v.end());
	cout << v.size();
	for(int i = 0; i<v.size(); i++){
		cout << " " << v[i].ff << "x" << v[i].sc;
	}
}
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
    	solve();
    	if(i != t-1) cout << endl;
    }
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}