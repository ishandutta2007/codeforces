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

ll q , n , x , y , A[MAXN];
string s , t;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> x >> y >> s >> t;
        vector<int> vec;
        for(int i = 0 ; i < n ; i++){
            A[i] = (s[i] == t[i] ? 0 : 1);
            if(A[i]){
                vec.push_back(i);
            }
        }
        x = min(x , y * 2);
        if(SZ(vec) % 2 == 1){
            cout << -1 << endl;
            continue;
        }
        if(SZ(vec) != 2 || vec[0] + 1 != vec[1]){
            cout << SZ(vec) / 2 * y << endl;
        }
        else{
            cout << x << endl;
        }
    }

    return 0;
}
/*

*/