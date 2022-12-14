#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector <ll> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)cin >> b[i];
    ll ans = 0, k, sc;

    k = 0;sc = 0;
    for(int i = 1; i <= n; i++, k++)sc += a[i] * k;
    k = n;
    for(int i = n; i > 0; i--, k++)sc += b[i] * k;
    ans = max(ans, sc);

    k = 1;sc = 0;
    for(int i = 1; i <= n; i++, k++)sc += b[i] * k;
    k = n;
    for(int i = n; i > 1; i--, k++)sc += a[i] * k;
    ans = max(ans, sc);

    vector <ll> su;
    su.p_b(0);
    vector <ll> pref(n * 2 + 1);

    for(int i = 1; i <= n; i++)su.p_b(a[i]);
    for(int i = n; i > 0; i--)su.p_b(b[i]);
    for(int i = 1; i <= 2 * n; i++)pref[i] = pref[i - 1] + su[i];
    ll x = 1, y = 1;
    ll s = 0;
    sc = 0;
    ll l = 1, r = 2 * n;
    bool fl1 = 1;
    bool fl = 0;
    for(int i = 1; i < 2 * n; i++)s += i * su[i + 1];
    for(int i = 0; i < 2 * n; i++){
//        cout << endl;
//        cout << s << " " << sc << endl;
//        cout << y << " " << x << endl;
//        cout << endl;
        if(y == 1 || fl1){
            sc += a[x] * i;
            s -= a[x] * i;
            l++;
            if(fl1)y++; else x++;
            fl1 = 1 - fl1;
            if(fl1)ans = max(ans, s + sc);
        }else{
            sc += b[x] * i;
            s -= b[x] * (2 * n - 1);
            r--;
            if(l <= r)s += pref[r] - pref[l - 1];
            if(fl)y--; else
            x++;
            fl = 1 - fl;
        }
    }
    ans = max(ans, sc);

    su.clear();
    su.p_b(0);
    for(int i = 1; i <= n; i++)su.p_b(b[i]);
    for(int i = n; i > 0; i--)su.p_b(a[i]);
    for(int i = 1; i <= 2 * n; i++)pref[i] = pref[i - 1] + su[i];
    x = 1, y = 1;
    s = 0;
    sc = 0;
    l = 1, r = 2 * n;
    fl = 0;
    fl1 = 1;
    //cout << s << endl;
    for(int i = 1; i < 2 * n; i++)s += i * su[i + 1];
    for(int i = 0; i < 2 * n; i++){
        //cout << s << endl;
        if(y == 1 || fl1){
            sc += a[x] * i;
            s -= a[x] * (2 * n - 1);
            if(fl1)y++; else x++;
            fl1 = 1 - fl1;
            r--;
            if(l <= r)s += pref[r] - pref[l - 1];
        }else{
            sc += b[x] * i;
            s -= b[x] * i;
            l++;
            if(fl)y--; else
            x++;
            fl = 1 - fl;
            if(fl)ans = max(ans, sc + s);
        }
    }
    ans = max(ans, sc);
    cout << ans << endl;
    return 0;
}
/*
3
1 10 2
1 1 1

4
1 1 1 1
1 2 10 1

*/