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
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;


char c[] = { 'q', 'r', 'b', 'n', 'p', 'k', 'Q', 'R', 'B', 'N', 'P', 'K'};
int d[]  = {9, 5, 3, 3, 1, 0, -9, -5, -3, -3, -1, 0};

int get(char x){
	if(x == '.') return 0;
	for(int i = 0; ; i++)
		if(c[i] == x) return d[i];
	return -1;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    string S;
    int a= 0;
    for(int i = 0; i < 8; i++){
    	cin >> S;
    	for(int j = 0; j < 8; j++){
    		a+=get(S[j]);
    	}
    }
    if(a > 0){
    	cout << "Black";
    }
    else if(a == 0) cout << "Draw";
    else cout << "White";

    




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}