#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1010;
const int M = 1e7;
const ll inf = 1e18;
const int mod = 998244353;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

using namespace std;

char a[101][101];

void solve(){
    ll h, w;

    cin >> h >> w;

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            a[i][j] = '0';
        }
    }

    if(h % 2 == w % 2 && w % 2 == 1){
        for(int i = 1; i <= w; i += 2){
            a[h][i] = a[1][i] = '1';
        }
        for(int i = 1; i <= h; i += 2){
            a[i][1] = a[i][w] = '1';
        }
    }

    if(h % 2 == 0 && w % 2 == 0){
        for(int i = 1; i <= w; i += 2){
            a[h][i] = a[1][i] = '1';
        }
        for(int i = 3; i + 1 < h; i += 2){
            a[i][1] = a[i][w] = '1';
        }
    }

    if(h % 2 == 1 && w % 2 == 0){
        for(int i = 3; i + 1 < w; i += 2){
            a[h][i] = a[1][i] = '1';
        }
        for(int i = 1; i <= h; i += 2){
            a[i][1] = a[i][w] = '1';
        }
    }

    if(h % 2 == 0 && w % 2 == 1){
        for(int i = 1; i <= w; i += 2){
            a[h][i] = a[1][i] = '1';
        }
        for(int i = 3; i + 1 < h; i += 2){
            a[i][1] = a[i][w] = '1';
        }
    }

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    //t = 1;

    while(t--){
        solve();
    }

    return 0;
}