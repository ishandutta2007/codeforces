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
const int maxn = 2e5 + 10;
const int inf = 2e9;

ll a[maxn];

int main(){
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
    ll ans = 0;
    int n, d;
    ll uk, x;
    scanf("%d%d", &n, &d);
    forn(i, n)
        cin >> a[i];
    a[n] = inf;
    uk = 0;
    for(int i = 0; i < n; i++){
        for(; a[uk] - a[i] <= d; uk++);
        x = uk - i - 1;
        ans = ans + (x * (x - 1) / 2);
        cerr << "ans " << ans << endl;
    }
    cout << ans << endl;
    

    return 0;
}