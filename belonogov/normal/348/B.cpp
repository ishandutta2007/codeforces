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

const int maxn = 1e6 + 2;
const int inf = 1e9;

long long a[maxn];
int b[maxn];
vector < int > e[maxn];
long long sum = 0;

bool fast_fail(){
    cout << sum << endl;
    exit(0);    
}

long long gcd(long long a, long long b){
    return (b == 0)? a: gcd(b, a % b);  
}

void dfs(int v, int p){
    int ch = 0;
    long long c = 1, mn = -1, c_old, d;
    for (int i = 0; i < (int)e[v].size(); i++)
        if (e[v][i] != p){
            dfs(e[v][i], v);
            d = a[e[v][i]] / b[e[v][i]];
            assert(a[e[v][i]] % b[e[v][i]] == 0);
            c = c / gcd(c, d);
            c_old = c;
            c = c * d;
            if (c / d != c_old) fast_fail();
            
            ch++;
        }
    if (ch == 0){
        if (a[v] == 0) fast_fail();
        b[v] = a[v];
        return;     
    }
    long long k = -1;
    for (int i = 0; i < (int)e[v].size(); i++)
        if (e[v][i] != p)
            k = (k == -1) ? a[e[v][i]] / c: min(k, a[e[v][i]] / c);
    a[v] = ch * k * c;
    for (int i = 0; i < (int)e[v].size(); i++)
        if (e[v][i] != p){
            long long x = k * c * b[e[v][i]] / a[e[v][i]];
            mn = (mn == -1)? x: gcd(mn, x);
        }
    b[v] = mn;
    
    if (a[v] == 0) fast_fail(); 
}



int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, v, u;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];        
    }
    for (int i = 0; i < n - 1; i++){
        scanf("%d %d\n", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);     
    }
    dfs(0, -1);
    cout << sum - a[0] << endl;
        
    return 0;
}