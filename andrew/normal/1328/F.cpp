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

    int n, k;
    cin >> n >> k;

    vector <int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    map <ll, ll> mp;

    for(int i : a)mp[i]++;

    sort(all(a));

    for(auto i : mp)if(i.se >= k)vout(0);

    ll ans = 0, cnt = 0, sum = 0;

    for(int i = 0; i < n; i++){
        ans += abs(a[i] - a[n / 2]);
    }

    vector <pll> v;

    ll sump, sums, cntp, cnts;
    sump = sums = 0;
    cntp = cnts = 0;
    cnts = n;

    for(int i = 0; i < n; i++){
        sums += a[i];
    }

    for(auto i : mp){
        cnts -= i.se;
        sums -= i.fi * i.se;
        ll temp_ans = 0;
        temp_ans += (i.fi - 1) * cntp;
        temp_ans -= (i.fi + 1) * cnts;
        temp_ans -= sump;
        temp_ans += sums;
        cntp += i.se;
        sump += i.fi * i.se;
        temp_ans += k - i.se;
        ans = min(ans, temp_ans);
    }

    for(auto i : mp){
        if(cnt + i.se >= k){
            ll temp_ans = 0;
            temp_ans += (i.fi - 1) * cnt;
            temp_ans -= sum;
            temp_ans += k - i.se;
            ans = min(ans, temp_ans);
        }
        cnt += i.se;
        sum += i.fi * i.se;
        v.p_b(i);
    }

    cnt = sum = 0;

    reverse(all(v));

     for(auto i : v){
        if(cnt + i.se >= k){
            ll temp_ans = 0;
            temp_ans += sum;
            temp_ans -= (i.fi + 1) * cnt;
            temp_ans += k - i.se;
            ans = min(ans, temp_ans);
        }
        cnt += i.se;
        sum += i.fi * i.se;
    }

    cout << ans << "\n";

    return 0;
}