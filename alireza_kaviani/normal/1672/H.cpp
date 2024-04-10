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

int q , n , ps[2][MAXN];
string s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> q >> s;
    for(int i = 1 ; i < n ; i++){
        ps[0][i] = ps[0][i - 1];
        ps[1][i] = ps[1][i - 1];
        if(s[i] == s[i - 1]){
            ps[s[i] - 48][i]++;
        }
    }
    
    while(q--){
        int l , r;
        cin >> l >> r;
        l--; r--;
        cout << max(ps[0][r] - ps[0][l] , ps[1][r] - ps[1][l]) + 1 << endl;
    }

    return 0;
}
/*

*/