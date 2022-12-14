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
#define fout(x) {cout << x << "\n"; return;}
#define ifn(x) if(!(x))

using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 2e6;
const ll MAXN = 1123456;
const ll inf = 1e18;
const ll M = 59051;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

bool fl[MAXN], mrk[N + 100];
ll val[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n;
    cin >> n;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    sort(a.begin() + 1, a.end());

    ll l = a[1] - n, r = a[1] + n;
    if(l < 2)l = 2;

    for(int i = 2; i < N; i++)
        if (!mrk[i]){

            if (ll(i) * ll(i) > ll(N)) continue;

            for (int j = i * i; j <= N; j += i)
                mrk[j] = 1;
        }

    vector <ll> st;

    for(ll i = l; i <= r; i++){
        val[i - l] = i;
    }

    for(ll i = 2; i * i <= r; i++)if(!mrk[i]){
        ll x = i * (l / i + (l % i > 0));
        if(l <= x && x <= r){
            st.p_b(i);
            for(; x <= r; x += i){
                while(val[x - l] % i == 0)val[x - l] /= i;
            }
        }
    }

    for(ll i = l; i <= r; i++)if(val[i - l] != 1)st.p_b(val[i - l]);


    ll ans = 0;

    for(int i = 1; i <= n; i++)if(a[i] % 2)ans++;

    shuffle(all(st), rnd);

    ll val, ost;

    for(auto i : st){
        ll sc = 0;
        for(int j = 1; j <= n; j++){
            ost = a[j] % i;
            val = i - ost;
            if(a[j] >= i)val = min(val, ost);
            sc += val;
            if(sc > ans)break;
        }
        ans = min(ans, sc);
    }
    cout << ans << "\n";




    return 0;

}