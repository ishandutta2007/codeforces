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

int q , n , k , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> k;
        for(int i = 0 ; i < n ; i++){
            cin >> A[i];
        }
        if(k == 1){
            cout << (n - 1) / 2 << endl;
            continue;
        }
        int res = 0;
        for(int i = 1 ; i + 1 < n ; i++){
            if(A[i] > A[i - 1] + A[i + 1]){
                res++;
            }
        }
        cout << res << endl;
    }

    return 0;
}
/*

*/