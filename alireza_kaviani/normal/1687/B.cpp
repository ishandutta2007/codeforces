#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
//#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , m , ans , prv = 0 , mark[MAXN];

int query(){
    cout << "? ";
    for(int i = 0 ; i < m ; i++){
        cout << mark[i];
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    vector<pii> vec;
    for(int i = 0 ; i < m ; i++){
        mark[i] = 1;
        int W = query();
        vec.push_back({W , i});
        mark[i] = 0;
    }
    sort(all(vec));
    for(pii i : vec){
        int w = i.X , ind = i.Y;
        mark[ind] = 1;
        int cur = query();
        if(cur == prv + w){
            ans += w;
        }
        prv = cur;
    }
    cout << "! " << ans << endl;

    return 0;
}
/*

*/