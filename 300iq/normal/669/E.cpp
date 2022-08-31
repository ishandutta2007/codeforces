#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define mp make_pair
#define pb push_back
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define all(x) x.begin(), x.end()
    
using namespace std;
using namespace __gnu_pbds;
    
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

map <int, map <int, int> > t;

const int MAXT = (int) 1e9 + 7;

void inc(int p, int d, int x) {
	for (; p < MAXT; p += (p & -p)) {
		t[p][d] += x;
	}
}

int get(int p, int d) {
	int res = 0;
	for (; p > 0; p -= (p & -p)) {
		res += t[p][d];
	}
	return res;
}

int main() {
    #ifdef __linux__
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    #ifndef __linux__
        
    #endif
    int n;
    scanf("%d", &n);
    forn (i, n) {
    	int a, t, x;
    	scanf("%d%d%d", &a, &t, &x);
    	if (a == 1) {
    		inc(t, x, 1);
    	} else if (a == 2) {
    		inc(t, x, -1);
    	} else {
    		printf("%d\n", get(t, x));
    	}
    }
}