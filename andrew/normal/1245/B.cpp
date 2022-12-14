#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll q;

    cin >> q;

    while(q--){
        ll n;
        cin >> n;
        ll a, b, c;
        cin >> a >> b >> c;
        ll k = 0;
        string s, ans;
        cin >> s;
        for(int i = 0; i < n; i++)ans += '0';

        for(int i = 0; i < n; i++)if(s[i] == 'R' && b){
            s[i] = 'X';
            b--;
            k++;
            ans[i] = 'P';
        }

        for(int i = 0; i < n; i++)if(s[i] == 'P' && c){
            s[i] = 'X';
            c--;
            k++;
            ans[i] = 'S';
        }

        for(int i = 0; i < n; i++)if(s[i] == 'S' && a){
            s[i] = 'X';
            a--;
            k++;
            ans[i] = 'R';
        }

        for(int i = 0; i < n; i++)if(ans[i] == '0'){
            if(a)ans[i] = 'R', a--;
            else if(b)ans[i] = 'P', b--;
            else ans[i] = 'S', c--;
        }

        if(k >= (n + 1) / 2)cout << "YES\n" << ans << "\n";
        else cout << "NO\n";

    }

    return 0;
}