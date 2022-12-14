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
    string s;
    int n;
    cin >> n;
    cin >> s;
    int val;
    for(int i = 0; i < sz(s); i++){
        val = s[i] - '0';
        if(!is_prime[val]){
            cout << "1\n" << s[i] << "\n";
            return;
        }
    }
    for(int i = 0; i < sz(s); i++){
        val = s[i] - '0';
        for(int j = i + 1; j < sz(s); j++){
            if(!is_prime[val * 10 + (s[j] - '0')]){
                cout << "2\n" << s[i] << s[j] << "\n";
                return;
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i <= 100; i++){
        is_prime[i] = 1;
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                is_prime[i] = 0;
            }
        }
    }

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}