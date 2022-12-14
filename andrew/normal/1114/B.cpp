#include <bits/stdc++.h>

#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define m_p make_pair
#define p_b push_back
#define sqr(x) (x) * (x)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
const ll N = 2e5;
const ll MAXN = 1123456;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n, m, k;
    cin >> n >> m >> k;

    vector <pll> a(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());

    vector <ll> c;

    ll ans = 0;

    for(int i = 1; i <= m * k; i++){
        ans += a[i].fi;
        c.p_b(a[i].se);
    }

    sort(all(c));
    ll last = 1;

    vector <ll> p;

    for(int i = 0; i < m * k; i++){
        if((i + 1) % m == 0){
            p.p_b(c[i]);
            last = c[i] + 1;
        }
    }

    p.pop_back();

    cout << ans << "\n";

    for(auto i : p)cout << i << " ";
    cout << "\n";

    return 0;
}