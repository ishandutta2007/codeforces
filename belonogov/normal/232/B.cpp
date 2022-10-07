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
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int maxn = 105;
const ll p = 1e9 + 7;

ll pow(ll x, ll st){
    assert(st >= 0);
    if (st == 0)
        return 1;
    if (st % 2 == 1)
        return (x * pow(x, st - 1)) % p;
    ll y = pow(x, st / 2);
    return (y * y) % p;
}

ll dp[maxn][maxn * maxn];
ll kof[maxn];
ll c[maxn];
ll c_kof[maxn][maxn];


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    ll m;
    int n, k;
    cin >> n >> m >> k;
    forn(i, n)
        kof[i] = (m - i + n - 1) / n;
//     cerr << "kof:\n";
//     forn(i, n)
//         cerr << kof[i] << " ";
//     cerr << endl;
    
    forn(i, n + 1){
            c[i] = 1;
            for(ll j = n; j > n - i; j--)
            c[i] = (c[i] * j) % p;
        for(ll j = 1; j <= i; j++)
            c[i] = (c[i] * pow(j, p - 2)) % p;
    }
//     cerr << "c:\n";
// //     forn(i, n + 1)
// //         cerr << c[i] << " ";
//     cerr << endl;
    forn(i, n + 1)
        forn(j, n + 1)
            c_kof[i][j] = pow(c[i], kof[j]);
    
    dp[0][0] = 1;
    forn(i, n)
        forn(j, k + 1)            
            forn(d, n + 1){
    if (j + d > k)
        continue;
//  dp[i + 1][j + d] = (dp[i + 1][j + d] + (dp[i][j] * pow(c[d], kof[i])) % p) % p;
    dp[i + 1][j + d] = (dp[i + 1][j + d] + (dp[i][j] * c_kof[d][i]) % p) % p;
  
            }
            
            
    cout << dp[n][k];
//     cerr << "ans\n";
//     cerr << dp[n][k] << endl;
    
    return 0;
}