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

const ll MAXN = 3e5 + 10;
const ll LOG = 60;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n , A[MAXN] , B[MAXN] , fen[LOG][MAXN];
map<ll, ll> val;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll getVal(ll x){
    if(val[x] != 0){
        return val[x];
    }
    val[x] = rng();
    return val[x];
}

void fen_add(int ind , int x , int val){
    for( ; x < MAXN ; x += x & -x)  fen[ind][x] += val;
}

void add(int pos , ll x , int val){
    for(int i = 0 ; i < LOG ; i++){
        if(x & (1ll << i)){
            fen_add(i , pos , val);
        }
    }
}

int get(int ind , int x){
    int ans = 0;
    for( ; x ; x -= x & -x) ans += fen[ind][x];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++){
        cin >> A[i];
        B[i] = getVal(A[i]);
        add(i , B[i] , 1);
    }

    while(q--){
        int t , x , y , k;
        cin >> t >> x >> y;
        if(t == 1){
            add(x , B[x] , -1);
            A[x] = y;
            B[x] = getVal(A[x]);
            add(x , B[x] , 1);
        }
        if(t == 2){
            cin >> k;
            int flag = 0; x--;
            for(int i = 0 ; i < LOG ; i++){
                if((get(i , y) - get(i , x)) % k != 0){
                    flag = 1;
                }
            }
            cout << (flag ? "NO" : "YES") << endl;
        }
    }

    return 0;
}
/*

*/