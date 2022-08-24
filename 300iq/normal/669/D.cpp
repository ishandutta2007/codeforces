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
    
int main() {
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    #ifndef __linux__
    #endif
    int n, q, t, x;
 	scanf("%d%d", &n, &q);   
 	int a = 0, b = 1;
 	forn (i, q) {
 		scanf("%d", &t);
 		if (t == 1) {
 			scanf("%d", &x);
 			a += x;
 			b += x;
 			a %= n;
 			b %= n;
 			if (a < 0) {
 				a += n;
 			}
 			if (b < 0) {
 				b += n;
 			}
 		} else {
 			if (a & 1) {
 				a--;
 				a %= n;
 				if (a < 0) {
 					a += n;
 				}
 			} else {
 				a++;
 				a %= n;
 				if (a < 0) {
 					a += n;
 				}
 			}
 			if (b & 1) {
 				b--;
 				b %= n;
 				if (b < 0) {
 					b += n;
 				}
 			} else {
 				b++;
 				b %= n;
 				if (b < 0) {
 					b += n;
 				}
 			}
 	 	}
 	}
 	vector <int> cur(n);
 	for (int i = 0; i < n; i += 2) {
 		cur[a] = i; 
 		a += 2;
 		a %= n; 
 	}
 	for (int i = 1; i < n; i += 2) {
 		cur[b] = i; 
 		b += 2;
 		b %= n; 
 	}
 	forn (i, n) {
 		printf("%d ", cur[i] + 1);
 	}
 	puts("");
}