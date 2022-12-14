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
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2e5;
const int MAXN = 1123456;
const ll inf = 3e18;
const ll mod = 1000000007;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    ll n, l, r;
    cin >> n >> l >> r;
    ll pos = l;
    if(l % 2 == 0){
        pos = l - 1;
    }
    ll sc = 0;
    pos >>= 1;
    pos++;
    ll first_block = 0;
    for(int i = 1; i <= n; i++){
        sc = n - i;
        if(pos <= sc){
            first_block = i;
            break;
        }else pos -= sc;
    }
    vector <ll> ans;
    if(first_block == 0){
        ans.p_b(1);
    }else if(l % 2 == 1)ans.p_b(first_block);
    ans.p_b(first_block + pos);
    ll fufel;
    fufel = ans.back() + 1;
    ll uk = l;
    if(l % 2 == 0)uk--;
    uk += 2;
    while(uk <= r){
        if(ans.back() == first_block){
            ans.p_b(fufel);
            fufel++;
        }else{
            if(ans.back() == n){
                first_block++;
                if(first_block == n)ans.p_b(1);
                else ans.p_b(first_block);
                fufel = first_block + 1;
            }else{
                ans.p_b(first_block);
            }
        }
        uk++;
    }
    if(l == r && l % 2 == 1)ans.pop_back();
    for(auto i : ans)cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}