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

ll q , n , k , A[MAXN] , ps[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> k;
        ll len = min(k , n) , ans = 0 , val = k * (k - 1) / 2 - (k - len) * (k - len - 1) / 2;
        for(int i = 1 ; i <= n ; i++){
            cin >> A[i];
            ps[i] = ps[i - 1] + A[i];
        }
        for(int i = len ; i <= n ; i++){
            ans = max(ans , ps[i] - ps[i - len]);
        }
        cout << ans + val << endl;
    }

    return 0;
}
/*

*/