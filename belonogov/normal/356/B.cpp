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

string x, y;
int a[26];

long long gcd(long long a, long long b){
    return (b == 0)? a: gcd(b, a % b);
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    long long n, m, kof, d, ans = 0, sum, n_x, n_y, nok;
    cin >> n >> m;
    cin >> x >> y;
    n_x = x.length();
    n_y = y.length();
    
    nok = n_x * n_y / gcd(n_x, n_y);
    assert(n * n_x % nok == 0);
    kof = n * n_x / nok;
    d = gcd(n_x, n_y);
    for (int i = 0; i < d; i++){
        memset(a, 0, sizeof(a));
        for (int j = i; j < n_y; j += d)
            a[y[j] - 'a']++;
        sum = n_y / d;
        for (int j = i; j < n_x; j += d)
            ans += sum - a[x[j] - 'a'];
    }
    cout << ans * kof << endl;
    
    
 
 
    return 0;
}