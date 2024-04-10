#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
bool check(ll secs){
    ll h = secs/60, m = secs%60;
    return (m%10 == 7 || h%10 == 7);
}
main(){
    FAST;
    ll x, h, m;
    cin >> x >> h >> m;
    ll mns = h*60+m, op = 0;
    while(!check(mns)) mns = (mns - x + 1440)%1440, ++op;
    cout << op;
}