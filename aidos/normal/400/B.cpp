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
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    set < int > s;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
    	string t;
    	cin >> t;
    	int v1, v2;
    	for(int j = 0; j < m; j++){
    		if(t[j] == 'G'){
    			v1 = j;
    		}
    		else if(t[j] == 'S') v2 = j;
    	}
    	s.insert(max(v2 - v1, -1));
    }
    if(s.find(-1) != s.end()) cout << -1;
    else {
    	cout << s.size();
    }
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}