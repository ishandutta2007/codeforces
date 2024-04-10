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

ll q , n , m , A[MAXN] , val[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> m;
        ll mn = INF , mx = -INF;
        for(int i = 0 ; i < n ; i++){
            val[i] = 0;
            for(int j = 0 ; j < m ; j++){
                cin >> A[j];
                val[i] += A[j] * j;
            }
            mn = min(mn , val[i]);
            mx = max(mx , val[i]);
        }
        for(int i = 0 ; i < n ; i++){
            if(val[i] == mx){
                cout << i + 1 << sep << mx - mn << endl;
            }
        }
    }

    return 0;
}
/*

*/