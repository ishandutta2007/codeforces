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

int q , n , m;
string s , t;

int Main(){
    cin >> n >> m >> s >> t;
    while(m > 1){
        if(t[m - 1] != s[n - 1]){
            return cout << "NO" << endl , 0;
        }
        m--; n--;
    }
    for(int i = 0 ; i < n ; i++){
        if(t[0] == s[i]){
            return cout << "YES" << endl , 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        Main();
    }

    return 0;
}
/*

*/