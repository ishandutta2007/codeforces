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
	int n, p, a[30];
	cin >> n >> p;
	int sum = 2*n + p;
	for(int i = 1; i<n && sum > 0; i++){
		for(int j = i+1; j<=n && sum > 0; j++){
			cout << i << " " << j << endl;
			sum--;
		}
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
    }
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}