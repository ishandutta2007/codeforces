#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

ll poww(ll x , ll y){
    ll ans = 1;
    for( ; y ; y >>= 1 , x = x * x % MOD){
        if(y & 1){
            ans = ans * x % MOD;
        }
    }
    return ans;
}

ll n , k , ans , cur , invk , P[MAXN] , mark[MAXN] , fen[MAXN] , val[MAXN];
vector<int> vec;

void add(int x , int v){
    for(x++; x < MAXN ; x += x & -x)    fen[x] += v;
}

int get(int x){
    int ans = 0;
    for(x++; x ; x -= x & -x)   ans += fen[x];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> P[i];
        if(P[i] != -1){
            mark[P[i]] = 1;
            ans += get(n) - get(P[i]);
            add(P[i] , 1);
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(!mark[i]){
            k++; vec.push_back(i);
        }
    }
    invk = poww(k , MOD - 2);
    for(int i = 1 ; i <= n ; i++){
        if(mark[i]){
            val[i] = lower_bound(all(vec) , i) - vec.begin();
            cur += k - val[i];
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(P[i] == -1){
            ans = (ans + cur * invk) % MOD;
        }
        else{
            cur = cur - k + 2 * val[P[i]];
        }
    }
    ans = (ans + k * (k - 1) / 2 % MOD * poww(2 , MOD - 2)) % MOD;
    cout << ans << endl;

    return 0;
}
/*

*/