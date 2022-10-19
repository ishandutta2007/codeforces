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

ll q , n , k , S[MAXN] , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> k;
        fill(S , S + n + 5 , 0);
        fill(A , A + n + 5 , 0);
        for(int i = n - k + 1 ; i <= n ; i++){
            cin >> S[i];
        }
        for(int i = n - k + 2 ; i <= n ; i++){
            A[i] = S[i] - S[i - 1];
        }
        ll x = S[n - k + 1] , y = n - k + 1;
        A[n - k + 1] = (x / y) + (x % y > 0);
        int flag = 0;
        for(int i = n - k + 2 ; i <= n ; i++){
            if(A[i - 1] > A[i]){
                flag = 1;
            }
        }
        cout << (flag ? "No" : "Yes") << endl;
    }

    return 0;
}
/*

*/