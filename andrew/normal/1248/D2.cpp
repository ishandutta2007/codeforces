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


    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll sc = 0, mn = 1e18, pos = 0;

    vector <ll> pref(n + 1), a, b, pref1;

    for(int i = 0; i < n; i++){
        if(s[i] == '(')sc++;
        else sc--;
        a.p_b(i);
        if(sc < mn){
            mn = sc;
            pos = i;
        }
    }

    if(sc != 0)vout("0\n1 1\n");

    string c;

    for(int i = pos + 1; i < n; i++){
        c += s[i];
        b.p_b(a[i]);
    }
    for(int i = 0; i <= pos; i++){
        c += s[i];
        b.p_b(a[i]);
    }

    a = b; s = c; c.clear(); b.clear();

    sc = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '(')sc++;
        else sc--;
        pref[i] = sc;
    }

    ll ans = 0, x, y;
    x = y = 0;

    for(int i = 0; i < n; i++){
        if(!pref[i])ans++;
    }

    ll Kol, Kol_jeden, old = ans, Kol_dwa;
    Kol = Kol_jeden = 0;

    for(int i = 0; i < n; i++){

        if(s[i] == ')'){
            ll res = Kol_jeden;

            if(res > ans){
                ans = res;
                x = i - Kol;
                y = i;
            }
        }

        if(pref[i] > 0){
            Kol++;
            Kol_jeden += (pref[i] == 1);
        }else{
            Kol = Kol_jeden = 0;
        }
    }

    Kol = Kol_dwa = 0;

    for(int i = 0; i < n; i++){

        if(s[i] == ')'){
            ll res = Kol_dwa + old;

            if(res > ans){
                ans = res;
                x = i - Kol;
                y = i;
            }
        }

        if(pref[i] > 1){
            Kol++;
            Kol_dwa += (pref[i] == 2);
        }else{
            Kol = Kol_dwa = 0;
        }
    }


    cout << ans << "\n" << a[x] + 1 << " " << a[y] + 1 << "\n";

    return 0;
}