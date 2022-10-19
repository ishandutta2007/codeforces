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

int q , n , P[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        vector<pii> vec;
        for(int i = 1 ; i <= n ; i++){
            cin >> P[i];
        }
        for(int i = 2 ; i <= n ; i++){
            if(P[i - 1] > P[i]){
                vec.push_back({P[i] - P[i - 1] , i});
            }
        }
        sort(all(vec));
        while(SZ(vec) < n){
            vec.push_back({0 , 1});
        }
        reverse(all(vec));
        for(pii i : vec){
            cout << i.Y << sep;
        }
        cout << endl;
    }

    return 0;
}
/*

*/