#include <bits/stdc++.h>

//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

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

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1123456;
const int N = 1e5 + 3;
const int M = pw(10);
const int inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    while(q--){
        int n = 0, sc = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            sc += x;
        }
        cout << sc / n + (sc % n > 0) << "\n";
    }

    return 0;
}