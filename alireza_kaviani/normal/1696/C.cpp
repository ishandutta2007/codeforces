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

ll q , n , m , k;

pll calc(ll x){
    ll y = 1;
    while(x % m == 0){
        x /= m;
        y *= m;
    }
    return {x , y};
}

vector<pll> getInput(int n){
    vector<pll> res;
    for(int i = 0 ; i < n ; i++){
        ll x;
        cin >> x;
        pll A = calc(x);
        if(SZ(res) == 0 || res.back().X != A.X){
            res.push_back(A);
        }
        else{
            res[SZ(res) - 1].Y += A.Y;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> m;
        vector<pll> A = getInput(n);
        cin >> k;
        vector<pll> B = getInput(k);
        if(A == B){
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