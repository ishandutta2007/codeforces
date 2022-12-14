#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5;
const int M = pw(16);
const long long mod = 998244353;
const int N = 1e6 + 200;
//const int N = 100;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve(){
    int n;
    cin >> n;
    int a, b, c;
    a = b = c = 0;
    if(n % 2 == 1){
        if((n / 2) % 2 == 0){
            c = 1;
            a = n / 2 - 1;
            b = n / 2 + 1;
        }else{
            c = 1;
            n--;
            a = n / 2 - 2;
            b = n / 2 + 2;
        }     
    }else{
        int x = (n - 2) / 2;
        c = 2;
        if(x % 2){
            a = x - 1;
            b = x + 1;
        }else{
            c = 1;
            a = (n - 1) / 2;
            b = a + 1;
        }
    }
    cout << a << ' ' << b << " " << c << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    

    return 0;
}