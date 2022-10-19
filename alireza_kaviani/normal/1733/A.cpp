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
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n , k , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> k;
        ll ans = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> A[i];
        }
        for(int i = 0 ; i < k ; i++){
            ll mx = 0;
            for(int j = i ; j < n ; j += k){
                mx = max(mx , A[j]);
            }
            ans += mx;
        }
        cout << ans << endl;
    }

    return 0;
}
/*

*/