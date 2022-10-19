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

int q , n , x , y;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> x >> y;
        if(x < y)   swap(x , y);
        if(y != 0 || x == 0 || (n - 1) % x != 0){
            cout << -1 << endl;
            continue;
        }
        for(int i = 0 ; i < (n - 1) / x ; i++){
            for(int j = 0 ; j < x ; j++){
                cout << i * x + 2 << sep;
            }
        }
        cout << endl;
    }

    return 0;
}
/*

*/