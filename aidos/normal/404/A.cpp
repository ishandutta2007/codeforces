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
    char c[310][310];
    int n;
    set < char > s;
    cin >> n;
    for(int i =0; i<n; i++)
    	for(int j = 0; j <n; j++){
    		cin >> c[i][j];
    		s.insert(c[i][j]);
    	}
	if(n == 1){
		cout << "YES";
		return 0;
	}
	if(s.size() != 2){
		cout << "NO";
		return 0;
	}
	char y = c[0][0];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j || j == n - i - 1){
				if(y != c[i][j]){
					cout <<"NO";
					return 0;
				}
			}
			else if(y == c[i][j]){
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