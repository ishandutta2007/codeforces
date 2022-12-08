#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll,ll>
#define MOD 1000000007LL

using namespace std;

ll pw(ll b, ll e) {
    if(e==0) { return 1LL; }
    if(e&1) { return (b*pw((b*b)%MOD,e/2))%MOD;}
    return pw((b*b)%MOD,e/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll n, P;
        cin >> n >> P;
        vector<ll> ps(n);
        for(ll &p : ps) {
            cin >> p;
        }
        if(P == 1) {
            cout << (n&1) << "\n";
            continue;
        }
        sort(ps.begin(), ps.end());
        // ll dif = 0;
        // ll e = 0;
        // ll res = 0;
        // for(int i = 0; i < n; i ++) {
        //     if(dif == 0) {
        //         e = ps[i];
        //         dif = 1;
        //         continue;
        //     }
        //     if(e == ps[i]) {
        //         dif --;
        //         continue;
        //     }
        //     if((ps[i]-e)<=log(dif)/log(P)) {
        //         ll PW = pow(P,ps[i]-e);
        //         res += (((dif%PW)*pw(P,e))%MOD);
        //         res %= MOD;
        //         dif /= pow(P,ps[i]-e);
        //         dif --;
        //         e = ps[i];
        //     } else {
        //         cout << P << " ^" << e << " * " << dif << "\n";
        //         res += (dif*pw(P,e))%MOD;
        //         dif = 1;
        //         e = ps[i];
        //     }
        // }
        // res += (dif * pw(P,e)) % MOD;
        // res %= MOD;
        // cout << res << "\n";
        // continue;
        ll e = 0;
        ll dif = 0;
        ll res = 0;
        bool lol = false;
        for(int i = n - 1; i >= 0; i --) {
            if(lol) {
                res += MOD - pw(P,ps[i]);
                res %= MOD;
                continue;
            }
            if(dif == 0) {
                dif = 1;
                e = ps[i];
                continue;
            }
            if(e == ps[i]) {
                dif --;
                continue;
            }
            ll mx = floor(exp(log(1000001)-(e-ps[i])*log(P)));
            if(mx >= dif) {
                dif *= pow(P,e-ps[i]);
                dif --;
                e = ps[i];
            } else {
                res += dif*pw(P,e);
                res %= MOD;
                
                res += (MOD-pw(P,ps[i]));
                res %= MOD;
                dif = 0;
                e = 1;
                lol = true;
            }
        }
        res += (dif*pw(P,e))%MOD;
        res %= MOD;
        // cout << P << " " << e << " " << pw(P,e) << " * " << dif << "\n";
        cout << res << "\n";
        continue;
        // ll res = 0;
        // for(pi pr : cnt) {
        //     res += pw(P,pr.first) * pr.second;
        //     res %= MOD;
        // }
        // cout << res << "\n";
    }

    return 0;
}