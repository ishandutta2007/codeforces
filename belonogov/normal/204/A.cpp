#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

const int maxn = 1e5 + 10;
const int inf = 1e8;


ll solve(ll x){
    ll x1 = x, ans;

    if (x < 10)
        return x;
    for(; x1 >= 10; x1 /= 10);

    ans = x / 10 + 8;
    if (x1 <= x % 10)
        ans++;
    return ans;
}




int main(){
    //freopen("in", "r", stdin);
    ll l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1);
    return 0;
}