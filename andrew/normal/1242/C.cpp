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

bool f[MAXN];
ll pr[MAXN], wt[MAXN];

int main() {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll k;
    cin >> k;
    vector <vector<ll>> arr(k);
    vector <ll> n(k), S(k);

    map <ll, ll> mp;

    ll sum = 0;

    for(int i = 0; i < k; i++){
        cin >> n[i];
        arr[i].resize(n[i]);
        for(int j = 0; j < n[i]; j++){
            cin >> arr[i][j];
            mp[arr[i][j]] = i;
            S[i] += arr[i][j];
        }
        sum += S[i];
    }

    if(sum % k)vout("No");

    ll Val = sum / k, nw;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n[i]; j++){
            ll x = arr[i][j], musk = 0, P = i;
            bool ok = 1;
            while(1){
                musk |= pw(P);
                nw = (Val - (S[P] - x));
                if(mp.find(nw) == mp.end()){
                    ok = 0;
                    break;
                }
                x = nw;
                P = mp[nw];
                if(x == arr[i][j])break;
                if((musk & pw(P))){
                    ok = 0;
                    break;
                }
            }
            if(ok && !f[musk]){
                f[musk] = 1;
                wt[musk] = arr[i][j];
                pr[musk] = musk;
            }
        }
    }

    f[0] = 1;

    for(int i = 1; i < pw(k); i++)if(!f[i]){
        for (int s = i; ;s = (s - 1) & i) {
            if(f[s] && f[s ^ i]){
                f[i] = 1;
                pr[i] = s ^ i;
                break;
            }
            if (s == 0)  break;
        }
    }

    if(!f[pw(k) - 1])vout("No");

    cout << "Yes\n";

    vector <pll> ans(k);

    ll X = pw(k) - 1;
    while(X){
        ll fufel = pr[X];
        X ^= fufel;
        ll x = wt[fufel], start = wt[fufel], musk = 0, P = mp[x];
        while(1){
            musk |= pw(P);
            nw = (Val - (S[P] - x));
            ans[mp[nw]] = {nw, P + 1};
            x = nw;
            P = mp[nw];
            if(x == start)break;
        }
    }

    for(int i = 0; i < k; i++){
        cout << ans[i].fi << " " << ans[i].se << "\n";
    }

    return 0;
}