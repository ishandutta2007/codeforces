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
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll inf = 1e8;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    ll n, m;
    cin >> n >> m;
    vector <ll> a(m);
    map <ll, ll> mp;
    for(int i = 0; i < m; i++){
        cin >> a[i];
        mp[a[i]]++;
    }

    ll ost = 0, ans = 0;

    for(int i = 0; i <= 60; i++){
        ost /= 2;
        ost += mp[pw(i)];
        if(n & pw(i)){
            if(ost){
                ost--;
            }else{
                ll ct = 0;
                for(int j = i + 1; j < 60; j++){
                    if(mp[pw(j)]){
                        mp[pw(j)]--;
                        ct = 1;
                        for(int l = j - 1; l >= i; l--){
                            mp[pw(l)]++;
                            ans++;
                        }
                        break;
                    }
                }
                if(!ct)fout(-1);
            }
        }
    }
    cout << ans << "\n";
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--){
        solve();
    }


    return 0;
}