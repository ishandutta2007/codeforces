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
bool used[3][2222];
bool m[3][2222][2222];
int n;
void dfs(int h, int v){
	used[h][v]  =  1;
	for(int i = 0; i < n; i++){
		if(m[h][v][i] && !used[h][i]){
			dfs(h, i);
		}
	}
}
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		int x;
    		scanf("%d", &x);
    		m[0][i][j] = (x!=0);
    		m[1][j][i] = m[0][i][j];
    	}

    }
    dfs(1, 0);
    dfs(0, 0);
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < 2; j++){
    		if(!used[j][i]){
    			cout << "NO";
    			return 0;
    		}
    	}
    }
    cout << "YES";
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}