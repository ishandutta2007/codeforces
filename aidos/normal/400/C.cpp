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
pii a[111000];
int n, m, xa, ya, z, p;
void move1(int x, int y){
	for(int i = 0; i<p; i++){
		swap(a[i].ff, a[i].sc);
		a[i].sc = x - a[i].sc + 1;
	}
}
void move2(int x, int y){
	for(int i = 0; i < p; i++){
		swap(a[i].ff, a[i].sc);
		a[i].ff = y - a[i].ff+1;
	}
}
void reversing(int x, int y){
	for(int i = 0; i < p; i++){
		a[i].sc = y - a[i].sc + 1;
	}
}
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif               
    cin >> n >> m >> xa >> ya >> z >> p;
    for(int i = 0; i<p; i++){
    	cin >> a[i].ff >> a[i].sc;
    }
    xa %= 4;
    for(int i = 0; i< xa; i++){
    	move1(n, m);
    	swap(n, m);
    }
    ya %= 2;
    if(ya) {
    	reversing(n, m);
    }
    z %= 4;
    for(int i = 0; i<z; i++){
    	move2(n, m);
    	swap(n, m);
    }
    for(int i = 0; i<p; i++){
    	cout << a[i].ff << " " << a[i].sc << endl;
    }
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}