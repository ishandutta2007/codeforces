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
#define fout(x) { cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 3123456;
const ll inf = 3e9;
const ll mod = 998244353;
const ll N = 1e6;
const ll mod1 = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

struct node{
    ll val, mn_sum;
};

node t[MAXN];

node merge(node a, node b){
    node res;
    res.val = a.val + b.val;
    res.mn_sum = a.mn_sum;
    res.mn_sum = min(res.mn_sum, a.val + b.mn_sum);
    return res;
}

void modify(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl == tr){
        t[v].val += val;
        t[v].mn_sum = t[v].val;
    }else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos, val);
        else modify(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }
}

void main_solve(){
    ll n;
    cin >> n;
    vector <ll> a(n + 1), b(n + 1), wh(n + 1), u(n + 2), suf(n + 2);
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        wh[a[i]] = i;
    }
    int ans = n;
    set <ll> st;
    cout << n;
    for(int i = 1; i < n; i++){
        st.insert(b[i]);
        while(!st.empty()){
            ll x = *--st.end();
            st.erase(--st.end());
            modify(1, 1, n, x, -1);
            modify(1, 1, n, wh[ans], +1);
            if(t[1].mn_sum >= 0){
                ans--;
                continue;
            }
            modify(1, 1, n, x, 1);
            modify(1, 1, n, wh[ans], -1);
            st.insert(x);
            break;
        }
        cout << " " << ans;
    }
    cout << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> t;
    #endif // LOCAL

    for(int id = 1; id <= t; id++){
        #ifdef LOCAL
            cout << "Test number " << id << ":\n";
        #endif // LOCAL
        main_solve();
    }


    return 0;
}