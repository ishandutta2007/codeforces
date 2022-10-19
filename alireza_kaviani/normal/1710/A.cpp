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

ll q , n , m , k , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> m >> k;
        ll x = 0 , y = 0 , fx = 0 , fy = 0;
        for(int i = 0 ; i < k ; i++){
            cin >> A[i];
            if(A[i] >= 2 * n){
                x += A[i] / n;
                if(A[i] >= 3 * n)   fx = 1;
            }
            if(A[i] >= 2 * m){
                y += A[i] / m;
                if(A[i] >= 3 * m)   fy = 1;
            }
        }
        if(m % 2 == 0)  fx = 1;
        if(n % 2 == 0)  fy = 1;
        if((fx && x >= m) || (fy && y >= n)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    return 0;
}
/*

*/