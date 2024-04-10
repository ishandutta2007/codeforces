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
#define fout(x) {cout << x; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e7 + 5;
const int MAXN = 3e6;
const int M = 1e7;
const ll inf = 1e18;
const int mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

bool is_prime[N];

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pos = -1;
    for(int i = n / 2; i < n; i++){
        if(s[i] == '0'){
            pos = i;
            break;
        }
    }
    if(pos != -1){
        cout << 1 << " " << pos + 1 << " " << 1 << " " << pos << "\n";
        return;
    }
    for(int i = 0; i < n / 2; i++){
        if(s[i] == '0'){
            cout << i + 1 << " " << n << " " << i + 2 << " " << n << "\n";
            return;
        }
    }
    cout << 1 << " " << n / 2 << " " << 2 << " " << n / 2 + 1 << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}