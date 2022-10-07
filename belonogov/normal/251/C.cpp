#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring> 
#include <vector>
#include <set>
#include <map>
#include <cassert>

typedef long long ll;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;
const int maxn = 4e5;
const int inf = 1e9;

int c[maxn];

int gcd(int a, int b){
    if (b != 0) return gcd(b, a % b);
    return a;   
}

int main(){
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
    ll a, b, ans = 0, y;
    int k, x, mod = 1, q, dist;
    cin >> a >> b >> k;
    for(int i = 1; i <= k; i++){
        q = gcd(i, mod);
        mod = mod * i / q;      
    }
//  cerr << "mod " << mod << endl;
    if (a - b > 800 * 1000){
        memset(c, -1, sizeof(c));
        c[a % mod] = 0;
//      cerr << "x " << a % mod << endl;
        for(int i = 1; true; i++){
            x = a % mod;
            q = 1;
            for(int j = 2; j <= k; j++)
                q = max(x % j, q);
            a = a - q;
            x = a % mod;
//          cerr << "q " << q << endl;
//          cerr << "x " << x << endl;
            if (c[x] != -1){
                ans = i;
//              cerr << "ans " << ans << endl;
                dist = i - c[x];
//              cerr << "dist " << dist << endl; 
                y = (a - b) / mod;
                ans += y * dist;
                a = a - y * mod;
                break;          
            }
            else
                c[x] = i;
        
        }
    }
//  return 0;
    for(;a > b;){
        x = a % mod;
        q = 1;
        for(int j = 2; j <= k; j++)
            if (x % j <= a - b)
                q = max(q, x % j);
        a -= q;
//      cerr << a << " ";
        ans++;      
    }
//  cerr << "\n";
    cout << ans << endl;
    return 0;
}