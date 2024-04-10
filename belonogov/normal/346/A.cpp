#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = -1;
const int inf = 1e9;

int gcd(int a, int b){
    return (b == 0) ? a: gcd(b, a % b); 
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, d = -1, mx = 0, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        mx = max(mx, x);
        d = (d == -1) ? x : gcd(d, x);      
    }
    mx /= d;
    cout << (((mx - n) % 2 == 0)? "Bob\n": "Alice\n"); 
 
    return 0;
}