#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T> void vout(T s){
    cout << s << endl;
    exit(0);
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    ll kol = 0;

    vector <ll> pref(n + 2);

    ll ans = 0;

    for(int i = 1; i <= n; i++){
        char a;
        cin >> a;
        pref[i] = pref[i - 1];
        if(a == 'G')pref[i]++;
    }

    pref[n + 1] = pref[n];
    kol = pref[n];

    if(!kol)vout(0);

    for(int i = 1; i <= n; i++){
        ll l = i, r = n;

        while(l < r){
            ll c = (l + r) >> 1;
            if(c == l)c++;

            ll kolb = c - i + 1 - (pref[c] - pref[i - 1]);
            if(kolb > 1)r = c - 1; else{
                if(!kolb)l = c; else{
                    if(kol != pref[c] - pref[i - 1])l = c; else r = c - 1;
                }
            }
        }

        ans = max(ans, l - i + 1);
    }
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}