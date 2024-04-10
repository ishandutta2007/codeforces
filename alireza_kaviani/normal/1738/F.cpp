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

int n , q , D[MAXN] , col[MAXN];

int query(int v){
    cout << "? " << v << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        vector<pii> vec;
        fill(col , col + n + 5 , 0);
        for(int i = 1 ; i <= n ; i++){
            cin >> D[i];
            vec.push_back({D[i] , i});
        }
        sort(all(vec) , greater<pii>());
        int cnt = 0;
        for(pii i : vec){
            int v = i.Y , C = -1;
            if(col[v])  continue;
            vector<int> A = {v};
            while(1){
                int u = query(v);
                if(u == -1){
                    break;
                }
                if(col[u] != 0){
                    C = col[u];
                    break;
                }
                A.push_back(u);
            }
            if(C == -1){
                C = ++cnt;
            }
            for(int i : A){
                col[i] = C;
            }
        }
        cout << "! ";
        for(int i = 1 ; i <= n ; i++){
            cout << col[i] << sep;
        }
        cout << endl;
    }

    return 0;
}
/*

*/