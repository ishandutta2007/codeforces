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
int n, k, a[6000], b[1000110], c[1000110];
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    sort(a, a+n);
    for(int i = 0; i<n; i++){
    	for(int j = 0; j<i; j++){
    		b[a[i] - a[j]]++;
    	}
    }   
    for(int m = 1; ; m++){
    	int cur = 0;
    	for(int  i = m + m; i<1000010; i+=m) b[m]+=b[i];
    	if(b[m] > k * (k + 1)/2) continue;
    	int x = 0;
    	for( ;x < n; x++){
    		if(!c[a[x] % m]) {
    			c[a[x] % m] = 1;
    		}
    		else {
    			cur++;
    		}
    	}
    	if(cur <= k){
    		cout << m << endl;
    		return 0;
    	}
    	for( int i = 0; i<x; i++){
    		c[a[i] %m] = 0;
    	}
    }
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}