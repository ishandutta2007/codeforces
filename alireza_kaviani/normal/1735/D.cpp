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

const ll MAXN = 1010;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , k , ans , A[MAXN][LOG];
map<ll, ll> cnt;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        ll val = 0;
        for(int j = 0 ; j < k ; j++){
            cin >> A[i][j];
            val = val * 3 + A[i][j];
        }
        cnt[val]++;
    }

    for(int i = 0 ; i < n ; i++){
        ll sum = 0;
        for(int j = 0 ; j < n ; j++){
            if(i == j)  continue;
            ll val = 0 , flag = 1;
            for(int l = 0 ; l < k ; l++){
                val = val * 3 + (6 - A[i][l] - A[j][l]) % 3;
                flag &= (A[i][l] == A[j][l]);
            }
            sum += cnt[val] - flag * 2;
        }
        sum /= 2;
        ans += sum * (sum - 1) / 2;
    }
    cout << ans << endl;

    return 0;
}
/*

*/