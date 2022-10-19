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

int q , n , x , A[MAXN] , L[MAXN] , R[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> x;
        for(int i = 0 ; i < n ; i++){
            cin >> A[i];
            L[i] = A[i] - x;
            R[i] = A[i] + x;
        }
        int l = -MOD * 2 , r = MOD * 2 , ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(R[i] < l || r < L[i]){
                ans++;
                l = -MOD * 2;
                r = MOD * 2;
            }
            l = max(l , L[i]);
            r = min(r , R[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
/*

*/