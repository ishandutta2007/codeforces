#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int MOD = 1e9 + 7;


ll fi(ll x) {
    vector<pair<ll,ll>> tmp;
    for (ll i = 2; i * i <= x; i++) {
        int cnt = 0;
        for (; x % i == 0; x /= i)
            cnt++;
        if (cnt > 0)
            tmp.pb(mp(i, cnt));
    }
    if (x != 1)
        tmp.pb(mp(x, 1));
    ll res = 1;
    for (auto y: tmp) {
        ll h = y.F - 1;
        for (ll i = 1; i < y.S; i++)
            h *= y.F;
        res *= h;
    }
    return res;

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    ll n, k; 
    scanf("%lld%lld", &n, &k);
    ll res = n;    
    for (int i = 0; i < (k + 1) / 2; i++) {
        if (res == 1) 
            break;
        res = fi(res);
    }
    //for (int i = 0; i < 20; i++)
        //db2(i, fi(i));

    cout << res % MOD << endl;

    return 0;
}