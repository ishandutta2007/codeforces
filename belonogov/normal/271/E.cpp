#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>


using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr 
#endif 


typedef long long ll;
typedef vector < int > vi;

const int maxn = 2e5 + 10;
const int inf = (int)1e9;

int a[maxn];
long long m;

int gcd(int a, int b){
    if (b != 0) return gcd(b, a % b); return a;
}

long long calc(long long  x){
    long long ans = 0;
//     epr("x %d\n", (int)x);
    for(; x < m; x *= 2)
        ans += m - x;  
    return ans;
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, d, j;
    long long ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]), a[i]--;
    
    d = a[0];
    for(int i = 1; i < n; i++)
        d = gcd(d, a[i]);
    
    assert(d > 0);
    for(; d % 2 == 0; d /= 2);
//     epr("d %d\n", d);
    for(int i = 1; i * i <= d; i++)
        if (d % i == 0){
            j = d / i;
            ans += calc(i);
            if (j != i)
    ans += calc(j);
        }
    
    cout << ans << endl;
    
    
    
    return 0;
}